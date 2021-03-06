/*
res represent the number of parentheses already added.
right represent the number of right parentheses needed.

case )
If we meet a right parentheses , right--.
If right < 0, we need to add a left parentheses before it.
Then we update right += 2 and res++
This part is easy and normal.

case )
If we meet a left parentheses,
we check if we have odd number ')' before.
If we right, we have odd ')' before,
but we want right parentheses in paires.
So add one ')' here, then update right--; res++;.
Note that this part is not necessary if two consecutive right parenthesis not required.
 */
class Solution {
public:
    int minInsertions(string s) {
        int res = 0, right = 0;
        for (char &c: s) {
            if (c == '(') {
                if (right % 2 > 0) {
                    right--;
                    res++;
                }
                right += 2;
            } else {
                right--;
                if (right < 0) {
                    right += 2;
                    res++;
                }
            }
        }
        return right + res;
    }
};