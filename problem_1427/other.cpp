class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int cnt = 0; // count left shift
        for (auto&vi: shift) cnt += (vi[0] ? -vi[1] : vi[1]);
        cnt %= int(s.size());
        if (cnt > 0) {
            rotate(s.begin(), next(s.begin(), cnt), s.end());
        } else {
            rotate(s.rbegin(), next(s.rbegin(), -cnt), s.rend());
        }
        return s;
    }
};
