/*
If we visit all the nodes and all the child nodes, then the root node would be the only node
that we visit once and once only. The rest of the nodes would be visited twice.

Given a list of numbers where some of the numbers appear twice, we are asked to
find the number that appear only once.
 */

class Solution {
    public Node findRoot(List<Node> tree) {

        Integer valueSum = 0;

        for (Node node : tree) {
            // the value is added as a parent node
            valueSum += node.val;
            for (Node child : node.children)
                // the value is deducted as a child node.
                valueSum -= child.val;
        }

        Node root = null;
        // the value of the root node is `valueSum`
        for (Node node : tree) {
            if (node.val == valueSum) {
                root = node;
                break;
            }
        }
        return root;
    }
}
