/*
216. Combination Sum III

    Total Accepted: 38977
    Total Submissions: 102411
    Difficulty: Medium

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Example 1:
Input: k = 3, n = 7
Output:
[[1,2,4]]

Example 2:
Input: k = 3, n = 9
Output:
[[1,2,6], [1,3,5], [2,3,4]]
*/

import java.io.*;
import java.util.*;

public class Solution {

    public void findCombination(int k, int sum, int num,
        List<Integer> oneSet, List<List<Integer>> allSets)
    {
        if (k == 0)
        {
            if (sum == 0)
            {
                List<Integer> s = new ArrayList<>(oneSet);
                allSets.add(s);
            }
            return;
        }

        for ( ; num <= Math.min(sum,9); ++num)
        {
            oneSet.add(num);
            findCombination(k-1, sum-num, num+1, oneSet, allSets);
            oneSet.remove(oneSet.size()-1);
        }
    }

    public List<List<Integer>> combinationSum3(int k, int sum) {
        List<List<Integer>> allSets = new ArrayList<>();
        List<Integer> oneSet = new ArrayList<>();

        findCombination(k, sum, 1, oneSet, allSets);
        return allSets;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        List<List<Integer>> res;
        int k, sum;
        k = 3;
        sum = 7;

        res = sol.combinationSum3(k,sum);
        for (List<Integer> r : res)
            System.out.println(r.toString());
    }
}

