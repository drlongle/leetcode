/*
421. Maximum XOR of Two Numbers in an Array

    Difficulty: Medium

Given a list of numbers, a[0], a[1], a[2], ... , a[N-1], where 0 <= a[i] < 2^32.
Find the maximum result of a[i] XOR a[j].

Could you do this in O(n) runtime?

Input: [3, 10, 5, 25, 2, 8]
Output: 28
Explanation: The maximum result is 5 ^ 25 = 28.
*/

import java.io.*;
import java.util.*;

public class Solution {

    public class TreeNode
    {
        int val;
        TreeNode left, right;
        TreeNode(int x)
        {
            val = x;
            left = right = null;
        }
    }

    public int findMaximumXOR(int[] nums) {
        int res = Integer.MIN_VALUE;
        int level; 
        for (level = Integer.SIZE-1; level >= 0; --level)
        {
            boolean hasLeft = false;
            boolean hasRight = false;
            for (int i = 0; i < nums.length && (!hasLeft || !hasRight) ; ++i)
            {
                int n = nums[i];
                if ((n >> level) != 0)
                    hasRight = true;
                else
                    hasLeft = true;
            }
            if (hasLeft && hasRight)
                break;
        }

        for (int i = 0; i < nums.length; ++i)
        {
            int n = nums[i];
            if (level <= 0 || (n >> level) != 0)
                insert(n);
        }

        for (int i = 0; i < nums.length; ++i)
        {
            int n = nums[i];
            if (level >= 0 && (n >> level) != 0)
                continue;
            int temp = query(n);
            if (temp > res)
                res = temp;
        }

        return res;
    }

    public Solution()
    {
        root = new TreeNode(0);
    }

    public int query(int num)
    {
        TreeNode node;
        TreeNode next = root;
        for (int i = Integer.SIZE-1; i >= 0; --i)
        {
            node = next;
            if (next == null)
                return 0;
            boolean goLeft = ((num >> i) & 1) == 1;
            if ((goLeft && node.left!= null) || (!goLeft && node.right == null))
                next = node.left; 
            else
                next = node.right; 
        }
        return num ^ next.val;
    }

    public void insert(int num)
    {
        TreeNode node;
        TreeNode next = root;
        for (int i = Integer.SIZE-1; i >= 0; --i)
        {
            node = next;
            boolean goLeft = ((num >> i) & 1) == 0;
            if (goLeft)
            {
                if (node.left == null)
                    node.left = new TreeNode(0);
                next = node.left;
            }
            else
            {
                if (node.right == null)
                    node.right = new TreeNode(0);
                next = node.right;
            }
        }
        next.val = num;
    }

    private TreeNode root;

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums;

        // Expected: 28
        nums = new int[] {3, 10, 5, 25, 2, 8};
        System.out.println("Result: " + sol.findMaximumXOR(nums));
    }
}

