/*
1300. Sum of Mutated Array Closest to Target
Medium

Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

In case of a tie, return the minimum such integer.

Notice that the answer is not neccesarilly a number from arr. 

Example 1:
Input: arr = [4,9,3], target = 10
Output: 3
Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.

Example 2:
Input: arr = [2,3,5], target = 10
Output: 5

Example 3:
Input: arr = [60864,25176,27249,21296,20204], target = 56803
Output: 11361

Constraints:

1 <= arr.length <= 10^4
1 <= arr[i], target <= 10^5
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

    int getSum(const vector<int>& arr, int value) {
        int low = 0, high = sz - 1;
        int index = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == value) {
                index = mid;
                break;
            } else if (arr[mid] > value) {
                index = min(index, mid);
                high = mid - 1;
            } else
                low = mid + 1;
        }
        int sum = (index > 0 ? prefix[index-1] : 0) + (sz - index) * value;
        return sum;
    }

    vector<int> prefix;
    int sz;
    int findBestValue(vector<int>& arr, int target) {
        sort(begin(arr), end(arr));
        sz = arr.size();
        partial_sum(begin(arr), end(arr), back_inserter(prefix));

        int res = 0, diff = numeric_limits<int>::max();
        int lo = 0, hi = arr.back();
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int s = getSum(arr, mid);
            if (abs(target - s) < diff || (abs(target -s) == diff && mid < res)) {
                res = mid;
                diff = abs(target - s);
            }
            if (s == target)
                break;
            if (s > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int target;

    // Output: 3
    arr = {4,9,3}, target = 10;

    // Output: 5
    //arr = {2,3,5}, target = 10;

    // Output: 11361
    //arr = {60864,25176,27249,21296,20204}, target = 56803;
    
    cout << "Result: " << sol.findBestValue(arr, target) << endl;
    
    return 0;
}
