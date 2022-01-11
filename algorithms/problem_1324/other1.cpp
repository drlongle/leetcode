class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string>ans;
        int i=0;
        for(auto c:s){
            if(c!=' '){
                if(ans.size()<=i){
                    ans.push_back("");
                }
                if(i>0&&ans[i].size()<ans[i-1].size()-1){
                    ans[i].append(ans[i-1].size()-1-ans[i].size(),' ');
                }
                ans[i].push_back(c);
                i++;
            }else{
                i=0;
            }
        }
        return ans;
    }
};
