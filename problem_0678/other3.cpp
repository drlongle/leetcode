/*
We can rephrase the problem by listing all the valid cases. There are 3 valid cases:
1- There are more open parenthesis but we have enough * so we can balance the parenthesis with ')'
2- There are more close parenthesis but we have enough * so we can balance the parenthesis with '('
3- There are as many '(' than ')' so all parentheses are balanced, we can ignore the extra '*'
Algorithm: You can parse the String twice, once from left to right by replacing all * by '(' and once from right to left by replacing all * by ')'. For each of the 2 loops, if there's an iteration where you end up with a negative count (SUM['('] - SUM[')'] < 0) then you know the parenthesis were not balanced. You can return false. After these 2 checks (2 loops), you know the string is balanced because you've satisfied all the 3 valid cases mentioned above.
 */

class Solution {
public:
    bool checkValidString( string s ) {
        int bal = 0;
        for( int i=0; i < s.length(); i++ ) {
            if( s[i] == '(' || s[i] == '*' ) bal++;
            else bal--;
            if( bal < 0 ) return false;
        }
        if( bal == 0 ) return true;
        
        bal = 0;
        for( int i=s.length()-1; i >= 0; i-- ) {
            if( s[i] == ')' || s[i] == '*' ) bal++;
            else bal--;
            if( bal < 0 ) return false; 
        }
        return true;
    }
};
