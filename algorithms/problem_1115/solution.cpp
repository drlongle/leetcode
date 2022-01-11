/*
1115. Print FooBar Alternately
Difficulty: Medium

Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads. Thread A will call foo() while thread B will call bar(). Modify the given program to output "foobar" n times.

 

Example 1:

Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar(). "foobar" is being output 1 time.
Example 2:

Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.
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

class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
        fired = 0;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                std::unique_lock<mutex> lk(lock );
                cv.wait(lk, [this]{return (fired & 1) == 0;});
            }
            printFoo();
            ++fired;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<mutex> lk(lock );
            cv.wait(lk, [this]{return fired & 1;});
            printBar();
            ++fired;
            cv.notify_one();
        }
    }

    int fired;
    std::mutex lock;
    std::condition_variable cv;
};

int main() {
    FooBar foobar(100);

    auto print_foo = [] { std::cout << "Foo" << endl;};
    auto print_bar = [] { std::cout << "Bar" << endl;};
    auto t1 = thread([&] {foobar.foo(print_foo);});
    auto t2 = thread([&] {foobar.bar(print_bar);});
    t1.join(); t2.join();

    return 0;
}

