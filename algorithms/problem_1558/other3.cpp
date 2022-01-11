class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),res=0,best=0;
        for(int num:nums){
            res+= hammingDistance(num);
            int high= num==0? 0:(int)(log2(num));  // index of the highest set bit
            best= max(best,high);
        }
        return res+best;
    }
    int hammingDistance(int x) {  // count #ones
        int count = 0;
        for (int i = 0; i < 32; i++)
            if (x & (1 << i)) count++;
        return count;
    }
};