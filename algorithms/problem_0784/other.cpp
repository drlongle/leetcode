class Solution {
public:
    vector<string> letterCasePermutation(string S){
        vector<string> answer;
        answer.push_back("");

        for(int i = 0 ; i < S.size(); i++)
            if(S[i] >= '0' && S[i] <= '9')                                           //if we have number
                for(int j = 0; j < answer.size(); j++) answer[j] += S[i];
            else{
                string c;                                                     //if we have character
                if(S[i] >= 'a') c = S[i] - 32;
                else c = S[i] + 32;

                int n = answer.size();
                for(int j = 0; j < n; j++){
                    string tmp = answer[j] + c;                       //construct with character
                    answer[j] += S[i];                                //put into with original character
                    answer.push_back(tmp);                            //put into with changable character
                }
            }
        return answer;
    }
};
