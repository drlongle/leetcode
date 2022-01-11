vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return ans;
        vector<string> visited; //record visited words  
        queue<vector<string>> q;  q.push({beginWord});
        while(!q.empty()){
           int n = q.size();
           for(int i = 0 ; i < n; ++i){
               auto cur=q.front(); q.pop();
               auto s = cur.back();
              
               for(auto& c : s){
                   const char origin = c;                  
                   for(c='a'; c<='z'; ++c){  
                       if(!dict.count(s)) continue;
                       auto path = cur; 
                       path.push_back(s); 
                       visited.push_back(s); 
                       if(s==endWord) ans.push_back(path);
                       else q.push(path);
                   }
                
                   c = origin;
               }
               
           }
            
           for(auto& w : visited) dict.erase(w);//erase visited
           visited.clear();
            
        }
        return ans; 
      
    }
