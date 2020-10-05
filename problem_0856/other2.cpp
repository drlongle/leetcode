class Solution {
public:
    int helper(string &S, int lo, int hi) {
        stack<int> st;
        int res = 0;
        for (int i = lo; i <= hi; i++) {
            if (S[i] == ')') {
                if (st.size() == 1) {
                    if (st.top() + 1 == i) res += 1;
                    else res += 2 * helper(S, st.top() + 1, i - 1);
                }
                st.pop();
            }
            else st.push(i);
        }
        return res;
    }
    int scoreOfParentheses(string S) {
        return helper(S, 0, S.size() - 1);
    }
};
