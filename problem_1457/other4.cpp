class Solution {// DFS + odd frequency count
public: // Time/Space: O(N); O(N)
    int pseudoPalindromicPaths (TreeNode* root) {        
        vector<int> pathCnt(9);        
        return dfs(root, pathCnt);
    }
    
private:
    int dfs(TreeNode* root, vector<int> pathCnt) {
        int ans = 0;
        if(!root) return 0;        
        ++pathCnt[root->val - 1];        
        if(!root->left && !root->right)  //if at most 1 element of pathCnt shows up in current path, it can be palindromic and return true(1), otherwise false(0)
            return count_if(begin(pathCnt), end(pathCnt), [](auto e){return e%2 == 1;}) <= 1;
        ans += dfs(root->left, pathCnt);
        ans += dfs(root->right, pathCnt);
        return ans;
    }
};
