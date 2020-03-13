class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
	vector<int> dp(nums);
	for(int d=1; d<nums.size(); d++){
            for(int i=0; i+d<nums.size(); i++){
                dp[i] = max(nums[i]-dp[i+1], nums[i+d]-dp[i]);
            }
	}
	return dp[0] >= 0;
    }
};
