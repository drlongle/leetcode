class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, string> g;
        queue<pair<string, int>> q;
        set<string> wList(wordList.begin(), wordList.end());
        q.emplace(beginWord, 1);
        while (q.size()) {
            auto& e = q.front();
            auto& s = e.first;
            if (s == endWord)
                return e.second;
            for (size_t i = 0; i < s.size(); ++i) {
                auto t = e.first;
                for (int j = 0; j < 26; ++j) {
                    char ch = 'a' + j;
                    if (ch != s[i]) {
                        t[i] = ch;
                        auto it = wList.find(t);
                        if (it != wList.end()) {
                            wList.erase(it);
                            q.emplace(t, e.second + 1);
                        }
                    }
                }
            }
            q.pop();
        }
        
        return 0;
    }
};
