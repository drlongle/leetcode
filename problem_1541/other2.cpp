class Solution {
public:
    int minInsertions(string s) {
        stack<char> v;
        int ans = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == '(') v.push(s[i]);
            else{
                if(s[i + 1] == ')') {
                    if(!v.empty())
                        v.pop();
                    else ans++;
                    i++;       // because we considered i+1 in this case
                }
                else {
                    if(!v.empty()){
                        v.pop();
                        ans++;
                    }
                    else ans += 2;
                }
            }
        }

        return v.size()*2 + ans;
    }
};
