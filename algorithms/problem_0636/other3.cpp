class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> s;
        stack<int> ss;
        vector<int> ans(n,0);

        for(string i:logs){
            int k=i.find(":");
            int j=i.find(":",k+1);
            if(i[k+1]=='s'){
                s.push(stoi(i.substr(j+1)));
                ss.push(stoi(i.substr(0,k)));
                continue;
            }
            int a = s.top();
            s.pop();
            ss.pop();
            ans[stoi(i.substr(0,k))]+=(int)stoi(i.substr(j+1))-a+1;
            if(!s.empty()){
                ans[ss.top()]-=(int)stoi(i.substr(j+1))-a+1;
            }
        }
        return ans;
    }
};
