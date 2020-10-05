class ThroneInheritance {
public:
    unordered_map<string, vector<string>> adj;
    unordered_set<string> set;
    string root;
    ThroneInheritance(string kingName) {
        root = kingName;
    }

    void birth(string parentName, string childName) {
        adj[parentName].push_back(childName);
    }

    void death(string name) {
        set.insert(name);
    }

    vector<string> getInheritanceOrder() {
        vector<string> res;
        if(set.find(root) == set.end()) res.push_back(root);
        dfs(root, res);
        return res;
    }
    void dfs(string root, vector<string>& res) {
        if(adj.find(root) == adj.end()) return;
        vector<string> childList = adj.find(root)->second;
        for(auto r:childList) {
            if(set.find(r) == set.end()) { // dead person
                res.push_back(r);
            }
            dfs(r, res);
        }
    }
};
