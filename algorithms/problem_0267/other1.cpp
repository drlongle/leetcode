class Solution {
public:
    void dfs(string &pallin,const char &odd_char,vector<string> &answer,const int &len,vector<bool> &visited,const string &find_chars){
        if(pallin.length()==len){
            string temp=pallin;
            reverse(temp.begin(),temp.end());
            if(odd_char!='#'){
                answer.push_back(pallin+odd_char+temp);
            }
            else answer.push_back(pallin+temp);
            return;
        }
        for(int i=0;i<len;i++){
            if(visited[i]) continue;
            if(i && find_chars[i]==find_chars[i-1] && !visited[i-1]) continue;
            pallin+=find_chars[i];
            visited[i]=true;
            dfs(pallin,odd_char,answer,len,visited,find_chars);
            pallin.pop_back();
            visited[i]=false;
        }
    }
    vector<string> generatePalindromes(string s) {
        unordered_map<char,int> freq;
        for(auto i:s){
            freq[i]++;
        }
        char odd_char='#';
        string find_chars="";
        for(auto i:freq){
            if(i.second%2) {
                if(odd_char!='#') return {};
                odd_char=i.first;
            }
            string temp(i.second/2,i.first);
            find_chars+=temp;
        }
        int len=find_chars.length();
        vector<string> answer;
        vector<bool> visited(len,false);
        string pallin="";
        dfs(pallin,odd_char,answer,len,visited,find_chars);
        return answer;
    }
};
