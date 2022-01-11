/*
306. Additive Number

    Total Accepted: 16428
    Total Submissions: 61351
    Difficulty: Medium

Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the
first two numbers, each subsequent number in the sequence must be the sum of
the preceding two.

For example: "112358" is an additive number because the digits can form an
additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

"199100199" is also an additive number, the additive sequence is:
1, 99, 100, 199.

1 + 99 = 100, 99 + 100 = 199

Note: Numbers in the additive sequence cannot have leading zeros, so sequence
1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine
if it's an additive number.

Follow up:
How would you handle overflow for very large input integers? 
*/

import java.io.*;
import java.util.*;

public class Solution
{
    String add(String s1, String s2)
    {
        StringBuilder sb = new StringBuilder();
        s1 = sb.append(s1).reverse().toString();
        sb.setLength(0);
        s2 = sb.append(s2).reverse().toString();
        sb.setLength(0);
        int carry = 0, index = 0;
        while (index < s1.length() || index < s2.length() || carry != 0)
        {
            if (index < s1.length())
                carry += s1.charAt(index) - '0';
            if (index < s2.length())
                carry += s2.charAt(index) - '0';
            char ch = '0';
            if (carry < 10)
            {
                ch += carry;
                carry = 0;
            }
            else
            {
                ch += carry-10;
                carry = 1;
            }
            sb.append(ch);
            ++index;
        }
        return sb.reverse().toString();
    }

    public boolean check(String num, String s1, String s2, int index)
    {
        while (index < num.length())
        {
            String sum = add(s1, s2);
            if (num.startsWith(sum, index) == false)
                return false;
            s1 = s2;
            s2 = sum;
            index += sum.length();
        }
        return index == num.length();
    }

    public boolean isAdditiveNumber(String num)
    {
        int length = num.length();
        for (int i = 1; i < length-1; ++i)
        {
            String s1 = num.substring(0, i);
            for (int j = i+1; j < length; ++j)
            {
                String s2 = num.substring(i, j);
                if ((s2.length() == 1 || s2.charAt(0) != '0') &&
                    check(num, s1, s2, j))
                    return true;
            }
        }
        return false;
    }

    public static void main(String[] args)
    {
        Solution sol = new Solution();
        String num, res;
        num = "112358";
        System.out.println("Result: " + sol.isAdditiveNumber(num));
    }
}
