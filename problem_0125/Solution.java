/*
125. Valid Palindrome

    Total Accepted: 112430
    Total Submissions: 459825
    Difficulty: Easy

Given a string, determine if it is a palindrome, considering only alphanumeric
characters and ignoring cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
*/

import java.io.*;
import java.util.*;

public class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        int begin = 0, end = s.length()-1;

        while (begin <= end)
        {
            for ( ; begin <= end && !Character.isLetter(s.charAt(begin)) &&
                !Character.isDigit(s.charAt(begin)); ++begin)
            {

            }

            for ( ; begin <= end && !Character.isLetter(s.charAt(end)) &&
		!Character.isDigit(s.charAt(end)); --end)
            {

            }

            if (begin > end)
                return true;
            if (s.charAt(begin) != s.charAt(end))
                return false;
            ++begin;
            --end;
        }

        return true;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String s;

        // Expected: true
        s = "A man, a plan, a canal: Panama";
        System.out.println("Result: " + sol.isPalindrome(s));
    }
}

