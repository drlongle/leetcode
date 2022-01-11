class Solution {
public:
    int numDifferentIntegers(string word) {
        for_each(word.begin(),word.end(),[](char& c)->void{if (isalpha(c)) c = ' ';});
        unordered_set<string> s;
        istringstream iss(word);
        string w;
        while (iss >> w) {
            size_t i = w.find_first_not_of('0');
            string ss = (i == string::npos) ? "0": w.substr(i);
            s.insert(ss);
        }
        return s.size();
    }
};
