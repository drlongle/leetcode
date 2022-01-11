class Solution {
public:
    int numDifferentIntegers(string s) {
        // REVERSING STRING SIMPLIFIES PROBLEM OF LEADING ZEROES
        reverse(s.begin(), s.end());

        for(auto&c: s) {
            if(isdigit(c)) continue;
            c = ' ';
        }

        stringstream ss;
        ss << s;
        string word;
        unordered_set<string> st;

        // STORE THE WORDS IN HASH MAP, AFTER REMOVING LEADING ZEROES
        while(ss >> word) {
            while(word.length() > 1 && word.back() == '0') {
                word.pop_back();
            }
            st.insert(word);
        }

        return st.size();
    }
};
