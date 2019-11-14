class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> res{folder[0]};
        copy_if(folder.begin()+1 ,folder.end(), std::back_inserter(res),
                [&res](auto& f){return f.find(res.back()+"/")==string::npos; });
        return res;
    }
};
