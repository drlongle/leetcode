/*
373. Find K Pairs with Smallest Sums

    Total Accepted: 102
    Total Submissions: 459
    Difficulty: Medium

You are given two integer arrays nums1 and nums2 sorted in ascending order and
an integer k.

Define a pair (u,v) which consists of one element from the first array and one
element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:

Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Example 3:

Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
*/

import java.io.*;
import java.util.*;

public class Solution {

    public class Entry
    {
        Entry(int i1, int i2, int s)
        {
            index1 = i1;
            index2 = i2;
            sum = s;
        }

        int index1, index2, sum;
    }

    public class EntryComparator implements Comparator<Entry>
    {
        @Override
        public int compare(Entry e1, Entry e2)
        {
            return e1.sum < e2.sum ? -1 :
                (e1.sum == e2.sum ? 0 : 1);
        }
    }

    public List<int[]> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        List<int[]> res = new ArrayList<>();
        if (nums1.length == 0 || nums2.length == 0) return res;
        int index_size = Math.min(nums1.length, k);
        Queue<Entry> queue =
            new PriorityQueue<Entry>(index_size+1, new EntryComparator());

        for (int i = 0; i < index_size; ++i)
        {
            Entry e = new Entry(i, 0, nums1[i]+nums2[0]);
            queue.add(e);
        }

        for (int i = 0; i < k && queue.size() > 0; ++i)
        {
            Entry e = queue.peek();
            int[] pair = new int[] {nums1[e.index1],nums2[e.index2]};
            res.add(pair);
            if (e.index2+1 < nums2.length)
            {
                e.sum += nums2[e.index2+1] - nums2[e.index2];
                ++e.index2;
                queue.add(e);
            }
            queue.poll();
        }

        return res; 
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums1, nums2;
        int k;
        List<int[]> res;

        nums1 = new int[] {1,7,11};
        nums2 = new int[] {2,4,6};
        k = 3;
        res = sol.kSmallestPairs(nums1,nums2, k);
        for (int[] r: res)
            System.out.println("[" + r[0] + "," + r[1] + "]");
    }
}

