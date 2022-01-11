class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); // for easy lookup
        unordered_map<size_t, vector<string>> cache; // memoization cache
        cache[ s.length() ] = { "" }; // base case
        return wordBreak(s, dict, 0UL, cache);
    }
    
    vector<string> wordBreak(string& s, unordered_set<string>& dict, size_t index, unordered_map<size_t, vector<string>>& cache) {        
        vector<string> out;
        for (size_t i = index; i < s.length(); ++i) {
            string sub = s.substr(index, i - index + 1);
            if (dict.find(sub) != dict.end()) {
                bool found = (cache.find(i+1) != cache.end());
                vector<string>& result = cache[i+1];
                if (!found) {
                    result = wordBreak(s, dict, i+1, cache);
                }
                
                for (string& subsub : result) {
                    out.emplace_back(sub + (subsub.length() ? (string(" ") + subsub) : ""));
                }
            }
        }
        return out; 
    }
};

