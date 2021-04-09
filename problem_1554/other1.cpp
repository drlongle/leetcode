class Solution {
public:
    bool differByOne(vector<string>& dict, unordered_set<string> st = {}) {
        for (string &s : dict) {
            for (char &c : s) {
                char orig = c;
                c = '*';
                if (st.count(s)) return true;
                st.insert(s);
                c = orig;
            }
        }
        return false;
    }
};
