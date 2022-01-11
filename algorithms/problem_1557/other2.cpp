/*
 * Basically find all the nodes with in-degree = 0. Because you can't get to these nodes from anywhere,
 * and once you have all of these you can visit the next level of nodes, and so on.
 */
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges)
    {
        unordered_map<int, int> indegrees;
        for (auto edge : edges)
            ++indegrees[edge[1]];

        vector<int> result;
        for (int i = 0; i < n; ++i)
            if (!indegrees[i])
                result.push_back(i);

        return result;
    }
};