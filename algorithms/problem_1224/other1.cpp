/*
Intuition
We need to count the frequency of numbers in A
Also we need to know, for each frequency, we have how many different numbers.
count[a] means the frequency of number a
freq[c] means how many numbers that occur c times.

Explanation
Iterate the input array A and we count the n first numbers.

There actually only 2 situation to discuss:

we delete the current number a.
In this case, the n - 1 first numbers have the same frequency,
and we can easier detect this case when we iterate the previous number A[n - 1]

we don't delete the current number a
the current a occurs c times.
So except all numbers that also occurs c times,
it should leave one single number, or c + 1 same numeber.

That's it, done.
*/

class Solution {
public:
    int maxEqualFreq(vector<int>& A) {
        vector<int> count(100001), freq(100001);
        int res = 0, N = A.size(), a,c,d;
        for (int n = 1; n <= N; ++n) {
            a = A[n - 1];
            --freq[count[a]];
            c = ++count[a];
            ++freq[count[a]];

            if (freq[c] * c == n && n < N)
                res = n + 1;
            d = n - freq[c] * c;
            if ((d == c + 1 || d == 1) && freq[d] == 1)
                res = n;
        }
        return res;
    }
};
