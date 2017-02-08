/*
228. Summary Ranges

    Total Accepted: 57411
    Total Submissions: 216534
    Difficulty: Medium

Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 
*/

import java.io.*;
import java.util.*;

public class Solution {
    public class Interval {
	public Interval(int n) {
	    first = n;
	    second = n;
	}
	public String toString() {
	    String s = "" + first;
	    if (second > first)
	        s += "->" + second;
	    return s;
	}
        public int first;
        public int second;
    }

    public List<String> summaryRanges(int[] nums) {
	List<String> res = new ArrayList<>();
	if (nums.length == 0)
	    return res;
	Interval it = new Interval(nums[0]);
	for (int i = 1; i < nums.length; ++i)
	{
	    if (nums[i] == it.second +1)
		++it.second;
	    else
	    {
		res.add(it.toString());
		it.first = nums[i];
		it.second = nums[i];
	    }
	}
	res.add(it.toString());
	return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {0,1,2,4,5,7};
        List<String> res = sol.summaryRanges(nums);
        for (String r: res)
            System.out.println("Result: " + r);
    }
}

