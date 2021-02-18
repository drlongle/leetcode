class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, i = 0, n = A.size();
        while (i + 1 < n) {
            int j = i + 1;
            int diff = A[j] - A[i];
            while (j + 1 < n && A[j+1] - A[j] == diff)
                ++j;
            int nums = j - i + 1;
            res += nums * (nums + 1) / 2 - nums - (nums - 1);
            i = j;
        }
        return res;
    }
};