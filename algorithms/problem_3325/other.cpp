int numberOfSubstrings(string s, int k) {
        int n = s.length(), res = (n + 1) * n / 2;
        unordered_map<char, int> count;
        for (int i = 0, j = 0; j < n; j++) {
            count[s[j]]++;
            while (count[s[j]] >= k)
                --count[s[i++]];
            res -= j - i + 1;
        }
        return res;
    }

