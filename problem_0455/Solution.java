/*
455. Assign Cookies

    User Tried: 605
    Total Submissions: 693
    Difficulty: Easy

Assume you are an awesome parent and want to give your children some cookies.
But, you should give each child at most one cookie. Each child i has a greed
factor gi, which is the minimum size of a cookie that the child will be
content with; and each cookie j has a size sj. If sj >= gi, we can assign the
cookie j to the child i, and the child i will be content. Your goal is to
maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive.
You cannot assign more than one cookie to one child.

Example 1:

Input: [1,2,3], [1,1]

Output: 1

Explanation: You have 3 children and 2 cookies. The greed factors of 3 children
are 1, 2, 3. And even though you have 2 cookies, since their size is both 1,
you could only make the child whose greed factor is 1 content. You need to
output 1.

Example 2:

Input: [1,2], [1,2,3]

Output: 2

Explanation: You have 2 children and 3 cookies. The greed factors of 2 children
are 1, 2.  You have 3 cookies and their sizes are big enough to gratify all of
the children,  You need to output 2.
 */

import java.io.*;
import java.util.*;

public class Solution {

    public int findContentChildren(int[] g, int[] s) {
        if (g == null || s == null)
            return 0;
        Arrays.sort(g);
        Arrays.sort(s);
        int res = 0;
        int g_index = 0;
        int s_index = 0;
        while (g_index < g.length && s_index < s.length)
        {
            if (g[g_index] <= s[s_index])
            {
                ++res;
                ++g_index;
            }
            ++s_index;
        }

        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int g[];
        int s[];
        
        g = new int[]{1,2,3};
        s = new int[]{1,1};

        System.out.println("Result: " + sol.findContentChildren(g, s));
    }
}

