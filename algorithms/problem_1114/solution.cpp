/*
Probleim 1114. Print in Order
Difficulty: Easy

Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
The same instance of Foo will be passed to three different threads. Thread A will call first(),
thread B will call second(), and thread C will call three(). Design a mechanism and modify the
program to ensure that second() is executed after first(), and third() is executed after second().

 
Example 1:

Input: [1,2,3]
Output: "firstsecondthird"
Explanation: There are three threads being fired asynchronously. The input [1,2,3] means
thread A calls first(), thread B calls second(), and thread C calls third().
"firstsecondthird" is the correct output.

Example 2:
Input: [1,3,2]
Output: "firstsecondthird"
Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(),
and thread C calls second(). "firstsecondthird" is the correct output.

Note:
We do not know how the threads will be scheduled in the operating system, even though
the numbers in the input seems to imply the ordering. The input format you see is mainly
to ensure our tests' comprehensiveness.
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
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

class Foo {
public:
    Foo() {

    }

    void first(function<void()> printFirst) {
        printFirst();
        fired[0] = true;
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<mutex> lk(lock);
        cv1.wait(lk, [this]{return fired[0];});
        printSecond();
        fired[1] = true;
        cv2.notify_one();
    }

    void third(function<void()> printThird) {
        std::unique_lock<mutex> lk(lock);
        cv2.wait(lk, [this]{return fired[1];});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

    array<bool, 2> fired{{false, false}};
    std::mutex lock;
    std::condition_variable cv1;
    std::condition_variable cv2;
};

int main() {
    Foo foo;

    auto print_first = [] { std::cout << "First" << endl;};
    auto print_second = [] { std::cout << "Second" << endl;};
    auto print_third = [] { std::cout << "Third" << endl;};
    auto t1 = thread([&] {foo.first(print_first);});
    auto t2 = thread([&] {foo.second(print_second);});
    auto t3 = thread([&] {foo.third(print_third);});

    t1.join(); t2.join(); t3.join();

    return 0;
}

