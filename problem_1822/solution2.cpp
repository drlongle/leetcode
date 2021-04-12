class Solution {
public:
    int arraySign(vector<int>& nums) {
        auto lambda = [] (int prod, int num) { return num ? prod * num / abs(num) : 0;};
        return accumulate(begin(nums), end(nums), 1, lambda);
    }
};
