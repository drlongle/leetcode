class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res = 0, cnt = 0, n = hours.size();
        for (int i = 0; i < n; ++i) {
            if (hours[i] > 8) ++cnt;
            if (cnt * 2 > i + 1) res = i + 1;
            int left = 0, curCnt = cnt;
            while (left < i && curCnt * 2 <= i - left + 1) {
                if (hours[left] > 8) --curCnt;
                ++left;
                if (curCnt * 2 > i - left + 1) res = max(res, i - left + 1);
            }
        }
        return res;
    }
};

