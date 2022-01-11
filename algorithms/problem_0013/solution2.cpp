class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> table{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000},};
        int res = 0, prev = 0;
        for (char ch: s) {
            int curr = table[ch];
            if (prev && prev < curr) {
                res -= 2 * prev;
            }
            res += curr;
            prev = curr;
        }
        return res;
    }
};