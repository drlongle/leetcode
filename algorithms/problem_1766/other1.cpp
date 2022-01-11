/*
This is a good case to demonstrate why reading the constraints section is crucial.
Here we can only have up to 50 different numbers.

So, we need to write our code in a way that we do not check more that 50 ancestors
for each node. Or else - TLE.

1. First, we collect all unique numbers in our tree.
2. Then, for each number, we save all of its co-primes into cops.
3. Now, it's a simple tree traversal (be sure to pass the parent so you won't go back).
- For each value n[i], we enumerate all of its co-primes, and check if a cop is within our ancestors.
- If it is - pick the most recent ancestor, and get its level and index.
- Assign the index of the closest ancestor (by tracking the highest level) to the result.
- Add {level, i} to the list of ancestors for value n[i].
- Traverse children (do not go back to parent).
- Remove last ancestor for value n[i].
*/

class Solution {
public:

    unordered_map<int, vector<int>> cops;
    unordered_map<int, vector<pair<int, int>>> ancestors;

    void traverse(vector<int>& n, vector<vector<int>> &al, int i, int parent, int level, vector<int> &res) {
        int max_level = -1;
        for (auto cop : cops[n[i]]) {
            auto &v = ancestors[cop];
            if (!v.empty() && v.back().first > max_level) {
                max_level = v.back().first;
                res[i] = v.back().second;
            }
        }
        ancestors[n[i]].push_back({level, i});
        for (auto child : al[i])
            if (child != parent)
                traverse(n, al, child, i, level + 1, res);
        ancestors[n[i]].pop_back();
    }

    vector<int> getCoprimes(vector<int>& n, vector<vector<int>>& edges) {
        unordered_set<int> s(begin(n), end(n));
        for (auto n1 : s) {
            for (auto n2 : s)
                if (__gcd(n1, n2) == 1)
                    cops[n1].push_back(n2);
        }
        vector<vector<int>> al(n.size());
        vector<int> res(n.size(), -1);
        for (auto &e : edges) {
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }
        traverse(n, al, 0, 0, 0, res);
        return res;
    }
};
