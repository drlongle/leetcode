class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      	//the number which is redundant
        int repeatNode=0;
        //record the number first scan   such as   1 1 2 2 3 3    the firstPos is 1 2 3
        int firstPos=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==nums[firstPos]&&i-firstPos>1)
            {
                repeatNode++;
            }
            else if(nums[i]!=nums[firstPos])
            {
                firstPos=i;
            }
            nums[i-repeatNode]=nums[i];
        }
        return nums.size()-repeatNode;
    }
};

