class Solution {
    unordered_map<char, string> seen;   // char to string
    unordered_set<string> dict;         // all strings
public:
    bool wordPatternMatch(string pattern, string s) {
        return backtracking(pattern, 0, s, 0);
    }

    bool backtracking(string& p, int i, string& s, int j) {
        // Base case
        if (p.size() == i && s.size() == j) return true;
        else if (p.size() == i || s.size() == j) return false;

        char ch = p[i];

        if (seen.count(ch) > 0) {   // Already mapped
            int len = seen[ch].size();
            // Compare seen[ch] and s.substr
            if (j + len <= s.size() && seen[ch] == s.substr(j, len))
                if (backtracking(p, i+1, s, j + len)) return true;
        } else {                    // Not mapped
            // Try all substrings which are started at j
            for (int len = 1; j + len <= s.size(); len++) {
                // If substring already mapped, then skip
                if (dict.count(s.substr(j, len)) > 0) continue;
                seen.insert({ch, s.substr(j, len)}); dict.insert(seen[ch]);
                if (backtracking(p, i+1, s, j + len)) return true;
                dict.erase(seen[ch]); seen.erase(ch);
            }
        }
        return false;
    }
};
