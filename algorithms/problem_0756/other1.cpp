class Solution {
public:
    unordered_map<string, vector<char>> mp;

    bool helper(int level, int idx, string &temp, string &bottom){
        if(level == 1 && idx == 1) return true;

        if(level == idx){
            string p = "";
            return helper(level-1, 0, p, temp);
        }

        string s = bottom.substr(idx, 2);

        if(mp.count(s) == 0) return false;

        for(int i=0;i<mp[s].size();i++){
            temp.push_back(mp[s][i]);
            if(helper(level, idx+1, temp, bottom)) return true;
            temp.pop_back();
        }

        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        mp.clear();

        for(string s:allowed){
            mp[s.substr(0,2)].push_back(s[2]);
        }

        string temp = "";

        return helper(bottom.size()-1, 0, temp, bottom);

    }
};
