/*
1213. Intersection of Three Sorted Arrays
Easy

Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order,
return a sorted array of only the integers that appeared in all three arrays.

Example 1:
Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation: Only 1 and 5 appeared in the three arrays.
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

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        map<int, int> count;
        for (int i: arr1)
            ++count[i];
        for (int i: arr2)
            ++count[i];
        for (int i: arr3)
            ++count[i];
        for (auto& p: count) {
            if (p.second == 3)
                ans.emplace_back(p.first);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr1, arr2, arr3;

    // Output: {1,5}
    arr1 = {1,2,3,4,5}, arr2 = {1,2,5,7,9}, arr3 = {1,3,4,5,8};

    auto ans = sol.arraysIntersection(arr1, arr2, arr3);
    copy(begin(ans), end(ans), ostream_iterator<int>(cout, ", "));
    
    return 0;
}
