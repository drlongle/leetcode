class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int n = S.size();
        long long int size = 0;
        for(int i = 0 ; i < n ; i++){
            if(isalpha(S[i])) size++;
            else size = size * (int(S[i]) - 48);
        }
        string ans = "";
        for(int i = n - 1 ; i >= 0 ; i--){
            K = K % size;
            if(K == 0 and isalpha(S[i])){
                ans += S[i];
                break;
            }
            if(!isalpha(S[i]))
                size = size / (int(S[i]) - 48);
            else
                size--;
        }
        return ans;
    }
};
