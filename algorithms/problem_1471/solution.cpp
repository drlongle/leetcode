/*
1471. The k Strongest Values in an Array
Medium

Given an array of integers arr and an integer k.

A value arr[i] is said to be stronger than a value arr[j] if |arr[i] - m| > |arr[j] - m| where m is the median of the array.
If |arr[i] - m| == |arr[j] - m|, then arr[i] is said to be stronger than arr[j] if arr[i] > arr[j].

Return a list of the strongest k values in the array. return the answer in any arbitrary order.

Median is the middle value in an ordered integer list. More formally, if the length of the list is n, the median is the element in position ((n - 1) / 2) in the sorted list (0-indexed).

For arr = [6, -3, 7, 2, 11], n = 5 and the median is obtained by sorting the array arr = [-3, 2, 6, 7, 11] and the median is arr[m] where m = ((5 - 1) / 2) = 2. The median is 6.
For arr = [-7, 22, 17, 3], n = 4 and the median is obtained by sorting the array arr = [-7, 3, 17, 22] and the median is arr[m] where m = ((4 - 1) / 2) = 1. The median is 3.

Example 1:
Input: arr = [1,2,3,4,5], k = 2
Output: [5,1]
Explanation: Median is 3, the elements of the array sorted by the strongest are [5,1,4,2,3]. The strongest 2 elements are [5, 1]. [1, 5] is also accepted answer.
Please note that although |5 - 3| == |1 - 3| but 5 is stronger than 1 because 5 > 1.

Example 2:
Input: arr = [1,1,3,5,5], k = 2
Output: [5,5]
Explanation: Median is 3, the elements of the array sorted by the strongest are [5,5,1,1,3]. The strongest 2 elements are [5, 5].

Example 3:
Input: arr = [6,7,11,7,6,8], k = 5
Output: [11,8,6,6,7]
Explanation: Median is 7, the elements of the array sorted by the strongest are [11,8,6,6,7,7].
Any permutation of [11,8,6,6,7] is accepted.

Example 4:
Input: arr = [6,-3,7,2,11], k = 3
Output: [-3,11,2]

Example 5:
Input: arr = [-7,22,17,3], k = 2
Output: [22,17]

Constraints:
1 <= arr.length <= 10^5
-10^5 <= arr[i] <= 10^5
1 <= k <= arr.length
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
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        int mid = (n-1) / 2;
        nth_element(begin(arr), begin(arr) + mid, end(arr));
        int median = arr[mid];
        auto lambda = [&] (int i, int j) {
                          int diff = abs(arr[i] - median) - abs(arr[j] - median);
                          return diff > 0 || (diff == 0 && arr[i] > arr[j]);
                      };
        priority_queue<int, vector<int>, decltype(lambda)> pq(lambda);
        for (int i = 0; i < n; ++i) {
            if (static_cast<int>(pq.size()) < k) {
                pq.push(i);
            } else if (lambda(i, pq.top())) {
                pq.pop();
                pq.push(i);                
            }
        }
        vector<int> res;
        while (pq.size()) {
            res.push_back(arr[pq.top()]);
            pq.pop();
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr, res;
    int k;

    // Output: {5,1}
    arr = {1,2,3,4,5}, k = 2;
    res = sol.getStrongest(arr, k);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    // Output: {5,5}
    arr = {1,1,3,5,5}, k = 2;
    res = sol.getStrongest(arr, k);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    // Output: {11,8,6,6,7}
    arr = {6,7,11,7,6,8}, k = 5;
    res = sol.getStrongest(arr, k);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    // Output: {-3,11,2}
    arr = {6,-3,7,2,11}, k = 3;
    res = sol.getStrongest(arr, k);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    // Output: {22,17}
    arr = {-7,22,17,3}, k = 2;
    res = sol.getStrongest(arr, k);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    return 0;
}
