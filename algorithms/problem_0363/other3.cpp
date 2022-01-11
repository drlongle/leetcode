class Solution {
private:
    int maxSubSum(vector<vector<int>>& pres, int r1, int r2, int k) {        
        int n = pres[0].size();
        
        int res = numeric_limits<int>::min();
        
        vector<int> pre(n + 1, 0);
        set<int> bst;
        bst.insert(0);
        for (int i = 1; i < n + 1; ++i) {
            int num = pres[r2 + 1][i - 1] - pres[r1][i - 1];
            pre[i] = num + pre[i - 1];           
            int target = pre[i] - k;

            auto it = bst.lower_bound(target);
            if (it != bst.end()) {
                res = max(res, pre[i] - *it);
            }
            
            bst.insert(pre[i]);
        }
        
        return res;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>> pres(row + 1, vector<int>(col, 0));
        for (int j = 0; j < col; ++j) {
            for (int i = 1; i < row + 1; ++i) {
                pres[i][j] = pres[i - 1][j] + matrix[i - 1][j];
            }
        }
        
        int res = numeric_limits<int>::min();
        for (int i = 0; i < row; ++i) {
            for (int j = i; j < row; ++j) {
                res = max(res, maxSubSum(pres, i, j, k));
            }
        }
        
        return res;
    }
};
