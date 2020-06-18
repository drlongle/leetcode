/*
precalculate at each position, i, the min length of array with target sum from left and from right respectively.
a. fromLeft[i]: from the leftmost to position, i, (i.e. [0 .. i]), the min length of the array with target sum
b. fromRight[i]: from the rightmost to position, i, (i.e. [i .. n-1]), the min length of the array with target sum
use DP to find the min sum of length at each pisition, i. (i.e. , dp[i] = fromLeft[i] + fromRight[i+1])
a. consider the minimal sum of two arrays' length at each index, i.
(i.e. min sum of length at index i = min length in the range of [0 .. i] + min length in the range of [i+1 .. n-1])
b. reverse the given array and apply the same subfunction to simply the code.
*/
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // from the left, min length of array with sum = target
        vector<int> left = minLen(arr, target);

        // from the right, min length of array with sum = target
        vector<int> arrReverse(arr.begin(), arr.end());
        reverse(arrReverse.begin(), arrReverse.end());
        vector<int> right = minLen(arrReverse, target);
        
        // consider each position to find the min sum of length of the two array with target sum
        int min_val = arr.size() + 1;
        int n = arr.size();
        for(int i = 0; i < arr.size() - 1; ++i) {
            min_val = min(min_val, left[i] + right[n-1-i-1]);
        }
        return min_val == arr.size() + 1 ? -1 : min_val;
    }
    
    // at each position, i, find the min length of array with target sum 
    vector<int> minLen(vector<int> &arr, int target) {
        int n = arr.size();
        vector<int> presum(n, 0);
        unordered_map<int, int> idx;
        vector<int> ans(n, n + 1);
        idx[0] = -1;
        for(int i = 0; i < arr.size(); ++i) {
            presum[i] = i == 0 ? arr[i] : arr[i] + presum[i-1];
            int len = arr.size() + 1;
            if(idx.find(presum[i] - target) != idx.end()) {
                len = i - idx[presum[i]-target];
            }
            idx[presum[i]] = i;
            ans[i] = i == 0 ? len : min(ans[i-1], len);    
        }
        return ans;
    }  
};
