class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() < 2) return false;
        map<int, int> cnt;

        for (int i : deck) 
            cnt[i]++;
    
        auto it = cnt.rbegin(); // reverse order iterator
    
        int minSize = INT_MAX;
        while (it != cnt.rend()) {
            if (it->second < 2)
                return false;
            minSize = min(minSize, it->second);
            it++;
        }
        // brute force search if every group has the same divisor
        for (int i = 2; i <= minSize; i++) {
            it = cnt.rbegin();
            int c = 0;
            while(it != cnt.rend()) {
                if (it->second % i == 0)
                    c++;
                it++;
            }
            if (c == cnt.size())
                return true;
        }
        return false;
    }
};
