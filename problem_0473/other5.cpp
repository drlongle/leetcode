class Solution {// Solution: DFS with sort-aided pruning
public: // Time/Space: O(4^N); O(N)
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4 ) return false;
        int tot = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(tot % 4 != 0) return false;
        int sums[4]={};
        sort(matchsticks.rbegin(), matchsticks.rend());
        return helper(matchsticks, 0, sums, tot/4);
    }

private:
    bool helper(vector<int>& matchsticks, int pos, int sums[], int len){
        if(pos >= matchsticks.size())
            return sums[0] == len && sums[1] == len && sums[2] == len;
        for(int i = 0; i < 4; i++){
            if(sums[i] + matchsticks[pos] > len) continue;
            sums[i] += matchsticks[pos];
            if(helper(matchsticks, pos + 1, sums, len)) return true;
            sums[i] -= matchsticks[pos];
        }
        return false;
    }
};
