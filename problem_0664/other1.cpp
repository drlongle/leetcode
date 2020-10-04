class Solution {
public:
    int dp[100][100] = {0};
    int find(string & s, int l , int r){
        if(l>r) return 0;

        int & ans = dp[l][r];
        if(ans!=0) return ans;

        ans = 1+ find(s, l+1 ,r);

        for(int k = l+1; k<=r;k++){
            if(s[k] == s[l]){
                ans = min(ans, find(s, l+1, k) + find(s,k+1,r ));
            }
        }

        return ans;
    }

    int strangePrinter(string s) {
        return find(s, 0,s.size()-1);
    }
};
