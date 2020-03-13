class Solution {
private:
    unordered_map<unsigned int, bool> dp;
    
    unsigned int selectNum(unsigned int state, int n) {
        return state | (1 << (n-1));
    }
    
    bool isSelected(unsigned int state, int n) {
        return (state >> (n-1)) & 1;
    }
    
    bool canIWinHelper(int maxChoosableInteger, int desiredTotal, int total, unsigned int state) {
        if (total >= desiredTotal) {
            return false;
        } else if (dp.find(state) != dp.end()) {
            return dp.at(state);
        }
        
        bool res = false;
        for (int n = 1; n <= maxChoosableInteger && !res; ++n) {
            if (isSelected(state, n)) {
                continue;
            }
            
            if (!canIWinHelper(maxChoosableInteger, desiredTotal, total + n, selectNum(state, n))) {
                res = true;
            }
        }
        
        dp[state] = res;
        return res;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal == 0) {
            return true;
        } else if ((maxChoosableInteger * (maxChoosableInteger+1))/2 < desiredTotal) {
            return false;
        }
        
        dp.clear();
        
        return canIWinHelper(maxChoosableInteger, desiredTotal, 0, 0);
    }
};
