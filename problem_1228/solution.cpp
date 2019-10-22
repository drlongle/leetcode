/*
1228. Missing Number In Arithmetic Progression
Easy

In some array arr, the values were in arithmetic progression: the values arr[i+1] - arr[i]
are all equal for every 0 <= i < arr.length - 1. Then, a value from arr was removed that was
not the first or last value in the array.

Return the removed value.

Example 1:
Input: arr = [5,7,11,13]
Output: 9
Explanation: The previous array was [5,7,9,11,13].

Example 2:
Input: arr = [15,13,12]
Output: 14
Explanation: The previous array was [15,14,13,12].
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
    int missingNumber(vector<int>& arr) {
        int sz = arr.size();
        map<int, vector<int>> lookup;
        for (int i = 0; i < sz-1; ++i) {
            int diff = arr[i+1] - arr[i];
            if (lookup[diff].size() > 1)
                continue;
            lookup[diff].emplace_back(i);
        }
        if (lookup.begin()->second.size() == lookup.rbegin()->second.size()) {
            int index;
            if (lookup.begin()->first >= 0)
                index = lookup.rbegin()->second[0];
            else
                index = lookup.begin()->second[0];
            return (arr[index+1] + arr[index]) / 2;
        }
        for (auto& p: lookup) {
            if (p.second.size() == 1) {
                int index = p.second[0];
                return (arr[index+1] + arr[index]) / 2;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    arr = {5,7,11,13};
    arr = {15,13,12};
    arr = {100,300,400};
    cout << sol.missingNumber(arr) << endl;
    
    return 0;
}
