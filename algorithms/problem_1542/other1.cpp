class Solution {
public:
    int longestAwesome(string s) {
        int curr = 0;
        unordered_map<int, int> processed;
        processed.reserve(size(s));
        int ans = 0;
        for (int i = 0; i < size(s); ++i) {
            curr ^=  1 << (s[i] - '0');
            for (int j = -1; j < 10; ++j) {
                int search_value = j >= 0 ? (1 << j) : 0; // j = -1 means that no bits are set
                if (curr == search_value) {
                    ans = i + 1;
                }
                else {
                    if (auto it = processed.find(curr ^ search_value); it != cend(processed))
                        ans = max(ans, i - it->second);
                }
            }
            processed.emplace(curr, i);
        }
        return ans;
    }
};