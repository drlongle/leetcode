class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {

        int n = preorder.size();
        if (!n) return true;

        stack<int>stk;
        int parent = INT_MIN;

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && stk.top() < preorder[i]) {
                parent = stk.top();
                stk.pop();
            }
            if (parent >= preorder[i])
                return false;
            stk.push(preorder[i]);
        }

        return true;
    }
};
