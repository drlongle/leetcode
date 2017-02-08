/*
371. Sum of Two Integers
Total Accepted: 769 Total Submissions: 1493 Difficulty: Easy

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
*/

import java.io.*;

class Solution {

    public int getSum(int a, int b) {
        if (a == 0) return b;
        long res = a;
        long temp = b, carry;
        while (temp != 0)
        {
            carry = res & temp;
            res ^= temp;
            temp = carry << 1;
        }
        return (int) res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int a, b, res;
        a = 1;
        b = 2;
        res = sol.getSum(a,b);
        System.out.println("Result:" + res);
    }
}

