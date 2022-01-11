/*
DP/Fibonacci

If we have n bits, the number of integers without consecutive ones f(n) = f(n - 1) + f (n - 2). f(n - 1) is for the case when first bit is zero, and f(n - 2) is when then the first bit is one and second bit is zero (as we cannot have consecutive ones):

f(n) = "0" f(n - 1) + "10" f(n - 2).
These are Fibonacci numbers, and we can have them in a static array for [0..31] bits.

First, we find n, which is the position of the highest set bit in our number.

Now, if the binary representation of our number starts with "11", then all integers will be smaller than our number, and we can just return a Fibonacci number for n bits.

For example, if n == 12 (binary 0b1100), highest bit at the position 4, next bit is set, so the result is 8 (fb[4]).
If the binary representation of our number starts with "10", then all integers with n - 1 bits will be smaller than our number. So, we will grab a Fibonacci number for n - 1 bits. That's "0" + f(n - 1) case. Plus, we need to add "10.." case, so we remove the highest bit from our number and recursively call our function.

For example, if n == 18 (binary 0b10010), the highest bit at the position 5, next bit is unset, so taking 8 (fb[4] for 0x01111) and adding 3 (fb[2] for 0x00010).
 */

class Solution {
public:
    int findIntegers(int num) {

        // These are Fibonacci numbers
        static int fb[31] = { 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946,
                              17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578 };
        if (num < 3) return num + 1;
        for (int bt = 29; bt >= 0; --bt) // bt should start from 30, but OJ accepts it from 29.
            if (num & (1 << bt)) return num & (1 << (bt - 1)) ? fb[bt] : fb[bt - 1] + findIntegers((num & ~(1 << bt)));
        return 0;
    }
};
