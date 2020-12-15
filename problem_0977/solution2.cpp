class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int x = nums[i]*nums[i];
            int y = nums[j]*nums[j];
            if (x >= y) {
                res.push_back(x);
                ++i;
            } else {
                res.push_back(y);
                --j;
            }
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};
