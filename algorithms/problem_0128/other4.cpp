class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }

        unordered_set<int> s(nums.begin(), nums.end());
        int count=1;  // since a number itself can be a sequence
        for(int i=0;i<nums.size();i++){
            //find the starting value of the sequence
            if(!s.count(nums[i]-1)){
                int curr_num=nums[i];
                int curr_count=0;
                //find the consecutive sequence
                while(s.find(curr_num)!=s.end()){
                    curr_count++;
                    curr_num++;
                }
                count=max(count,curr_count);
            }
        }
        return count;
    }
};
