class Solution {
public:
    int cam=0;
    unordered_set<TreeNode*> covered;
    int minCameraCover(TreeNode* root) {
        if(root == nullptr) return 0;
        covered.insert(nullptr);
        put_camera(root, nullptr);
        return cam;
    }
    void put_camera(TreeNode* node, TreeNode* parent){
        if (node != nullptr){
            put_camera(node->left, node);
            put_camera(node->right, node);
            if (parent == nullptr && (covered.find(node) == covered.end())
                || covered.find(node->left)== covered.end() ||
                covered.find(node->right)== covered.end()) {
                cam++;
                covered.insert(node);
                covered.insert(parent);
                covered.insert(node->left);
                covered.insert(node->right);
            }
        }
    }
};