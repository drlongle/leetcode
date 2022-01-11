/*
282. Expression Add Operators

    Total Accepted: 14381
    Total Submissions: 54690
    Difficulty: Hard

Given a string that contains only digits 0-9 and a target value, return all possibilities to add
binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples:

"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/

import java.io.*;
import java.util.*;

public class Solution {

    public List<String> addOperators(String num, int target) {
        List<String> res = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        dfs(res, sb, num, 0, target, 0, 0);
        return res;
    }

    public void dfs(List<String> res, StringBuilder sb, String num,
        int pos, int target, long sum, long prev) {
        if(pos == num.length()) {
            if(target == sum) res.add(sb.toString());
            return;
        }

        for(int i = pos; i < num.length(); i++) {
            if(num.charAt(pos) == '0' && i != pos) break;
            long curr = Long.parseLong(num.substring(pos, i + 1));
            int len = sb.length();
            if(pos == 0) {
                dfs(res, sb.append(curr), num, i + 1, target, curr, curr); 
                sb.setLength(len); // Ignore every in in sb that comes after len
            } else {
                dfs(res, sb.append("+").append(curr), num, i + 1, target,
                    sum + curr, curr);
                sb.setLength(len);
                dfs(res, sb.append("-").append(curr), num, i + 1, target,
                    sum - curr, -curr);
                sb.setLength(len);

                // we have previously add "prev" to "sum" but now we multiply "prev"
                // by "curr". Thus, the sum so far is: sum - prev. We also pass on
                // prev * curr as "prev" at the next level.
                dfs(res, sb.append("*").append(curr), num, i + 1, target,
                    sum - prev + prev * curr, prev * curr);
                sb.setLength(len);
            }
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        List<String> res;
        String num;
        int target;

        // ["1+2+3", "1*2*3"]
        num = "123";
        target = 6;

        res = sol.addOperators(num, target);
        System.out.println(res);
    }
}
