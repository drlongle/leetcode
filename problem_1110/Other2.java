public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
    Set<Integer> set = new HashSet<>();
    for (int v : to_delete) set.add(v);
    List<TreeNode> results = new ArrayList<>();
    delete(root, set, results, true);
    return results;
}
private TreeNode delete(TreeNode node, Set<Integer> to_delete, List<TreeNode> results, boolean add) {
    if (node == null) {
        return null;
    } else if (to_delete.contains(node.val)) {
        delete(node.left, to_delete, results, true);
        delete(node.right, to_delete, results, true);
        return null;
    } else {
        if (add) results.add(node);
        node.left = delete(node.left, to_delete, results, false);
        node.right = delete(node.right, to_delete, results, false);
        return node;
    }
}
