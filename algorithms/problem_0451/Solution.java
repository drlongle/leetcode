/*
451. Sort Characters By Frequency

    Total Accepted: 1967
    Total Submissions: 4336
    Difficulty: Medium
    Contributors: stickypens

Given a string, sort it in decreasing order based on the frequency of
characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

import java.io.*;
import java.util.*;

public class Solution {

    public class CharComparator implements Comparator<Character>
    {
        public int compare(Character c1, Character c2)
        {
            int v1 = counters.get(c1);
            int v2 = counters.get(c2);
            if (v1 > v2)
                return -1;
            else if (v1 < v2)
                return 1;
            if (c1 < c2)
                return -1;
            else if (c1 == c2)
                return 0;
            else
                return 1;
        }
    }

    public String frequencySort(String s) {
        counters = new HashMap<>();
        List<Character> chars = new ArrayList<>();
        for (Character c: s.toCharArray())
        {
            /*
            if (!counters.containsKey(c))
                counters.put(c,  1);
            else
                counters.put(c, counters.get(c) + 1);
             */
            counters.merge(c, 1, Integer::sum);
            chars.add(c);
        }

        Collections.sort(chars, new CharComparator());
        StringBuilder sb = new StringBuilder();
        for (Character c: chars)
            sb.append(c);
        return sb.toString();
    }

    private HashMap<Character, Integer> counters;
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        String s;
        
        s = "tree";
        s = "loveleetcode";
            
        System.out.println("Result: " + sol.frequencySort(s));
    }
}
