class Solution {
public:
    vector<int> findBuildings(vector<int>& hs) {
        vector<int> st;
        for (int i = 0; i < hs.size(); ++i) {
            while (!st.empty() && hs[st.back()] <= hs[i])
                st.pop_back();
            st.push_back(i);
        }
        return st;
    }
};
