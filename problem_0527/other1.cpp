class Solution {
    template<typename T>
    using adjacency_list = unordered_map<T, vector<T>>;
    using hashmap = unordered_map<string, int>;

    vector<string> answer;
    hashmap index;
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        answer.resize(dict.size());
        for (int i=0; i<dict.size(); i++) index[dict[i]] = i;
        abbreviateAll(dict, 1);
        return answer;
    }

    string abbreviation(string word, int prefixSize) {  // computes the actual abbreviation of a word.
        int n = word.size();
        if (n - prefixSize < 3) {
            return word;
        }
        return word.substr(0, prefixSize) + to_string(n-prefixSize-1) + word.back();
    }

    void abbreviateAll(vector<string>& dict, int prefixSize) { // manages to find abbreviations without conflicts.
        adjacency_list<string> group; // hashmap with key=string, value=array of strings.
        for (auto &word: dict) {
            group[abbreviation(word, prefixSize)].push_back(word);
        }
        for (auto &keyVal: group) {
            if (keyVal.second.size() == 1) {
                answer[index[keyVal.second[0]]] = keyVal.first;
            } else {
                abbreviateAll(keyVal.second, prefixSize + 1);
            }
        }
    }
};
