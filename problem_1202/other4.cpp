class Solution {
public:
    int find(vector<int>& parents, int p) {
        if (p != parents[p]) {
            parents[p] = find(parents, parents[p]);
        }
        return parents[p];
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // pairs can be connected to group of indices so that we can sort chars of s in each group separately to smallest
        // sub-string and connect them together as the return.
        // [0,3] [1,2] can form two groups, so "dcab" can be sorted separately like b..d and ac, then bacd.
        // [0,3] [1,2] [0,2] can be connected to a single group 0,1,2,3, so we can sort s as one string
        std::unordered_map<int, vector<int>> posGroups;
        std::unordered_map<int, string> groupStrs;
        int n = s.size();
        std::vector<int> parents(n, 0);
        for(int i = 0; i < n; i++) {
            parents[i] = i;
        }
        
        for (const auto& p: pairs) {
            int p0 = find(parents, p[0]);
            int p1 = find(parents, p[1]);
            parents[p1] = p0;
        }
        for (int i = 0; i < n; i++) {
            int p = find(parents, parents[i]);
            posGroups[p].emplace_back(i);
            groupStrs[p].push_back(s[i]);
        }
        for (const auto& it: posGroups) {
            const auto& g = it.second;
            string& str = groupStrs[it.first];
            sort(str.begin(), str.end());
            int i = 0;
            for (const auto& p: g) {
                s[p] = str[i++];
            }
        }
        return s;
    }
};
