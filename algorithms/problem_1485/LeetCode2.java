class Solution {
    public NodeCopy copyRandomBinaryTree(Node root) {
        Map<Node, NodeCopy> copy = new HashMap<>();
        dfsCopy(root, copy);
        dfsConnect(root, copy);
        return copy.get(root);
    }

    private NodeCopy dfsCopy(Node root, Map<Node, NodeCopy> copy){
        if (root == null) {
            return null;
        }
        NodeCopy copyNode = new NodeCopy(root.val);
        copy.put(root, copyNode);
        dfsCopy(root.left, copy);
        dfsCopy(root.right, copy);
        return copyNode;
    }

    private void dfsConnect(Node node, Map<Node, NodeCopy> copy){
        if (node == null) {
            return;
        }
        if (node.left != null) {
            copy.get(node).left = copy.get(node.left);    
        }
        if (node.right != null) {
            copy.get(node).right = copy.get(node.right);    
        }
        if (node.random != null) {
            copy.get(node).random = copy.get(node.random);    
        }
        dfsConnect(node.left, copy);
        dfsConnect(node.right, copy);
    }
}
