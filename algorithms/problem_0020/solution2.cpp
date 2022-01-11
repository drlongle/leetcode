class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_set<char> open{'(','[','{'};
        unordered_map<char, char> close{{')', '('},
                                        {']', '['},
                                        {'}', '{'}};
        for (char c: s) {
            if (open.count(c))
                st.emplace(c);
            else {
                auto it = close.find(c);
                if (st.empty() || st.top() != it->second)
                return false;
            else
                st.pop();
            }
        }
        
        return st.empty();
    }
};
