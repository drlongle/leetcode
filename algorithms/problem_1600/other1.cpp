class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }

    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);
    }
    void death(string name) {
        dead.insert(name);
    }

    vector<string> getInheritanceOrder() {
        vector<string> res;
        successor(king,res);
        return res;
    }
private:
    string king;
    unordered_map<string, vector<string>> mp;
    unordered_set<string> dead;

    void successor(string parent, vector<string>&res)
    {
        if(dead.find(parent)==dead.end())
            res.push_back(parent);

        vector<string> children = mp[parent];
        for(auto child:children)
            successor(child,res);
    }
};
