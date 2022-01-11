/*
199. Binary Tree Right Side View

    Total Accepted: 55248
    Total Submissions: 148450
    Difficulty: Medium

Given a binary tree, imagine yourself standing on the right side of it, return
the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

You should return [1, 3, 4]. 
*/

import java.io.*;
import java.util.*;

public class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return res;
        List<List<TreeNode>> levels = new ArrayList<>();
        List<TreeNode> currLevels, nextLevels;
        levels.add(new ArrayList<TreeNode>());
        levels.add(new ArrayList<TreeNode>());
        levels.get(0).add(root);
        int index = 0;
        while (!levels.get(index).isEmpty())
        {
            currLevels = levels.get(index);
            nextLevels = levels.get(1-index);
            res.add(currLevels.get(currLevels.size()-1).val);
            for (TreeNode node: currLevels)
            {
                if (node.left != null)
                    nextLevels.add(node.left);
                if (node.right != null)
                    nextLevels.add(node.right);
            }
            currLevels.clear();
            index = 1 - index;
        }
        return res; 
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
    }
}

