/*
Explanation:
First, we iterate the dominoes twice.

- From left to right, we want to check which dominoes might be falling to the right side.
So every time we see a 'R' we know that the next dominoes will maybe fall right, so we save in the 'right' vector
the distance from the previous 'R'. (Until we reach a 'L').
- From right to left, we do the same for the left side.

Example:
Let's use the second example from the question - ".L.R...LR..L..".
The 'right' array will look like this: [0,0,0,0,1,2,3,0,0,1,2,0,0,0]
The 'left' array will look like this: [1,0,0,0,3,2,1,0,0,2,1,0,0,0]
Next step is to compare 'right and 'left'.
For each i:

If both are 0 - we just copy what we had in dominoes.
If right[i] is 0 but left[i] is not, it means this domino falls to the left, and vice versa.
if they are both equal, which means that we have balance of the forces and we stay vertical.
If we have to different values in right[i] and left[i], we find the minimum which means that it's closer.
 */

class Solution {
public:
    string pushDominoes(string dominoes) {
        #define SET(ch, arr) \
        if (dominoes[i] == ch) { count = 1; prev = ch; } \
        else if (dominoes[i] != '.') prev = dominoes[i]; \
        if (prev == ch && dominoes[i] == '.') arr[i] = count++;

        string res = "";
        char prev;
        int n = dominoes.size(), count = 1;

        vector<int> left(n, 0), right(n, 0);
        for (int i = 0; i < n; i++) {
            SET('R', right);
        }

        prev = '.';
        for (int i = n-1; i >= 0; i--) {
            SET('L', left);
        }

        for (int i = 0; i < n; i++) {
            if (!left[i] && !right[i]) res += dominoes[i];
            else if (!left[i]) res += 'R';
            else if (!right[i]) res += 'L';
            else if (left[i] == right[i]) res += '.';
            else if (left[i] < right[i]) res += 'L';
            else res += 'R';
        }

        return res;
    }
};
