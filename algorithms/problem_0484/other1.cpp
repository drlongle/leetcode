class Solution {
public:
    void reverse(vector<int>& perm, int start, int end) {
        while (start <= end) {
            int temp = perm[start];
            perm[start] = perm[end];
            perm[end] = temp;
            start++;
            end--;
        }
    }
    vector<int> findPermutation(string s) {
        int n = s.length() + 1;
        vector<int> perm(n);

        for (int i = 0; i < n; ++i)
            perm[i] = i + 1;

        int idx = 0;
        int start = -1, end = -1;
        while (idx < s.length()) {
            if (s[idx] == 'I') {
                if (start != -1) {
                    end = idx;
                    reverse(perm, start, end);
                    start = -1;
                }
            }
            else {
                if (start == -1)
                    start = idx;
            }
            idx++;
        }

        if (start != -1) {
            end = idx;
            reverse(perm, start, end);
        }

        return perm;
    }
};
