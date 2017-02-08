/*
179. Largest Number

    Total Accepted: 55942
    Total Submissions: 271603
    Difficulty: Medium

Given a list of non negative integers, arrange them such that they form the largest number.
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
Note: The result may be very large, so you need to return a string instead of an integer.
*/

import java.io.*;
import java.util.*;

public class Solution {

    public class Compare implements Comparator<Integer>
    {
	public int compare(Integer first, Integer second)
	{
	    String s1 = first.toString();
	    String s2 = second.toString();
  	    return (s2+s1).compareTo(s1+s2);
	}
    }

    public String largestNumber(int[] nums) {
	List<Integer> array = new ArrayList<>();
	for (int n: nums)
	    array.add(n);
	Collections.sort(array, new Compare());
	StringBuffer sb = new StringBuffer();
	for (Integer a: array)
	    sb.append(a);
	String res = sb.toString();
	int index;
	for (index = 0; index < res.length(); ++index)
	    if (res.charAt(index) != '0')
		break;
	if (index > 1)
	    res = res.substring(index-1);
	return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {3, 30, 34, 5, 9};
        String res = sol.largestNumber(nums);
        System.out.println("Result: " + res);
    }
}

