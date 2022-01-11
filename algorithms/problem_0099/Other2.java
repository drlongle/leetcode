class Solution {
    public void recoverTree(TreeNode root) {
        if(root == null || 
          (root.left == null && root.right == null)) return;
        
        TreeNode preNode = null;
        TreeNode curr = root;
        
        TreeNode fNode = null;
        TreeNode sNode = null;
            
        Stack<TreeNode> stack = new Stack<TreeNode>();
        
        while(!stack.isEmpty() || curr != null) {
            while(curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            
            TreeNode node = stack.pop();
            // something start
            if(preNode == null) preNode = node;
            else {
                if(fNode == null && preNode.val > node.val) fNode = preNode;      
                if(preNode.val > node.val) sNode = node;
            }
            // something ends
            preNode = node;
            curr = node.right;
        }
        
        int tem = fNode.val;
        fNode.val = sNode.val;
        sNode.val = tem;
    }
}

