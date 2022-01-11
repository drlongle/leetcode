/*
Idea is to treat the expression as the pre-order traversal of a tree. So, assume we have a tree,
then expression would be analogous to root->val ? root->left : root->right. val can be T/F/0-9.
Since this is a preorder traversal, we only need to find where the : is that separates
root->left expression from root->right expression, if root->val == F. So we can use the same idea
from "check if bracket expression is valid" problem and find the first : that makes the number
of ? and : equal. If root->val == T, we just move 2 chars over.

How do we know when to stop?
Just like traversing through a tree, we stop when there is nothing to go on. That means a leaf node.
By definition, each non-leaf node in this case must be full (have both left and right child), so that
means a ? must proceed all non-leaf nodes. So if we don't have a ? (have : instead, or nothing, in the
case of the last value in the expression) after the current char, we have a leaf node. So we can simply
add that check in to stop.
*/

class Solution {
public:
    string parseTernary(const string& expression, int i = 0) {
        size_t size{expression.size()};
        if(i == size-1 || expression[i+1] == ':') return std::string(1, expression[i]);
        if(expression[i] == 'F') {
            int count{1}, j = i+1;
            while(count) {
                ++j;
                if(expression[j] == '?') ++count;
                else if(expression[j] == ':') --count;
            }
            return parseTernary(expression, j+1);
        }
        return parseTernary(expression, i+2);
    }
};
