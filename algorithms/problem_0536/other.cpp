class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) {
            return nullptr;
        }
        stack<TreeNode*> stack;
        stack.push(new TreeNode);
        for (int i = 0; i < s.length(); /*nothing*/) {
            if (s[i] == '(') {
                TreeNode* curr = stack.top();
                if (!curr->left) {
                    curr->left = new TreeNode;
                    stack.push(curr->left);
                }
                else { // left already processed, go to right
                    curr->right = new TreeNode;
                    stack.push(curr->right);
                }
                ++i;
            }
            else if (s[i] == ')') {
                stack.pop();
                ++i;
            }
            else {
                const int j = s.find_first_of("()", i);
                stack.top()->val = stoi(s.substr(i, j - i));
                i = j;
            }
        }
        assert(stack.size() == 1);
        return stack.top();
    }
};
