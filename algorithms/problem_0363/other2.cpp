class Solution {
public:
int maxSumK(vector<int> &nums, int K) {
        set<int> s;
        int      ans = INT_MIN;
        int      sum = 0;

        s.insert(0);
        for (auto n : nums) {
            sum += n;
            auto pos = s.lower_bound(sum - K);
            if (pos != s.end())
                ans = max(ans, sum - *pos);
            s.insert(sum);
        }
        return ans;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty())
            return 0;
        
        int R = matrix.size();
        int C = matrix[0].size();
        int ans = INT_MIN;
        // lc --> left column, rc-->right column
        for (int lc = 0; lc < C; ++lc) {
            vector<int> sums(R, 0);
            for (int rc = lc; rc < C; ++rc) {
                for (int r = 0; r < R; ++r)
                    sums[r] += matrix[r][rc];
                ans = max(ans, maxSumK(sums, k));
            }
        }
        return ans;
    }
};
