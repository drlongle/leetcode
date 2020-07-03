/*
1497. Check If Array Pairs Are Divisible by k
Medium

Given an array of integers arr of even length n and an integer k.

We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

Return True If you can find a way to do that or False otherwise.

Example 1:
Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true
Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).

Example 2:
Input: arr = [1,2,3,4,5,6], k = 7
Output: true
Explanation: Pairs are (1,6),(2,5) and(3,4).

Example 3:
Input: arr = [1,2,3,4,5,6], k = 10
Output: false
Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.

Example 4:
Input: arr = [-10,10], k = 2
Output: true

Example 5:
Input: arr = [-1,1,-2,2,-3,3,-4,4], k = 3
Output: true

Constraints:
arr.length == n
1 <= n <= 10^5
n is even.
-10^9 <= arr[i] <= 10^9
1 <= k <= 10^5
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

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> cnt(k, 0);
        int pairs = 0, n = arr.size();
        for (int n: arr) {
            int d = n % k;
            d += (d < 0) ? k : 0;
            if (cnt[(k - d) % k]) {
                ++pairs;
                --cnt[(k - d) % k];
            } else
                ++cnt[d];
        }

        return pairs == n/2;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int k;

    // Output: true
    arr = {1,2,3,4,5,10,6,7,8,9}, k = 5;
    cout << boolalpha << sol.canArrange(arr, k) << endl;

    // Output: true
    arr = {1,2,3,4,5,6}, k = 7;
    cout << boolalpha << sol.canArrange(arr, k) << endl;

    // Output: false
    arr = {1,2,3,4,5,6}, k = 10;
    cout << boolalpha << sol.canArrange(arr, k) << endl;

    // Output: true
    arr = {-10,10}, k = 2;
    cout << boolalpha << sol.canArrange(arr, k) << endl;

    // Output: true
    arr = {-1,1,-2,2,-3,3,-4,4}, k = 3;
    cout << boolalpha << sol.canArrange(arr, k) << endl;

    return 0;
}
