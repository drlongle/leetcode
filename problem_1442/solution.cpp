/*
1442. Count Triplets That Can Form Two Arrays of Equal XOR
Medium

Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.
Return the number of triplets (i, j and k) Where a == b.

Example 1:
Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)

Example 2:
Input: arr = [1,1,1,1,1]
Output: 10

Example 3:
Input: arr = [2,3]
Output: 0

Example 4:
Input: arr = [1,3,5,7,9]
Output: 3

Example 5:
Input: arr = [7,11,12,9,5,2,7,17,22]
Output: 8

Constraints:
1 <= arr.length <= 300
1 <= arr[i] <= 10^8
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
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
    int countTriplets(vector<int>& arr) {
        unordered_map<int, map<int, int>> cnt;
        int n = arr.size();
        int res = 0;
        for (int i = n; i >= 0; --i) {
            for (int j = i, sum = 0; j < n; ++j) {
                sum ^= arr[j];
                auto& candidates = cnt[sum];
                auto it = candidates.upper_bound(j);
                if (it != candidates.end() && it->first == j+1)
                    res += it->second;
                ++cnt[sum][i];
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    // Output: 4
    arr = {2,3,1,6,7};
    cout << sol.countTriplets(arr) << endl;

    // Output: 10
    arr = {1,1,1,1,1};
    cout << sol.countTriplets(arr) << endl;
    
    // Output: 0
    arr = {2,3};
    cout << sol.countTriplets(arr) << endl;
    
    // Output: 3
    arr = {1,3,5,7,9};
    cout << sol.countTriplets(arr) << endl;
    
    // Output: 8
    arr = {7,11,12,9,5,2,7,17,22};
    cout << sol.countTriplets(arr) << endl;

    return 0;
}
