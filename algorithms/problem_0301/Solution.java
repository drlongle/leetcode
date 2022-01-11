/*
301. Remove Invalid Parentheses
    Total Accepted: 17312
    Total Submissions: 52085
    Difficulty: Hard

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/

import java.io.*;
import java.util.*;

public class Solution {

    public void makeString(String s, int index, int leftCount, int rightCount)
    {
        if (index == stringSize)
        {
            if (leftCount == expectedPairs && rightCount == expectedPairs)
                res.add(sb.toString());
            return;
        }

        char ch = s.charAt(index);
        int diff, sblen = sb.length();
        switch (ch)
        {
        case '(':
            diff = leftCount - rightCount - rParens[index];
            if (diff < 0)
            {
                sb.append(ch);
                makeString(s, index+1, leftCount+1, rightCount);
                sb.setLength(sblen);
            }
            makeString(s, index+1, leftCount, rightCount);
            break;
        case ')':
            diff = leftCount - rightCount;
            if (diff > 0)
            {
                sb.append(ch);
                makeString(s, index+1, leftCount, rightCount+1);
                sb.setLength(sblen);
            }
            makeString(s, index+1, leftCount, rightCount);
            break;
        default:
            sb.append(ch);
            makeString(s, index+1, leftCount, rightCount);
            sb.setLength(sblen);
        }
    }

    public List<String> removeInvalidParentheses(String s)
    {
        res = new HashSet<>();
        sb = new StringBuilder();
        int leftCount = 0;
        int rightCount = 0;
        expectedPairs = 0;
        stringSize = s.length();
        lParens = new int[stringSize];
        rParens = new int[stringSize];
        
        ArrayDeque<Character> stack = new ArrayDeque<>();

        for (int i = stringSize-1; i >= 0; --i)
        {
            int cp = s.codePointAt(i);
            switch (cp)
            {
            case '(':
                leftCount++;
                if (stack.size() > 0)
                {
                    stack.pop();
                    ++expectedPairs;
                }
                break;

            case ')':
                rightCount++;
                stack.push(')');
                break;
            }
            lParens[i] = leftCount;
            rParens[i] = rightCount;
        }
            
        makeString(s, 0, 0, 0);

        List<String> result = new ArrayList<>();
        for (String r: res)
            result.add(r);

        return result;
    }

    int[] lParens;
    int[] rParens;
    int expectedPairs;
    int stringSize;
    Set<String> res;
    StringBuilder sb;

    public static void main(String[] args)
    {
        Solution sol = new Solution();
        String s;
        
        s = "()((())h()(()()()))((";
        
        System.out.println("Input: " + s);
        List<String> res = sol.removeInvalidParentheses(s);
        for (String r: res)
            System.out.println("  --> " + r);
    }
}
