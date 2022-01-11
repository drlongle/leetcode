class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> dirs;
        sort(folder.begin(), folder.end());
        for (auto &dir : folder) {
            bool isSub = false;
            string t = "";
            for (auto &c : dir) {
                if (c=='/' && t.size()) {
                    if (dirs.find(t) != dirs.end()) {
                        isSub = true;
                        break;
                    }
                }
                t += c;
            }
            if (!isSub)
                dirs.insert(dir);
        }
        
        vector<string> ans;
        for (auto &p : dirs)
            ans.push_back(p);
        
        return ans;
    }
};
