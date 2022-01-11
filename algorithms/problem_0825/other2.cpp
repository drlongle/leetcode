class Solution {
public:
    bool check(int a, int b) {
        return !((b <= 0.5 * a + 7) || (b > a) || (b > 100 && a < 100));
    }
    int numFriendRequests(vector<int>& ages) {
        vector<int> mp(121);
        for (auto& a : ages) mp[a]++;
        int res = 0;
        for (int i = 1; i < mp.size(); i++) {
            if (check(i, i)) res += mp[i] * (mp[i] - 1);
            for (int j = 1; j < i; j++)
                if (check(i, j)) res += mp[i] * mp[j];
        }
        return res;
    }
};
