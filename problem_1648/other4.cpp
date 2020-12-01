class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        inventory.push_back(0);
        std::sort(inventory.begin(),inventory.end(),std::greater<int>());
        long long res = 0, mod = 1000000007, cnt = 0;
        for(long long i=1;i<inventory.size();++i){
            long long delta = inventory[i-1]-inventory[i];
            if(cnt + i * delta < orders) {
                res += i * ((1LL+inventory[i-1]+inventory[i])*delta/2%mod) % mod;
                cnt += i * delta;
            } else {
                long long a1 = (orders-cnt)/i, a2 = (orders-cnt)%i;
                res += i*(2LL*inventory[i-1]+1-a1)*a1/2%mod + a2*(inventory[i-1]-a1)%mod;
                return res%mod;
            }
        }
        return res%mod;
    }
};
