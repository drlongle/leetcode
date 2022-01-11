class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0,r=0;

        if (nums.size() == 1 ) return 1;
        int ans = 0, firstZero = 0,fz_pos = -1;
        while ( r < nums.size()){
            if (nums[r] == 1) r++;
            else {
                if (firstZero == 0) {
                    firstZero = 1;
                    fz_pos = r;
                    r++;
                    continue;
                } else {
                    ans = std::max(ans, r-l);
                    //r++;
                    l = fz_pos+1;
                    firstZero = 0;
                }
            }
        }
        if (firstZero) {
            ans = std::max(ans, r-l);
        }
        if (fz_pos == -1) ans = r;
        return ans;
    }
};