class Solution {
  public:
    int DFS(vector<vector<int>> &children, string &s, int &ans, int curr_node) {
        int big_1 = 0, big_2 = 0;
        for (int j : children[curr_node]) {
            int cur_len = DFS(children, s, ans, j);
            if (s[curr_node] == s[j])
                continue;
            if (cur_len > big_2)
                big_2 = cur_len;
            if (big_2 > big_1)
                swap(big_2, big_1);
        }
        ans = max(ans, big_1 + big_2 + 1);
        return big_1 + 1;
    }
    int longestPath(vector<int> &parent, string s) {
        int n = parent.size();
        int ans = 0;
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) // left 0 as 0 doesnt have any parent
            children[parent[i]].push_back(i);
        DFS(children, s, ans, 0);
        return ans;
    }
};
