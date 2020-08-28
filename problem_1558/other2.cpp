/*
We can flip the question and reduce nums to a zero array:

If a number is odd, we have no choice but to decrement it.
If a number is even, we divide it by 2.
Now, since we can divide all numbers in one operation, we just need to track the maximum number and
add its devisions in the end.

In C++, bitset.count uses the most efficient implementaiton for the hardware, and we can consider it O(1).
Since we calculate log2 once in the end, the algorithm time complexity is O(n).
 */

class Solution {
public:
    int minOperations(vector<int>& n) {
        return accumulate(begin(n), end(n), 0, [&](int s, int i) { return s + bitset<32>(i).count(); })
               + log2(*max_element(begin(n), end(n)));
    }
};