/*
1157. Online Majority Element In Subarray
Hard

Implementing the class MajorityChecker, which has the following API:

    MajorityChecker(int[] arr) constructs an instance of MajorityChecker with
the given array arr; int query(int left, int right, int threshold) has arguments
such that: 0 <= left <= right < arr.length representing a subarray of arr; 2 *
threshold > right - left + 1, ie. the threshold is always a strict majority of
the length of the subarray

Each query(...) returns the element in arr[left], arr[left+1], ..., arr[right]
that occurs at least threshold times, or -1 if no such element exists.
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

class SegmentTree {
   public:
    SegmentTree(vector<int>& d) : data_size(d.size()) {
        int x = ceil(log2(data_size));
        int max_size = 2 * (int)pow(2, x) - 1;
        index_limit = pow(2, x) - 1;
        data.resize(max_size);
    }

    void add(int index, int low, int high, int begin, int end, int val,
             vector<unordered_map<int, int>*>& count) {
        if (low > end || begin > high) return;
        if (begin <= low && high <= end) {
            data[index][val]++;
            for (auto& c : count) (*c)[val]++;
            return;
        }
        count.emplace_back(&data[index]);
        int mid = (low + high) / 2;
        add(2 * index + 1, low, mid, begin, end, val, count);
        add(2 * index + 2, mid + 1, high, begin, end, val, count);
    }

    void add(int index, int val) {
        vector<unordered_map<int, int>*> res;
        add(0, 0, index_limit, index, index, val, res);
    }
    void join(unordered_map<int, int>& m1, const unordered_map<int, int>& m2) {
        for (auto& p : m2) m1[p.first] += p.second;
    }

    void join(unordered_map<int, int>& m1, unordered_map<int, int>&& m2) {
        for (auto& p : m2) m1[p.first] += p.second;
    }

    void get_data(int index, int low, int high, int begin, int end,
                  unordered_map<int, int>& count) {
        if (begin <= low && high <= end) {
            join(count, data[index]);
            return;
        }
        if (low > end || begin > high) return;
        int mid = (low + high) / 2;
        unordered_map<int, int> res;
        get_data(2 * index + 1, low, mid, begin, end, count);
        get_data(2 * index + 2, mid + 1, high, begin, end, count);
    }

    void get_data(int low, int high, unordered_map<int, int>& res) {
        get_data(0, 0, index_limit, low, high, res);
    }

    vector<unordered_map<int, int>> data;
    int index_limit, data_size;
};

/*
This solution was not accepted because time limit exceeded.
 */
class MajorityChecker {
   public:
    MajorityChecker(vector<int>& arr) : seg(arr) {
        int nsize = arr.size();
        for (int i = 0; i < nsize; ++i) seg.add(i, arr[i]);
    }

    int query(int left, int right, int threshold) {
        unordered_map<int, int> res;
        seg.get_data(left, right, res);
        auto it = max_element(begin(res), end(res), [](auto& p1, auto& p2) {
            return p1.second < p2.second;
        });
        // cout << "left: " << left << ", right: " << right << ", elem: " <<
        // it->first << ", count: " << it->second << endl;
        if (it->second >= threshold)
            return it->first;
        else
            return -1;
    }

    SegmentTree seg;
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

int main() {
    test1();
    // test2();
    return 0;
}
