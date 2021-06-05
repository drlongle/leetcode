class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int m = nums.size();
        int left = 0, right = m-1;

        auto eval = [&](int x){
            return a*x*x + b*x + c;
        };

        vector<int> res;
        while (left <= right) {
            int eval_left = eval(nums[left]);
            int eval_right = eval(nums[right]);
            if ((a > 0) ^ (eval_left < eval_right)) {
                res.push_back(eval_left);
                left++;
            } else {
                res.push_back(eval_right);
                right--;
            }
        }

        if (a > 0) reverse(res.begin(), res.end());
        return res;
    }
};
