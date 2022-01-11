class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ret;
        int num, i = 0;

        while(i<nums.size()){
            num = nums[i++];
            int p = num;
            string ans = to_string(num);
            while(i<nums.size()&&num+1==nums[i])
                num = nums[i++];
            ret.push_back(p!=num?ans+"->"+to_string(num):ans);
        }
        return ret;
    }
};
