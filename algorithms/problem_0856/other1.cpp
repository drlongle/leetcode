class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        int score = 0;
        for(int i=0; i < S.length(); i++){
            if(S[i] == '('){
                // push whatever score we previously had
                s.push(score);
                // we are starting new pair so score is 0;
                score = 0;
            }else{
                // previous score [s.top()]
                score = s.top() + max(score*2 , 1);
                s.pop();
            }
        }
        return score;
    }
};
