class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        if(s.length() == 1){
            return 0;
        }
        int ans = 0, i = 1, mx = 0, n = s.length();
        while(i < n){
            int sum = 0;
            while(s[i] == s[i-1]){
                mx = max(mx,cost[i-1]);
                sum += cost[i-1];
                i++;
            }
            mx = max(mx, cost[i-1]);
            sum += cost[i-1];
            ans += (sum-mx);
            mx = 0;
            i++;
        }

        return ans;
    }
};
