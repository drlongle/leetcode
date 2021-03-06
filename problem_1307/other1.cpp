/*
Use dfs and backtracking to search from least important digits to most important digists, and iterate on each string. Record each mapping in map and used and backtrack if fail.
*/
class Solution {
    vector<vector<char>> lefts;
    vector<char> rights;
    unordered_map<char, int> map;
    unordered_set<int> used;
    bool check(int level, int idx, int sum) {
        // last check
        if (level >= rights.size()) {
            // check left length is larger than right
            if (level < lefts.size()) {
                return false;
            }
            // check leading zeros
            for (char ch : lefts.back()) {
                if (map[ch] == 0) {
                    return false;
                }
            }
            if (map[rights.back()] == 0) {
                return false;
            }
            return sum == 0;
        }
        //check equality at the end of each level, level < rights.size();
        if (level >= lefts.size() || idx >= lefts[level].size()) {
            char ch = rights[level];
            bool add = false;
            if (map.find(ch) == map.end()) {
                // try map right character
                if (used.count(sum % 10) > 0) {
                    return false;
                } else {
                    used.insert(sum % 10);
                    map[ch] = sum % 10;
                    add = true;
                }
            } else if (map[ch] != sum % 10) {
                return false;
            }
            if (check(level + 1, 0, sum / 10)) {
                return true;
            } else {
                if (add) {
                    // reset mapping
                    used.erase(sum % 10);
                    map.erase(ch);
                }
                return false;
            }
        }
        char ch = lefts[level][idx];
        if (map.find(ch) != map.end()) {
            // this left character is already mapped
            return check(level, idx + 1, sum + map[ch]);
        }
        for (int i = 0; i <= 9; i++) {
            // enumerate to map left character
            if (used.count(i) > 0) {
                continue;
            }
            map[ch] = i;
            used.insert(i);
            if (check(level, idx + 1, sum + i)) {
                return true;
            }
            map.erase(ch);
            used.erase(i);
        }
        return false;
    }
public:
    bool isSolvable(vector<string>& words, string result) {
        int levels = 0;
        for (const string &str : words) {
            levels = max(levels, (int)str.length());
        }
        for (int level = 0; level < levels; level++) {
            lefts.emplace_back();
            for (const string &str : words) {
                if (level < str.length()) {
                    lefts[level].push_back(str[str.length() - level - 1]);
                }
            }
        }
        for (int i = result.length() - 1; i >= 0; i--) {
            rights.push_back(result[i]);
        }
        return check(0, 0, 0);
    }
};
