class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0, right = removable.size(), mid;
        while (left < right){
            mid = (left + right) / 2;
            if (isSub(s, p, removable, mid))
                left = mid + 1;
            else
                right = mid;
        }
        if (!isSub(s, p, removable, left)) --left;
        return left;
    }

    bool isSub(string s, string p, vector<int>& removeable, int m){
        int j = 0, n1 = s.length(), n2 = p.length();
        for (int k = 0; k < m; ++k)
            s[removeable[k]] = '#';
        for (int i = 0; i < n1; ++i){
            if (s[i] == p[j]){
                ++j;
                if (j == n2) return true;
            }
        }
        return false;
    }
};
