class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int start = 0, end = 0;
        vector<vector<int>> ans;
        char ch;
        while(end < s.size()){
            ch = s[start];
            end = start;
            while(end < s.size() && ch == s[end]){
                end++;
            }
            if(end-start >= 3)
                ans.push_back({start, end-1});
            start = end;
        }
        return ans;
    }
};
