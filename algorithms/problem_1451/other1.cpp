class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        stringstream ss(text), rs;
        string word;
        map<int, vector<string>> m;
        while (ss >> word) m[word.size()].emplace_back(word);

        for (const auto& count: m)
            for(const auto & word: count.second)
                rs << word << " ";
        string result = rs.str();
        result.pop_back();
        result[0] = toupper(result[0]);
        return result;
    }
};
