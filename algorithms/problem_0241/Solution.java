/*
241. Different Ways to Add Parentheses

    Total Accepted: 27094
    Total Submissions: 71769
    Difficulty: Medium

Given a string of numbers and operators, return all possible results from
computing all the different possible ways to group numbers and operators.
The valid operators are +, - and *.

Example 1

Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2

Output: [0, 2]

Example 2
Input: "2*3-4*5"
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

Output: [-34, -14, -10, -10, 10]
 */

import java.io.*;
import java.util.*;

public class Solution {

    public List<Integer> combine(List<Integer> result1, List<Integer> result2,
        char op)
    {
        List<Integer> res = new ArrayList<>();
        int length1 = result1.size();
        int length2 = result2.size();
        for (int i = 0; i < length1; ++i) {
            int num1 = result1.get(i);
            for (int j = 0; j < length2; ++j) {
                int num2 = result2.get(j);
                switch (op) {
                case '+':
                    res.add(num1+num2);
                    break;
                case '-':
                    res.add(num1-num2);
                    break;
                case '*':
                    res.add(num1*num2);
                    break;
                }
            }
        }

        return res;
    }

    public List<Integer> compute(String input, char op)
    {
        List<Integer> res = new ArrayList<>();
        List<Integer> r1, r2;
        int index = 0;
        while (true) {
            index = input.indexOf(op, index);
            if (index < 0)
                break;
            r1 = diffWaysToCompute(input.substring(0, index));
            r2 = diffWaysToCompute(input.substring(index+1, input.length()));
            ++index;
            res.addAll(combine(r1, r2, op));
        }
        return res;
    }

    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> r, res = new ArrayList<>();
        String ops = "+-*";
        for (int i = 0; i < ops.length(); ++i) {
            r = compute(input, ops.charAt(i));
            res.addAll(r);
        }

        if (res.isEmpty())
            res.add(Integer.valueOf(input));
        else
            Collections.sort(res);
        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String input;
        List<Integer> res;

        input = "2*3-4*5";
        res = sol.diffWaysToCompute(input);
        for (Integer r: res)
            System.out.println(r);
    }
}

