class Solution {
public:
    unordered_map<int, unordered_set<int>> out, in;
    int ans = 0;
    
    void dfs(int node) {
        ans += out[node].size(); // All these edges must be reversed.
        for (int x: out[node]) {
            // node -> x edge was present which we are going to remove. So remove entry from in[x] of "node".
            in[x].erase(node); // edge is reversed. 
            dfs(x); // recursive call to make sure all edges connected to x are coming into x instead of going out.
        }
        for (int x:in[node]) {
            out[x].erase(node); // to avoid visiting the same node again, remove the entry from out[x] of the "node".
            dfs(x); // recursive call to make sure all edges connected to x are coming into x instead of going out.
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        ans = 0;
		// make graphs out and in.
        for (auto x: connections) {
            out[x[0]].insert(x[1]);
            in[x[1]].insert(x[0]);
        }
        dfs(0); // start with 0 because we are certain that we will have to reverse the outgoing edges of 0. 
                // We cannot say the same about other nodes
        return ans;
    }
};
