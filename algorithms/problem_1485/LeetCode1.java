class Solution {
    public NodeCopy copyRandomBinaryTree(Node root) {
        if (root == null) {
            return null;
        }

        // Step 1. Create a copy of each node
        Map<Node, NodeCopy> copy = new HashMap<>();
        Stack<Node> stack = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            Node node = stack.pop();
            NodeCopy copyNode = new NodeCopy(node.val);
            copy.put(node, copyNode);

            if (node.left != null) {
                stack.push(node.left);
            }
            if (node.right != null) {
                stack.push(node.right);
            }
        }

        // Step 2. Connect the copied nodes together
        stack.push(root);
        while (!stack.isEmpty()) {
            Node node = stack.pop();

            if (node.left != null) {
                copy.get(node).left = copy.get(node.left);
                stack.push(node.left);
            }
            if (node.right != null) {
                copy.get(node).right = copy.get(node.right);
                stack.push(node.right);
            }
            if (node.random != null) {
                copy.get(node).random = copy.get(node.random);
            }
        }

        return copy.get(root);
    }
