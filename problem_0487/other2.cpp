class Solution {
public:
    int res = INT_MIN;
    int i = 0;
    int count = 0;
    int lastIdx = -1;

    int findMaxConsecutiveOnes(vector<int>& nums) {
        for(int j = 0; j < nums.size(); j++){
            count += nums[j] ? 0 : 1;
            if(count > 1){
                i = lastIdx + 1;
                count--;
            }else{
                res = max(res, j - i + 1);
            }

            if(nums[j] == 0) lastIdx = j;
        }
        return res;
    }
};
