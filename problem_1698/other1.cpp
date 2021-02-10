// Prefix trie

class Solution {
public:
    int countDistinct(string s) {
        v.reserve(1000000);
        v.push_back(Node());
        for(int i=0;i<s.size();i++) add(s, i);
        return v.size()-1;
    }

    void add(const string& s, int i){
        auto p = &v[0];
        for(; i<s.size();i++){
            int j = s[i]-'a';
            if(!p->child[j]) {
                v.push_back(Node());
                p->child[j] = &(v.back());
            }
            p = p->child[j];
        }
    }

    struct Node{
        array<Node*, 26> child = {};
    };

    vector<Node> v;
};
