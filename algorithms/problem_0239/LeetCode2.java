/*
Split an input array into blocks of k elements. The last block could contain less elements
if n % k != 0.

Iterate along the array in the direction left->right and build an array left.
Iterate along the array in the direction right->left and build an array right.
Build an output array as max(right[i], left[i + k - 1]) for i in range (0, n - k + 1).
*/

class Solution {
  public int[] maxSlidingWindow(int[] nums, int k) {
    int n = nums.length;
    if (n * k == 0) return new int[0];
    if (k == 1) return nums;

    int [] left = new int[n];
    left[0] = nums[0];
    int [] right = new int[n];
    right[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++) {
      // from left to right
      if (i % k == 0) left[i] = nums[i];  // block_start (block means i % k == 0)
      else left[i] = Math.max(left[i - 1], nums[i]); // max in the current block so far (going from left to right)

      // from right to left
      int j = n - i - 1;
      if ((j + 1) % k == 0) right[j] = nums[j];  // block_end
      else right[j] = Math.max(right[j + 1], nums[j]); // max in the current block so far (going from right to left)
    }

    int [] output = new int[n - k + 1];
    for (int i = 0; i < n - k + 1; i++)
      output[i] = Math.max(left[i + k - 1], right[i]);

    return output;
  }
}
