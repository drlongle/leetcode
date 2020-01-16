/*
1207. Unique Number of Occurrences
Easy

Given an array of integers arr, write a function that returns true if and only if the
number of occurrences of each value in the array is unique.


Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
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
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        for (auto a: arr)
            ++count[a];
        set<int> occur;
        for (auto& p: count) {
            auto res = occur.insert(p.second);
            if (!res.second)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    return 0;
}
