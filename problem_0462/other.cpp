class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        while(start < end)
        {
            res += nums[end] - nums[start];
            start++;
            end--;
        }
        return res;
    }
};
