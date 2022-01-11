/*
273. Integer to English Words

 Convert a non-negative integer to its english words representation. Given
 input is guaranteed to be less than 2^31 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

Hint:
- Did you see a pattern in dividing the number into chunk of words? For example,
123 and 123000.
- Group the number by thousands (3 digits). You can write a helper function that
takes a number less than 1000 and convert just that chunk to words.
- There are many edge cases. What are some good test cases? Does your code work
with input such as 0? Or 1000010? (middle chunk is zero and should not be
printed out).
*/

import java.io.*;
import java.util.*;

public class Solution {
    String[] digitToWord;
    String[] tyToWord;
    String[] teenToWord;

    public String numberToWordsHelper(int num) {
	StringBuffer sb = new StringBuffer();
	int digit = num / 100;
	num %= 100;
	if (digit > 0)
	    sb.append(digitToWord[digit]).append(" Hundred");

	digit = num / 10;
	num %= 10;
	if (digit >= 2)
	{
	    if (sb.length() > 0)
	        sb.append(" ");
	    sb.append(tyToWord[digit]);
	}
	else if (digit == 1) {
	    if (sb.length() > 0)
		sb.append(" ");
	    sb.append(teenToWord[num]);
	    num = 0;
	}

	if (num > 0) {
	    if (sb.length() > 0)
		sb.append(" ");
	    sb.append(digitToWord[num]);
	}
	return sb.toString();
    }

    public String numberToWords(int num) {
        digitToWord = new String[] {"Zero", "One", "Two", "Three", "Four",
            "Five", "Six", "Seven", "Eight", "Nine"};
        tyToWord = new String[] {"", "", "Twenty", "Thirty", "Forty", "Fifty",
            "Sixty", "Seventy", "Eighty", "Ninety"};
        teenToWord = new String[] {"Ten", "Eleven", "Twelve", "Thirteen",
            "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
            "Nineteen"};

        StringBuffer sb = new StringBuffer();
        int digit = num / 1000000000;
        num %= 1000000000;
        if (digit > 0)
            sb.append(numberToWordsHelper(digit)).append(" Billion");

        digit = num / 1000000;
        num %= 1000000;
        if (digit > 0) {
            if (sb.length() > 0)
        	sb.append(" ");
            sb.append(numberToWordsHelper(digit)).append(" Million");
        }

        digit = num / 1000;
        num %= 1000;
        if (digit > 0) {
            if (sb.length() > 0)
    	        sb.append(" ");
            sb.append(numberToWordsHelper(digit)).append(" Thousand");
        }

        if (num > 0) {
            if (sb.length() > 0)
    	        sb.append(" ");
            sb.append(numberToWordsHelper(num));
        }

        if (sb.length() == 0)
            sb.append("Zero");
        return sb.toString();
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println(sol.numberToWords(123));
        System.out.println(sol.numberToWords(12345));
        System.out.println(sol.numberToWords(1234567));
    }
}

