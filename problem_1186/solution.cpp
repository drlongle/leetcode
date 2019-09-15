/*
1186. Maximum Subarray Sum with One Deletion
Medium

Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.

Example 1:
Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.

Example 2:
Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.

Example 3:
Input: arr = [-1,-1,-1,-1]
Output: -1
Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
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
    pair<int, int> search(vector<int>& arr, int begin, int end, int inc, function<bool(int, int)> comp) {
        set<int> negatives;
        int sum = 0, max_sum = arr[begin], max_sum_deleted = arr[begin];
        for (int i = begin; comp(i, end); i += inc) {
            sum += arr[i];
            if (arr[i] < 0)
                negatives.emplace(arr[i]);
            max_sum = max(max_sum, sum);
            max_sum_deleted = max(max_sum_deleted, sum - (negatives.empty() ? 0 : *negatives.begin()));
        }

        return {max_sum, max_sum_deleted};
    }

    vector<int> maximumSum(vector<int>& arr, int begin, int end) {
        if (begin == end)
            return {arr[begin], arr[begin], max(arr[begin], 0), arr[begin], max(arr[begin], 0)};
        int mid = (begin + end) / 2;
        auto ls = search(arr, begin, end, 1, [](const int a, const int b) {return a <= b;});
        auto rs = search(arr, end, begin, -1, [](const int a, const int b) {return a >= b;});

        auto lres = maximumSum(arr, begin, mid);
        auto rres = maximumSum(arr, mid+1, end);
        int res = max(lres[0], rres[0]);
        res = max(res, lres[3] + rres[2]);
        res = max(res, lres[4] + rres[1]);

        return {res, ls.first, ls.second, rs.first, rs.second};
    }

    int maximumSum(vector<int>& arr) {
        return maximumSum(arr, 0, arr.size()-1)[0];
    }
};


int main() {
    Solution sol;
    return 0;
}
