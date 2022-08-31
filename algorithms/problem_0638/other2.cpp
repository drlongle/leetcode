class Solution {
  public:
    map<vector<int>, int> mp;
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special,
                       vector<int> &need) {
        if (mp.count(need))
            return mp[need];
        int ans = without(price, need);
        for (auto &a : special) {
            vector<int> temp = need;
            bool flag = false;
            for (int i = 0; i < need.size(); i++) {
                temp[i] -= a[i];
                if (temp[i] < 0) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                continue;
            ans = min(ans, a.back() + shoppingOffers(price, special, temp));
        }
        return mp[need] = ans;
    }

    int without(vector<int> &price, vector<int> &need) {
        int sum = 0;
        for (int i = 0; i < price.size(); i++)
            sum += (price[i] * need[i]);
        return sum;
    }
};
