class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        // sort , slidling window
        if(tokens.size() == 0){
            return 0;
        }

        if(tokens.size() == 1){
            return P>tokens[0]? 1:0;
        }

        sort(tokens.begin(), tokens.end());

        int result = 0;
        int i = 0;
        int j = tokens.size()-1;
        while(i <= j){
            if(P < tokens[i]){
                return result;
            }
            while(P>=tokens[i] && i <= j){
                P -= tokens[i];
                result++;
                i++;
            }

            if(result > 0 && i < j){
                P+= tokens[j];
                j--;
                result--;
            }
        }

        return result;
    }
};
