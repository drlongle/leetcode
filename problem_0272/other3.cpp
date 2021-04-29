class Solution {
    multiset<pair<int, int>> values;
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        string value = to_string(target);
        int index    = value.find('.');
        if(index != string::npos){
            value = value.substr(index + 1, 1);
            if(value < "5") target = floor(target);
            else target = ceil(target);
        }

        dfs(root, target);
        vector<int> result;
        for(auto iter = values.begin(); iter != values.end(); iter++){
            if(k == 0) break;
            result.push_back(iter->second);
            k--;
        }

        return result;
    }

    void dfs(TreeNode *root, double &target){
        if(root == nullptr) return;

        values.insert({abs(target - root->val), root->val});
        dfs(root->left,  target);
        dfs(root->right, target);
    }
};
