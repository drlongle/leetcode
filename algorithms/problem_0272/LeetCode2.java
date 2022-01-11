class Solution {
    public void inorder(TreeNode r, List<Integer> nums, Queue<Integer> heap, int k) {
        if (r == null) 
            return;
                    
        inorder(r.left, nums, heap, k);
        heap.add(r.val);
        if (heap.size() > k) 
            heap.remove();
        inorder(r.right, nums, heap, k);
    }

    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        List<Integer> nums = new ArrayList();
        
        // init heap 'less close element first'
        Queue<Integer> heap = new PriorityQueue<>((o1, o2) -> Math.abs(o1 - target) > Math.abs(o2 - target) ? -1 : 1);
        inorder(root, nums, heap, k);
        return new ArrayList<>(heap);
    }
}
