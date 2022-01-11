class Solution {
public:
    int compress(vector<char>& chars)
    {
        int i = 0;
        while (i < chars.size()) {
            int j = i;
            while (j < chars.size() && chars[j] == chars[i]) {
                ++j;
            }
            if (j == i + 1) {
                ++i;
            } else {
                // ["a","a","b","b","c","c","c"]
                //           i  i+1  j
                // ["a","a","b","b","c","c","c"]
                // ["a","a","b","2", c","c","c"]
                //           i     i+step+1
                chars.erase(chars.begin() + i + 1, chars.begin() + j);
                int step = 0, ctr = j - i;
                while (ctr != 0) {
                    chars.insert(chars.begin() + i + 1, '0' + ctr % 10);
                    ctr /= 10;
                    ++step;
                }
                i += step + 1;
            }
        }
        return chars.size();
    }
};
