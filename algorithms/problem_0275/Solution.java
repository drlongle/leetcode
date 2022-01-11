/*
275. H-Index II

    Total Accepted: 32401
    Total Submissions: 97823
    Difficulty: Medium

Follow up for H-Index: What if the citations array is sorted in ascending order?
Could you optimize your algorithm?

Hint:
  Expected runtime complexity is in O(log n) and the input is sorted.
*/

import java.io.*;
import java.util.*;

public class Solution {
    public int hIndex(int[] citations) {
        int lower = 0;
        int upper = citations.length-1;
        int h = 0;
        while (lower <= upper)
        {
            int mid = lower + ((upper-lower)>>1);
            int new_h = citations[mid];
            int highPapers = citations.length - mid;
            if (highPapers >= new_h)
            {
        	if (new_h > h)
    	            h = new_h;
         	lower = mid+1;
            }
            else
            {
    	        upper = mid-1;
    	        if (highPapers >= h)
    	            h = highPapers;
            }
        }
    
        return h;
    }

    public static void main(String[] args) {
	Solution sol = new Solution();
	int[] citations;
	citations = new int[] {0, 1, 3, 3, 5, 6};
	System.out.println("Result: " + sol.hIndex(citations));
    }
}

