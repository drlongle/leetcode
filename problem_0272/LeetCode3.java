class Solution {
    List<Integer> nums;
    double target;
    
    public void swap(int a, int b) {
        int tmp = nums.get(a);
        nums.set(a, nums.get(b));
        nums.set(b, tmp);
    }
    
    public void inorder(TreeNode r, List<Integer> nums) {
        if (r == null) 
            return;
                    
        inorder(r.left, nums);
        nums.add(r.val);
        inorder(r.right, nums);
    }

    public int partition(int left, int right, int pivotIndex) {
        double pivotDist = dist(pivotIndex);
        // 1. move pivot to end
        swap(pivotIndex, right);
        int storeIndex = left;

        // 2. move more close elements to the left
        for (int i = left; i <= right; i++) {
            if (dist(i) < pivotDist) {
                swap(storeIndex, i);
                storeIndex++;
            }
        }

        // 3. move pivot to its final place
        swap(storeIndex, right);

        return storeIndex;
    }
    
    public void quickselect(int left, int right, int kSmallest) {
        /*
        Sort a list within left..right till kth less close element
        takes its place. 
        */

        // base case: the list contains only one element
        if (left >= right) return;
        
        // select a random pivot_index
        Random randomNum = new Random();
        int pivotIndex = left + randomNum.nextInt(right - left); 

        // find the pivot position in a sorted list
        pivotIndex = partition(left, right, pivotIndex);

        // if the pivot is in its final sorted position
        if (kSmallest == pivotIndex) {
            return;    
        } else if (kSmallest < pivotIndex) {
            // go left
            quickselect(left, pivotIndex - 1, kSmallest);     
        } else {
            // go right 
            quickselect(pivotIndex + 1, right, kSmallest);  
        }
    }
    
    public double dist(int idx) {
        return Math.abs(nums.get(idx) - target);
    }

    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        nums = new ArrayList();  
        this.target = target;
        inorder(root, nums);
        quickselect(0, nums.size() - 1, k);
        return nums.subList(0, k);
    }
}
