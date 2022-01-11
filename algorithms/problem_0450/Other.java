/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return root;
        if (root.val == key) { // root is the key
            return mergeLeft(root.left, root.right);
        } else if (root.val > key) {
            root.left = deleteNode(root.left, key);
        } else {
            root.right = deleteNode(root.right, key);
        }
        return root;
    }
    
    private TreeNode mergeLeft(TreeNode leftNode, TreeNode rightNode) {
        if (leftNode == null) return rightNode;
        if (rightNode == null) return leftNode;
        TreeNode iterator = rightNode;
        while (iterator.left != null) {
            iterator = iterator.left;
        }
        iterator.left = leftNode;
        return rightNode;
    }
}
