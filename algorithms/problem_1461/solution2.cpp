struct Solution {
    bool hasAllCodes(string s, int k) {
        int size = 1 << k;
        int mask = size - 1, count = 0;
        vector<int> contains(size, 0);
        for (int i = 0, sum = 0, n = s.size(); i < n; ++i) {
            sum = (sum * 2 + s[i] - '0') & mask;
            if (i >= k-1) {
                size -= contains[sum] == 0;
                contains[sum] = true;
            }
        }

        return !size;
    }
};