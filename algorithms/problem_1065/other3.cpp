// Remember to set i to start + 1 after every search, either successfully or not.

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> res;
        for(string s : words){
            int i = 0, j, start, end;
            while(i < text.size()){
                j = 0;
                if(text[i] == s[j]){
                    start = i;
                    while(text[i] == s[j] && j < s.size()){
                        i++;
                        j++;
                    }
                    if(j >= s.size()){
                        end = i - 1;
                        res.push_back({start, end});
                    }
                    i = start + 1;
                }
                else
                    i++;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
