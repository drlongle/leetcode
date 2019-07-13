/*
1116. Print Zero Even Odd
Difficulty: Medium

Suppose you are given the following code:

class ZeroEvenOdd {
  public ZeroEvenOdd(int n) { ... }      // constructor
  public void zero(printNumber) { ... }  // only output 0's
  public void even(printNumber) { ... }  // only output even numbers
  public void odd(printNumber) { ... }   // only output odd numbers
}
The same instance of ZeroEvenOdd will be passed to three different threads:

Thread A will call zero() which should only output 0's.
Thread B will call even() which should only ouput even numbers.
Thread C will call odd() which should only output odd numbers.
Each of the thread is given a printNumber method to output an integer. Modify the given
program to output the series 010203040506... where the length of the series must be 2n.

Example 1:
Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously. One of them calls zero(),
the other calls even(), and the last one calls odd(). "0102" is the correct output.

Example 2:
Input: n = 5
Output: "0102030405"
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <condition_variable>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class ZeroEvenOdd {
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        count = 0;
        num = 1;
    }

    void zero(function<void(int)> printNumber) {
        while (count < 2*n) {
            unique_lock<mutex> lk(lock);
            cv.wait(lk, [this]{return count % 2 == 0;});
            if (num <= n)
                printNumber(0);
            ++count;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (count < 2*n) {
            unique_lock<mutex> lk(lock);
            cv.wait(lk, [this]{return count % 4 == 3;});
            if (num <= n)
                printNumber(num++);
            ++count;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (count < 2*n) {
            unique_lock<mutex> lk(lock);
            cv.wait(lk, [this]{return count % 4 == 1;});
            if (num <= n)
                printNumber(num++);
            ++count;
            cv.notify_all();
        }
    }

    std::mutex lock;
    std::condition_variable cv;
    int n, num, count;
};

int main() {
    ZeroEvenOdd zero_even_odd(40);

    auto print_number = [] (int n) { std::cout << n << endl;};

    auto t1 = thread([&] {zero_even_odd.zero(print_number);});
    auto t2 = thread([&] {zero_even_odd.even(print_number);});
    auto t3 = thread([&] {zero_even_odd.odd(print_number);});
    t1.join(); t2.join(); t3.join();

    return 0;
}

