class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {

        if(words1.size() != words2.size()) return false;

        int size{(int)pairs.size()}, i{0};
        std::unordered_map<string,int> m;
        for(const auto &n: pairs) {
            if(!m.count(n[0])) m[n[0]] = i++;
            if(!m.count(n[1])) m[n[1]] = i++;
        }

        int sizeW{(int)m.size()};
        std::vector<int> parent(sizeW, 0);
        for(int i{0}; i < sizeW; ++i) parent[i] = i;
        for(const auto &p: pairs) parent[getParent(parent, m[p[0]])] = getParent(parent, m[p[1]]);

        int sizeS{(int)words1.size()};
        for(int i{0}; i < sizeS; ++i) {
            if(words1[i] != words2[i]) {
                if(!m.count(words1[i]) || !m.count(words2[i])) return false;
                if(getParent(parent, m[words1[i]]) != getParent(parent, m[words2[i]])) return false;
            }
        }

        return true;
    }

    int getParent(std::vector<int>& parent, int i) {
        return parent[i] = parent[i] == i ? i : getParent(parent, parent[i]);
    }
};
