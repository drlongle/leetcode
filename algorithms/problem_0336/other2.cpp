class Solution {
public:
    long int pre[5001]={}, suf[5001]={}, p[301]={}, X = 1000000007, Y = 998244353, len[5001]={};

    void init(vector<string>& words){

        int n = words.size();
        p[0]=1;
        for(int i=1;i<=300;i++){
            p[i] = (p[i-1]*Y)%X;
        }

        for(int i=0;i<n;i++){
            len[i] = words[i].size();
            for(int j=0;j<len[i];j++){
                pre[i] = (pre[i] + (words[i][j]*p[j])%X)%X;
                suf[i] = (suf[i] + (words[i][j]*p[len[i]-1-j])%X)%X;
            }
        }
    }

    bool isPalindrome(int a,int b){

        long int x = (pre[a] + (p[len[a]]*pre[b])%X)%X;
        long int y = (suf[b] + (p[len[b]]*suf[a])%X)%X;;

        return (x==y) ;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {

        init(words);
        vector<vector<int>> ans;

        int n = words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isPalindrome(i,j)){
                    vector<int> temp = {i,j};
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};
