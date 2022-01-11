class Solution {
public:
    int numSub(string s) {
        long long ans = 0,sz = 0;
        for(int i=0;i<s.length();i++){
            while(i<s.length()&&s[i]=='1')
                    sz++,i++;
            ans +=((sz*(sz+1))/2)%1000000007;
            sz = 0;
        }
        return ans;
    }
};
