/*
347. Top K Frequent Elements
Total Accepted: 18067 Total Submissions: 42013 Difficulty: Medium

Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
    You may assume k is always valid, 1 <= k <= number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

import java.io.*;
import java.util.*;

public class Solution {

    class Counter
    {
        Counter(int v, int o)
        {
            value = v;
            occurs = o;
        }
        int value;
        int occurs;
    }

    class CounterComparator implements Comparator<Counter>
    {
        @Override
        public int compare(Counter o1, Counter o2)
        {
            if (o1.occurs > o2.occurs) return -1;
            else if (o1.occurs == o2.occurs) return 0;
            else return 1;
        }
    }

    public int[] topKFrequent(int[] nums, int k) {
        int[] res = new int[k];
        HashMap<Integer,Integer> counters = new HashMap<Integer,Integer>();
        for (int n: nums)
        {
            if (!counters.containsKey(n))
                counters.put(n,1);
            else
                counters.put(n, counters.get(n)+1);
        }

        ArrayList<Counter> condensed = new ArrayList<Counter>();
        Set set = counters.entrySet();
        Iterator iterator = set.iterator();
        while (iterator.hasNext()) {
            Map.Entry mentry = (Map.Entry)iterator.next();
            int value = ((Integer) mentry.getKey()).intValue();
            int occurs = ((Integer) mentry.getValue()).intValue();
            condensed.add(new Counter(value, occurs));
        }

        Collections.sort(condensed, new CounterComparator());
        for (int i = 0; i < k; ++i)
            res[i] = condensed.get(i).value;

        return res;
    }
}
