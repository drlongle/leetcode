class Solution {
public:
    void util(vector<int> &nums, int start, vector<vector<int>> &res, vector<int> &subres, int product) {
        if(product == 1)
            res.push_back(subres);
        if(product < 1 ) return;
        for(int i = start; i < nums.size(); i++) {
            if((product % nums[i]) == 0) {
                subres.push_back(nums[i]);
                util(nums, i, res, subres, product/nums[i]);
                subres.pop_back();
            }
        }
    }
    vector<int> factors(int n) {
        vector<int> res;
        for(int i = 2; i*i <= n; i++) {
            if(n % i == 0){
                res.push_back(i);
                // get only distinct factors
                if(n/i != i)
                    res.push_back(n/i);
            }
        }
        return res;
    }
    vector<vector<int>> getFactors(int n) {
        if (n == 1) return {};
        vector<vector<int>> res;
        vector<int> subres;
        vector<int> nums = factors(n);
        util(nums, 0, res, subres, n);
        return res;
    }
};
