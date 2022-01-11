class Solution {
public:

    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char,string>link;
        unordered_set<string>visited;
        return dfs(pattern,s,0,0,link,visited);
    }

    bool dfs(string key, string str, int i, int j, unordered_map<char,string>&link,
             unordered_set<string>&visited){

        /*
            two cases:
                mapped, need to check such substring match
                not mapped, assign any size of substring

        */

        if(i == key.length() && j == str.length()) return true;
        if(i == key.length() || j == str.length()) return false;

        if(link.count(key[i])){
            string map = link[key[i]];
            int x = 0;
            for(x = 0; x < map.length(); ++x){
                if(map[x]!=str[j+x]) return false;
            }
            if(x != map.length()) return false;

            return dfs(key,str,i+1,j+x,link,visited);
        }else{
            for(int x = 1; j+x <= str.length(); ++x){
                string map = str.substr(j,x);
                if(visited.count(map)) continue;
                link[key[i]] = map;
                visited.insert(map);

                if(dfs(key,str,i+1,j+x,link,visited)) return true;
                link.erase(key[i]);
                visited.erase(map);
            }
        }
        return false;

    }
};
