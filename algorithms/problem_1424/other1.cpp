class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> diag;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                if (i + j == diag.size()) diag.push_back({});
                diag[i + j].push_back(nums[i][j]);
            }
        }
        
        vector<int> res;
        for (auto& it: diag)
            copy(it.rbegin(), it.rend(), back_inserter(res));
        return res;
    }
};
