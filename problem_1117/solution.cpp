/*
1117. Building H2O
Difficulty: Hard

There are two kinds of threads, oxygen and hydrogen. Your goal is to group these threads to form
water molecules. There is a barrier where each thread has to wait until a complete molecule
can be formed. Hydrogen and oxygen threads will be given a releaseHydrogen and releaseOxygen
method respectfully, which will allow them to pass the barrier. These threads should pass
the barrier in groups of three, and they must be able to immediately bond with each other
to form a water molecule. You must guarantee that all the threads from one molecule bond
before any other threads from the next molecule do.

In other words:
If an oxygen thread arrives at the barrier when no hydrogen threads are present, it has
to wait for two hydrogen threads. If a hydrogen thread arrives at the barrier when no
other threads are present, it has to wait for an oxygen thread and another hydrogen thread.
Write synchronization code for oxygen and hydrogen molecules that enforces these constraints.

Example 1:
Input: "HOH"
Output: "HHO"
Explanation: "HOH" and "OHH" are also valid answers.

Example 2:
Input: "OOHHHH"
Output: "HHOHHO"
Explanation: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" and "OHHOHH" are also valid answers.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <condition_variable>
#include <cmath>
#include <functional>
#include <future>
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

class H2O {
public:
    void reset() {
        hydro = oxy = 0;
    }

    H2O() {
        reset();
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lk(lock);
        cv.wait(lk, [this]{return hydro < 2;});

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        ++hydro;
        if (oxy == 1 && hydro == 2)
            reset();
        cv.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lk(lock);
        cv.wait(lk, [this]{return oxy == 0;});

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

        ++oxy;
        if (oxy == 1 && hydro == 2)
            reset();
        cv.notify_one();
    }

    int hydro, oxy;
    std::mutex lock;
    std::condition_variable cv;
};

int main() {
    H2O h2o;
    auto hydro_func = [] {std::cout << "H";};
    auto oxy_func = [] {std::cout << "0";};
    vector<thread> threads;

    for (int i = 0; i < 1000; ++i) {
        threads.emplace_back(thread([&]{h2o.hydrogen(hydro_func);}));
        threads.emplace_back(thread([&]{h2o.hydrogen(hydro_func);}));
        threads.emplace_back(thread([&]{h2o.oxygen(oxy_func);}));
    }

    for (auto& t: threads)
        t.join();

    return 0;
}

