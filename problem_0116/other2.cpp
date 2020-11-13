class Solution {
public:
    Node* connect(Node* root){
        if (root == NULL)
            return NULL;
        auto curr=root, first=root; //first denotes first node of each level
        while (first != NULL){
            curr=first;
            while (curr != NULL){
                if(curr->right != NULL){
                    curr->left->next = curr->right;
                }
                if(curr->right != NULL && curr->next != NULL){
                    curr->right->next = curr->next->left;
                }
                curr=curr->next;
            }
            first=first->left;
        }

        return root;
    }
};
