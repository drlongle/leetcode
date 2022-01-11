/*
1122. Relative Sort Array
Easy

Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements
that don't appear in arr2 should be placed at the end of arr1 in ascending order.

Example 1:
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
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

class Solution {
public:

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> order;
        for (int i = 0; i < arr2.size(); ++i) {
            order[arr2[i]] = i;
        }
        sort(begin(arr1), end(arr1), [&order] (const int el1, const int el2) {
                bool el1_present = order.count(el1);
                bool el2_present = order.count(el2);
                if (!el1_present && !el2_present)
                    return el1 < el2;
                if (el1_present && el2_present)
                    return order[el1] < order[el2];
                if (el2_present)
                    return false;
                else
                    return true;

            });
        return arr1;
    }

};

int main() {
    Solution sol;
    vector<int> arr1, arr2, res;

    arr1 = {2,3,1,3,2,4,6,7,9,2,19}, arr2 = {2,1,4,3,9,6};

    res = sol.relativeSortArray(arr1, arr2);

    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}

