class Solution {
public:
    int s, n;
    vector<int> sum;

    bool helper(vector<int>& m, int id, int k){
        if(k == n)
            if(sum[0] == sum[1] && sum[1] == sum[2] && sum[2] == sum[3]) return true;
            else return false;

        for(int i = 0; i != 4; i++)
            if(sum[i] + m[id] <= s) {
                sum[i] += m[id];
                if(helper(m, id-1, k+1)) return true;
                sum[i] -= m[id];
            }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(),matchsticks.end());
        n = matchsticks.size();
        s = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(s%4 != 0 || s == 0 ) return false;
        s = s>>2;
        if(matchsticks.back() > s) return false;

        sum.resize(4,0);
        return helper(matchsticks, n-1, 0);
    }
};
