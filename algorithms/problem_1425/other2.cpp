class Solution {
public:
	int constrainedSubsetSum(vector<int> &nums, int k) {
		int ans  = nums[0];
		deque<int> maxd;
		maxd.push_back(nums[0]);
		for(int i = 1;i<nums.size();i++){
			nums[i] = max(maxd.front() + nums[i],nums[i]);
			while(!maxd.empty() && maxd.back() < nums[i]){
				maxd.pop_back();
			}
			maxd.push_back(nums[i]);
			ans = max(ans,maxd.front());
			if(i>=k && maxd.front() == nums[i-k]) maxd.pop_front();
		}
		return ans;
	}
};
