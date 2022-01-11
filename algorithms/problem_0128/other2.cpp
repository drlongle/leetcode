// Basically, LCS[x] = length of the longest sequence ending at x. if x-1 exists, LCS[x] = LCS[x-1] + 1, else LCS[x] = 1.

class Solution {
public:
    int calc_lcs_util(unordered_map<int, int>& LCS, int n) {
        if (LCS[n] != 0)
            return LCS[n];
            
        if (LCS.find(n-1) != LCS.end())
            LCS[n] = 1 + calc_lcs_util(LCS, n - 1);
        else
            LCS[n] = 1;
        return LCS[n];
    }
    int longestConsecutive(vector<int>& nums) {
        int max_lcs = 0;
        unordered_map<int, int> LCS;
        
        for (auto n: nums) {
            LCS[n] = 0;
        }
        
        for (auto n: nums) {
            max_lcs = max(max_lcs, calc_lcs_util(LCS, n));
        }
        return max_lcs;
    }
};

