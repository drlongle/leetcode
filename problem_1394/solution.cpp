/*
1394. Find Lucky Integer in an Array
Easy

Given an array of integers arr, a lucky integer is an integer which has a frequency in the array equal to its value.

Return a lucky integer in the array. If there are multiple lucky integers return the largest of them. If there is no lucky integer return -1.

Example 1:
Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.

Example 2:
Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.

Example 3:
Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.

Example 4:
Input: arr = [5]
Output: -1

Example 5:
Input: arr = [7,7,7,7,7,7,7]
Output: 7

Constraints:
1 <= arr.length <= 500
1 <= arr[i] <= 500
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
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> cnt;
        for (int a: arr)
            ++cnt[a];
        for (auto it = cnt.rbegin(); it != cnt.rend(); ++it) {
            if (it->first == it->second)
                return it->first;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    // Output: 2
    arr = {2,2,3,4};
    cout << sol.findLucky(arr) << endl;
    
    // Output: 3
    arr = {1,2,2,3,3,3};
    cout << sol.findLucky(arr) << endl;
    
    // Output: -1
    arr = {2,2,2,3,3};
    cout << sol.findLucky(arr) << endl;
    
    // Output: -1
    arr = {5};
    cout << sol.findLucky(arr) << endl;
    
    // Output: 7
    arr = {7,7,7,7,7,7,7};
    cout << sol.findLucky(arr) << endl;
        
    return 0;
}
