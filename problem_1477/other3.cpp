/*
sliding window
Find two sub-arrays to meet the following two conditions:

sum(sub_array1) == target && sum(sub_array2) == target
min_of_all_possible_comibantion(len1 + len2), where len1= length(sub_array1),
len2= length(sub_array2), len1 and len2 are the smallest two subarrays meet the condition 1.
Note:
min_of_all_possible(len1 + len2) =/= min_of_all_possible(len1) + min_of_all_possible(len2)
*/
class Solution { // Sliding window; Original author: huahua[1]
public: // Time/Space: O(N); O(N)
    int minSumOfLengths(vector<int>& arr, int target) {
        const int n = arr.size(), kInf = INT_MAX/2;
        int ans = kInf;
        vector<int> memo(n, kInf); //memo[i] := min length of a valid subarray ends or before i.
        for(int i = 0, sum = 0, s=0, min_len = kInf; i < n; i++){
            sum += arr[i];
            while(sum > target) sum -= arr[s++]; //shrink from left, 's'
            if(sum == target){                
                int cur_len = i - s + 1;
                if( s > 0 && memo[s-1] != kInf)
                    ans = min(ans, cur_len + memo[s-1]);
                min_len = min(min_len, cur_len);
            }
            memo[i]=min_len;
        }        
        return ans < kInf ? ans : -1;
    }
};
