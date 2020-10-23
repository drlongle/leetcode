class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        queue <string> que;
        que.push(s);
        string ans = s;
        visited.insert(s);
        while(!que.empty()){
            string frt = que.front();
            if(ans> frt) ans = frt;
            que.pop();
            vector <string> tmp = both(frt,a,b);
            if(visited.find(tmp[0]) == visited.end()){
                visited.insert(tmp[0]);
                que.push(tmp[0]);
            }
            if(visited.find(tmp[1]) == visited.end()){
                visited.insert(tmp[1]);
                que.push(tmp[1]);
            }
        }
        return ans;
    }
    vector <string> both(string s,int &a,int &b){
        vector <string> res (2,s);
        for(int i =1; i < s.length(); i+=2){
            int num = res[0][i]-'0';
            num += a;
            num %= 10;
            res[0][i] = '0'+num;
        }
        res[1] = s.substr(s.length()-b,s.length())+s.substr(0,s.length()-b);
        return res;
    }
};
