class Solution {
  public:
    int dfs(int curNode, unordered_map<int, vector<int>> &nodeMap, string &s,
            int &maxLen) {
        if (!nodeMap.count(curNode))
            return 1;
        // figure out top return lens
        priority_queue<int, vector<int>, greater<int>> nodepq;
        for (int i : nodeMap[curNode]) {
            int childMax = dfs(i, nodeMap, s, maxLen);
            if (s[i] != s[curNode]) {
                nodepq.push(childMax);
            }
            if (nodepq.size() > 2) {
                nodepq.pop();
            }
        }
        if (nodepq.size() == 1) {
            // if pq left with one element
            maxLen = max(maxLen, nodepq.top() + 1);
            return nodepq.top() + 1;
        } else if (nodepq.size() == 2) {
            //
            int secondMax = nodepq.top();
            nodepq.pop();
            int firstMax = nodepq.top();
            maxLen = max(maxLen, firstMax + secondMax + 1);
            return firstMax + 1;
        } else {
            return 1;
        }
    }
    int longestPath(vector<int> &parent, string s) {
        unordered_map<int, vector<int>> nodeMap;
        for (int i = 1; i < parent.size(); ++i) {
            nodeMap[parent[i]].push_back(i);
        }
        int maxLen = 1;
        int tmp = dfs(0, nodeMap, s, maxLen);
        return maxLen;
    }
};
