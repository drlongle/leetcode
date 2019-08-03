
public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
    List<TreeNode> ans = new ArrayList();
    Set<Integer> set = new HashSet();
    for(int x: to_delete)
        set.add(x);
    helper(root, ans, set, true);
    return ans;
}
    
private TreeNode helper(TreeNode root, List<TreeNode> ans, Set<Integer> set, boolean isRoot) {
    if(root == null)
        return null;
    TreeNode res = root;
    if(set.contains(root.val))
        res = null;
    if(res != null && isRoot)
        ans.add(root);
    root.left = helper(root.left, ans, set, res == null);
    root.right = helper(root.right, ans, set, res == null);
    return res;
}
