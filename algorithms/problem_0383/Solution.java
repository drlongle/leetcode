/*
383. Ransom Note

Given an arbitrary ransom note string and another string containing letters
from all the magazines, write a function that will return true if the ransom
note can be constructed from the magazines; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

*/

import java.io.*;
import java.util.*;

public class Solution {

    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character,Integer> counter = new HashMap<>();
        if (ransomNote.isEmpty()) return true;
        for (char ch : ransomNote.toCharArray()) {
            if (counter.containsKey(ch))
                counter.put(ch, counter.get(ch)+1);
            else
                counter.put(ch, 1);
        }

        for (char ch : magazine.toCharArray()) {
            if (counter.containsKey(ch)) {
                int val = counter.get(ch)-1;
                if (val == 0) {
                    counter.remove(ch);
                    if (counter.isEmpty())
                        return true;
                } else
                    counter.put(ch, val);
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String ransomNote, magazine;

        ransomNote = "fffbfg";
        magazine = "effjfggbffjdgbjjhhdegh";
        System.out.println("Result: " + sol.canConstruct(ransomNote, magazine));
    }
}

