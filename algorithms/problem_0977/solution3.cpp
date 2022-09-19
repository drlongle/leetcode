class Solution {
  public:
    vector<int> sortedSquares(vector<int> &nums) {
        vector<int> res;
        for (int n : nums) {
            res.push_back(n * n);
        }
        sort(begin(res), end(res));
        return res;
    }
};
