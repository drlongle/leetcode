/*
1157. Online Majority Element In Subarray
Hard

Implementing the class MajorityChecker, which has the following API:

  MajorityChecker(int[] arr) constructs an instance of MajorityChecker with the
given array arr; int query(int left, int right, int threshold) has arguments
such that: 0 <= left <= right < arr.length representing a subarray of arr; 2 *
threshold > right - left + 1, ie. the threshold is always a strict majority of
the length of the subarray

Each query(...) returns the element in arr[left], arr[left+1], ..., arr[right]
that occurs at least threshold times, or -1 if no such element exists.

Example:
MajorityChecker majorityChecker = new MajorityChecker([1,1,2,2,1,1]);
majorityChecker.query(0,5,4); // returns 1
majorityChecker.query(0,3,3); // returns -1
majorityChecker.query(2,3,2); // returns 2
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
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

class MajorityChecker {
   public:
    MajorityChecker(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; ++i) idx[arr[i]].emplace_back(i);
    }

    int find_index_left(vector<int>& vect, int low, int high, int target) {
        int res = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (vect[mid] >= target) {
                res = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return res;
    }

    int find_index_right(vector<int>& vect, int low, int high, int target) {
        int res = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (vect[mid] <= target) {
                res = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return res;
    }

    int query(int left, int right, int threshold) {
        unordered_map<int, int> count;

        for (auto& p : idx) {
            auto& vect = p.second;
            if (vect.empty()) continue;
            auto lid = find_index_left(vect, 0, vect.size() - 1, left);
            if (lid == -1) continue;
            auto rid = find_index_right(vect, 0, vect.size() - 1, right);
            if (rid == -1) {
                continue;
            }
            auto dist = rid - lid + 1;
            if (dist >= threshold) count[p.first] = dist;
        }

        auto it = max_element(begin(count), end(count), [](auto& p1, auto& p2) {
            return p1.second < p2.second;
        });

        if (it != end(count) && it->second >= threshold)
            return it->first;
        else
            return -1;
    }

    static constexpr int nsize = 20001;
    unordered_map<int, vector<int>> idx;
};

void test1() {
    vector<int> v{1, 1, 2, 2, 1, 1};
    MajorityChecker checker(v);
    cout << checker.query(0, 5, 4) << endl;  // returns 1
    cout << checker.query(0, 3, 3) << endl;  // returns -1
    cout << checker.query(2, 3, 2) << endl;  // returns 2
}

void test2() {
    int nsize = 20000;
    vector<int> v(nsize, 1);
    MajorityChecker checker(v);
    for (int i = 0; i < 100000; ++i) {
        int left, right;
        tie(left, right) = minmax(rand() % nsize, rand() % nsize);
        checker.query(left, right, nsize / 2);
    }
}

void test3() {
    vector<int> v{1, 1, 2, 2, 1, 1, 3, 4, 3, 2, 5, 1, 2, 4, 1, 2, 3, 3, 3, 2};
    MajorityChecker checker(v);
    cout << checker.query(0, 5, 4) << endl;    // returns 1
    cout << checker.query(0, 3, 3) << endl;    // returns -1
    cout << checker.query(2, 3, 2) << endl;    // returns 2
    cout << checker.query(4, 6, 2) << endl;    // returns 1
    cout << checker.query(5, 7, 2) << endl;    // returns -1
    cout << checker.query(6, 8, 2) << endl;    // returns 3
    cout << checker.query(7, 9, 2) << endl;    // returns -1
    cout << checker.query(12, 15, 2) << endl;  // returns 2
    cout << checker.query(15, 16, 2) << endl;  // returns -1
    cout << checker.query(15, 17, 2) << endl;  // returns 3
    cout << checker.query(15, 18, 3) << endl;  // returns 3
    cout << checker.query(15, 19, 3) << endl;  // returns 3
    cout << checker.query(15, 20, 3) << endl;  // returns 3
    cout << checker.query(15, 18, 4) << endl;  // returns -1
}

int main() {
    // test1();
    // test2();
    test3();
    return 0;
}
