class Solution {
public:
    bool dfs(const string &s,const string &pattern,unordered_map<char,string> &track,
             unordered_set<string> &visited){
        if(!pattern.length() && s.length()) return false;
        if(!pattern.length()) return true;
        if(pattern.length()>s.length()) return false;
        if(track.find(pattern[0])!=track.end()){
            if(s.find(track[pattern[0]])==0)
                return dfs(s.substr(track[pattern[0]].length()),pattern.substr(1),track,visited);
            else return false;
        }
        for(int i=0;i<s.length();i++){
            string temp=s.substr(0,i+1);;
            if(visited.count(temp)) continue;
            track[pattern[0]]=temp;
            visited.insert(temp);
            if(dfs(s.substr(i+1),pattern.substr(1),track,visited)) return true;
            visited.erase(temp);
            track.erase(pattern[0]);
        }
        return false;
    }

    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char,string> track;
        unordered_set<string> visited;
        return dfs(s,pattern,track,visited);
    }

};
