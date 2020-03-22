class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> div;
            for (int j = 1; j <= sqrt(nums[i]); j++)
                if (nums[i] % j == 0) {
                    div.push_back(j);
                    if (j != sqrt(nums[i])) div.push_back(nums[i] / j);
                }
            if ((int)div.size() == 4) 
                for (int k : div)
                    res += k;
        }
        return res;
    }
};
