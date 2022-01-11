class Solution {
public:
    int scoreOfParentheses(string S) {
        int x = 1;
        int n = S.size();
        int result = 0;

        for(int i = 1; i < n; ++i){
            switch (S[i])
            {
                case ')':
                    if(S[i-1] == '('){
                        result += (1 << (x-1));
                    }
                    --x;
                    break;
                default:
                    ++x;
                    break;
            }
        }

        return result;
    }
};
