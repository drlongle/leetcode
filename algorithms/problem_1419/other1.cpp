class Solution {
public:
    int minNumberOfFrogs(const std::string& croakOfFrogs) {
        char prevMap[256];
        prevMap['c'] = 'k';
        prevMap['r'] = 'c';
        prevMap['o'] = 'r';
        prevMap['a'] = 'o';
        prevMap['k'] = 'a';
        int countMap[256] = {0};
        int ans = 0;
        int total = 0;
        for (char ch : croakOfFrogs) {
            char p = prevMap[ch];
            if (countMap[p] > 0) {
                countMap[p] --;
                total --;
            } else if (ch != 'c') {
                return -1;
            }
            countMap[ch] ++;
            total ++;

            ans = std::max(ans, total);
        }

        return croakOfFrogs.size() % 5 == 0 ? ans : -1;
    }
};
