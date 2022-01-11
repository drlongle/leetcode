public boolean isSameTree(TreeNode p, TreeNode q) {

        Queue<TreeNode> nodes = new LinkedList<>();
        nodes.add(p);
        nodes.add(q);

        while (!nodes.isEmpty()) {
            TreeNode first = nodes.poll();
            TreeNode second = nodes.poll();
            if (first != null && second != null) {
                if (first.val == second.val) {
                    nodes.add(first.left);
                    nodes.add(second.left);
                    nodes.add(first.right);
                    nodes.add(second.right);
                } else {
                    return false;
                }
            } else if (first != second) {
                return false;
            }
        }

        return true;
    }

