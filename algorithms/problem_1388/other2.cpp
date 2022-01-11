/*
Idea
We first divide the problem into 2 sub-problem. (since we cannot have slice 0 and slice n at the same time)
1. we choose from pizza [0, ..., n-1] as a linear pizza instead of a circular pizza
2. we choose from pizza [1, ..., n] as a linear pizza instead of a circular pizza

We then track the maximum amount we ate after eating the ith pizza we have in eat. There are only 2 possibilities as follows.
1. largest value when encountering the previous slice
2. current slice + largest value when encountering last second slice

Similar Questoins
  188. Best Time to Buy and Sell Stock IV
  213. House Robber II

*/
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = (int)slices.size() / 3;
        auto l1 = vector<int>(slices.begin(), slices.end()-1);
        auto l2 = vector<int>(slices.begin()+1, slices.end());
        return max(linear(l1, n), linear(l2, n));
    }
    
private:
    int linear(vector<int>& slices, int n) {
        vector<vector<int>> eat((int)slices.size()+2, vector<int>(n+1, INT_MIN));
        int res = INT_MIN;
        for (int i=0; i<eat.size(); ++i) eat[i][0] = 0;

        // i is the index for slices[i] and j is the number of pizzas we have eaten
        for (int i=2; i<eat.size(); ++i) {
            for (int j=1; j<n+1; ++j)
                eat[i][j] = max(eat[i-1][j], eat[i-2][j-1] + slices[i-2]);
            res = max(eat[i][n], res);
        }
        return res;
    }
};
