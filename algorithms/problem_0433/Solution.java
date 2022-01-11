/*
433. Minimum Genetic Mutation

A gene string can be represented by an 8-character long string, with choices
from "A", "C", "G", "T". Suppose we need to investigate about a mutation
(mutation from "start" to "end"), where ONE mutation is defined as ONE single
character changed in the gene string.

For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

Also, there is a given gene "bank", which records all the valid gene mutations.
A gene must be in the bank to make it a valid gene string.

Now, given 3 things - start, end, bank, your task is to determine what is the
minimum number of mutations needed to mutate from "start" to "end". If there
is no such a mutation, return -1.

Note:

    Starting point is assumed to be valid, so it might not be included in the
        bank.
    If multiple mutations are needed, all mutations during in the sequence must
        be valid.
    You may assume start and end string is not the same.

Example 1:

start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

return: 1

Example 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

return: 2

Example 3:

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

return: 3
*/

import java.io.*;
import java.util.*;

public class Solution {

    public class Entry
    {
        Entry(String w, int d)
        {
            word = w;
            dist = d;
        }
        String word;
        int dist;
    }

    public int minMutation(String start, String end, String[] bank) {
        Set<String> lookup = new HashSet<>();
        for (String s: bank)
            lookup.add(s);
        Queue<Entry> queue = new ArrayDeque<>();
        queue.offer(new Entry(start, 0));
        while (!queue.isEmpty())
        {
            Entry e = queue.poll();
            if (e.word.equals(end))
                return e.dist;

            char[] chars = e.word.toCharArray();
            for (int i = 0; i < chars.length; ++i)
            {
                for (char c: allChars)
                {
                    chars[i] = c;
                    String s = new String(chars);
                    if (lookup.contains(s))
                    {
                        lookup.remove(s);
                        queue.add(new Entry(s, e.dist + 1));
                    }
                }
                chars[i] = e.word.charAt(i);
            }
        }

        return -1;
    }

    private static final char[] allChars = {'A', 'C', 'G', 'T'};

    public static void main(String[] args) {
        Solution sol = new Solution();
        String start, end;
        String[] bank;

        start = "AAAAACCC";
        end =   "AACCCCCC";
        bank = new String[] {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
        
        System.out.println("Result: " + sol.minMutation(start, end, bank));
    }
}
