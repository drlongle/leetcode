/*
299. Bulls and Cows

    Total Accepted: 34175
    Total Submissions: 111233
    Difficulty: Easy

You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

https://en.wikipedia.org/wiki/Bulls_and_Cows

For example:

Secret number:  "1807"
Friend's guess: "7810"

Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"

In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".

You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
*/

import java.io.*;
import java.util.*;

public class Solution {

    public String getHint(String secret, String guess) {
        Map<Character,Integer> chars = new HashMap<>();
        int size = secret.length();
        int cows = 0, bulls = 0;

        for (int i = 0; i < size; ++i)
        {
            char ch = secret.charAt(i);
            if (chars.containsKey(ch))
                chars.put(ch, chars.get(ch)+1);
            else
                chars.put(ch, 1);
        }

        for (int i = 0; i < size; ++i)
        {
            char ch = guess.charAt(i);
            if (ch == secret.charAt(i))
            {
                ++bulls;
                chars.put(ch, chars.get(ch)-1);
                if (chars.get(ch) == 0)
                    chars.remove(ch);
            }
        }

        for (int i = 0; i < size; ++i)
        {
            char ch = guess.charAt(i);
            if (ch != secret.charAt(i) && chars.containsKey(ch))
            {
                ++cows;
                chars.put(ch, chars.get(ch)-1);
                if (chars.get(ch) == 0)
                    chars.remove(ch);
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(bulls);
        sb.append("A");
        sb.append(cows);
        sb.append("B");

        return sb.toString();
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String secret, guess;

        secret = "1807";
        guess =  "7810";
        System.out.println("Result: " + sol.getHint(secret, guess));
    }
}

