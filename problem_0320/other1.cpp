class Solution {
public:
    void dfs(int start,string curr,vector<string> &answer,const int &n,const string &word){
        if(start==n) {
            answer.push_back(curr);
            return;
        }
        int curr_len=curr.length();
        for(int i=0;i<=n-start;i++){
            if(i && curr_len && isdigit(curr[curr_len-1])) continue;
            if(!i || (curr_len && isdigit(curr[curr_len-1]))){
                curr+=word[start];
                dfs(start+1,curr,answer,n,word);
                curr.pop_back();
            }
            else{
                string temp=to_string(i);
                curr+=temp;
                dfs(start+i,curr,answer,n,word);
                for(int j=0;j<temp.length();j++) curr.pop_back();
            }
        }
    }

    vector<string> generateAbbreviations(string word) {
        vector<string> answer;
        int n=word.length();
        dfs(0,"",answer,n,word);
        return answer;
    }
};
