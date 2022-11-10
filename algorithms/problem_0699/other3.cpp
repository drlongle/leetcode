class Solution {
  public:
    vector<int> fallingSquares(vector<vector<int>> &pos) {
        int n = pos.size();
        vector<int> h(n); // h[i] means the height at which the top surface of
                          // i-th block ends up
        h[0] =
            pos[0][1]; // in the beginning it's obviously just the height of the
                       // first block because it is dropped at an empty surface
        vector<int> ans(
            1, h[0]); // and the first element of the answer is the same
        for (int i = 1; i < n; i++) {
            int under = 0; // the hight at which the i-th block will stop moving
                           // down. then h[i] = under + own height of the block
            for (int j = 0; j < i; j++) {
                bool ok = false; // check if there is any previous block under
                                 // the i-th block
                if (pos[j][0] <
                    pos[i][0]) { // if the j-th block is to the left from the
                                 // left side of the i-th block
                    if (pos[j][0] + pos[j][1] > pos[i][0])
                        ok = true; // it's right point must be to the right side
                                   // to overlap (case A)
                } else { // if it's to the right, then it's left side should be
                         // to the left from the right side of the i-th block
                         // (case B)
                    if (pos[j][0] < pos[i][0] + pos[i][1])
                        ok = true;
                }
                if (ok)
                    under = max(under, h[j]);
            }
            h[i] = under + pos[i][1];
            ans.push_back(max(ans.back(), h[i]));
        }
        return ans;
    }
};
