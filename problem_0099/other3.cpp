
class Solution {
public:
    TreeNode* last1;
    TreeNode* last2;
    TreeNode* node1;
    TreeNode* node2;
    void Postraversal(TreeNode* node)
    {
        if(node!=nullptr)
        {
            Postraversal(node->left);

            if(last1==nullptr)
                last1=node;
            else{
                if(node1==nullptr&&last1->val>node->val)
                {
                    node1=last1;
                }
                else if(node1!=nullptr&&last2->val>last1->val&&node->val>last1->val)
                {
                    node2=last1;
                }
                last2=last1;
                last1=node;
            }
            Postraversal(node->right);
        }
    }
    void recoverTree(TreeNode* root) {
        last1=last2=node1=node2=nullptr;
        Postraversal(root);
        if(node2==nullptr || last1->val<last2->val)
            node2=last1;

        swap(node1->val, node2->val);
    }
};
