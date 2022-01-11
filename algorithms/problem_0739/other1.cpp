class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int>st; vector<int>res(T.size(),0);
        for(int i=T.size()-1 ; i>=0 ; i--)
        {
            while(!st.empty() and T[st.top()]<=T[i]) st.pop();
            res[i]=(st.empty()?0:st.top()-i);
            st.push(i);
        }
        return res;
    }
};
