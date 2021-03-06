class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();

        if(n == 0){
            return 0;
        }

        int ones = 0; //number of consecutive ones
        int zeros = 0; //number of consecutive zeros
        int ans = 0;  //answer

        for(int i=0; i<n; i++){
            char c = s[i];

            if(c == '0'){
                zeros = 0;
                //count the number of zeros
                while(s[i] == '0'){
                    i++;
                    zeros++;
                }
                i--;
                //add the minimum of consecutive ones and zeros to the answer
                //like if we have 001111 then we'll add two because there are lesser number of zeros to match with
                ans += min(ones, zeros);
            }
                //the logic used for zero goes exactly the same way here
            else{
                ones = 0;
                while(s[i] == '1'){
                    ones++;
                    i++;
                }
                i--;
                ans += min(zeros, ones);
            }
        }

        return ans;
    }
};