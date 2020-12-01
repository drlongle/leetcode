class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders)
    {
        long long int res = 0;
        int mod = 1e9 + 7;
        map<int, int> freq;
        for (int i = 0; i < inventory.size(); i++)
            freq[inventory[i]]++;

        auto iter = freq.rbegin();
        while(orders && iter != freq.rend())
        {
            int cnt = iter->second;
            long long int curr = iter->first;
            iter++;
            int top = iter == freq.rend() ? 0 : iter->first;

            if (orders >= (curr - top) * cnt)
            {
                res = (res + cnt * (curr + top + 1) * (curr - top) / 2) % mod;
                orders -= (curr - top) * cnt;
                iter->second += cnt;
            }
            else
            {
                int trancs = orders / cnt;
                int remain = orders % cnt;
                res = (res + cnt * (curr + curr - trancs + 1) * trancs / 2) % mod;
                res = (res + remain * (curr - trancs)) % mod;
                orders = 0;
            }
        }

        return res;
    }
};
