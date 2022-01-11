class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node == nullptr)
            return nullptr;

        if (node -> right){
            Node* tmp  = node -> right;
            while (tmp -> left)
                tmp = tmp -> left;
            return tmp;
        }

        Node* next_parent = nullptr;
        while(node -> parent){
            Node* par = node -> parent;
            if (par -> val > node -> val){
                next_parent = par;
                break;
            }
            else
                node = par;
        }
        return next_parent;
    }
};
