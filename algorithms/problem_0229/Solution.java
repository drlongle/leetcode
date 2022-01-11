/*
229. Majority Element II
Total Accepted: 31362 Total Submissions: 119583 Difficulty: Medium

Given an integer array of size n, find all elements that appear more than
n/3 times. The algorithm should run in linear time and in O(1) space.
*/

import java.io.*;
import java.util.*;

public class Solution {

    public static final int K = 3;

    public List<Integer> majorityElement(int[] nums) {
        HashMap<Integer, Integer> counters = new HashMap<Integer,Integer>();

        for (int i = 0; i < nums.length; ++i)
        {
            int n = nums[i];
            if (counters.size() == 3 && counters.containsKey(n) == false)
            {
                ArrayList<Integer> to_be_erased = new ArrayList<Integer>();
                Set<Map.Entry<Integer,Integer>> set = counters.entrySet();
                Iterator<Map.Entry<Integer,Integer>> iterator = set.iterator();
                while (iterator.hasNext()) {
                    Map.Entry<Integer,Integer> mentry = iterator.next();
                    int key = mentry.getKey().intValue();
                    int occurs = mentry.getValue().intValue() - 1;
                    counters.put(key, occurs);
                    if (occurs == 0)
                        to_be_erased.add(key);
                }

                for (int j = 0; j < to_be_erased.size(); ++j)
                    counters.remove(to_be_erased.get(j));
            }

            if (counters.containsKey(n))
                counters.put(n, counters.get(n)+1);
            else
                counters.put(n, 1);
        }

        Set<Map.Entry<Integer,Integer>> set = counters.entrySet();
        Iterator<Map.Entry<Integer,Integer>> iterator = set.iterator();
        while (iterator.hasNext()) {
            Map.Entry<Integer,Integer> mentry = iterator.next();
            int key = mentry.getKey().intValue();
            counters.put(key, 0);
        }

        for (int i = 0; i < nums.length; ++i)
        {
            int n = nums[i];
            if (counters.containsKey(n))
                counters.put(n, counters.get(n)+1);
        }

        ArrayList<Integer> res = new ArrayList<Integer>();
        set = counters.entrySet();
        iterator = set.iterator();
        while (iterator.hasNext()) {
            Map.Entry<Integer,Integer> mentry = iterator.next();
            int key = mentry.getKey().intValue();
            if (counters.get(key) > nums.length / K)
                res.add(key);
        }

        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {1,2,3};
        List<Integer> res = sol.majorityElement(nums);
        for (int i = 0; i < res.size(); ++i)
          System.out.println(res.get(i));
    }
}

