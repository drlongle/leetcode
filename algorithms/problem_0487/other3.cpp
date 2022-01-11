class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // prev and next are run-length of the previous and current consecutive ones
        int next = 0, prev = 0, maxi = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                maxi = max(maxi, prev + next);
                prev = next + 1;
                next = 0;
            } else next++;
        }
        return max(maxi, prev + next);
    }
};
