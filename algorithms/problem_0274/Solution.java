/*
274. H-Index

    Total Accepted: 47981
    Total Submissions: 154277
    Difficulty: Medium

Given an array of citations (each citation is a non-negative integer) of a
researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h
if h of his/her N papers have at least h citations each, and the other (N - h)
papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has
5 papers in total and each of them had received 3, 0, 6, 1, 5 citations
respectively. Since the researcher has 3 papers with at least 3 citations each
and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as
the h-index.

Hint:
    An easy approach is to sort the array first.
    What are the possible values of h-index?
    A faster approach is to use extra space.
*/

import java.io.*;
import java.util.*;

public class Solution {
    public int hIndex(int[] citations) {
        TreeMap<Integer,Integer> counters = new TreeMap<>();
        for (int i: citations)
            counters.merge(i, 1, Integer::sum);
        int h = 0;
        int lowPapers = 0;
        for (Map.Entry<Integer,Integer> mentry : counters.entrySet())
        {
            int highPapers = citations.length - lowPapers;
            int new_h = mentry.getKey();
            if (highPapers >= new_h)
            {
         	h = new_h;
    	        lowPapers += mentry.getValue();
            } else
            {
     	        if (highPapers >= h)
    	            h = highPapers;
    	        break;
            }
        }

        return h;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] citations;
        citations = new int[] {3, 0, 6, 1, 5};

        System.out.println("Result: " + sol.hIndex(citations));
    }
}
