class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        int score = 0;

        for(char c : S)
        {
            if(c == '('){
                st.push(score);
                score = 0;
            }
            else {
                score = st.top() + max(score * 2, 1);
                st.pop();
            }
        }
        return score;
    }
};
