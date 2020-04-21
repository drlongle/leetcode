/*
For the string of size n, we can build 3 * pow(2, n - 1) strings. So, if k <= pow(2, n - 1), then the first letter is a, k <= 2 * pow(2, n - 1) - then b, otherwise c. We can also return empty string right away if k > 3 * pow(2, n - 1).

We continue building the string using the same approach but now with two choices.
 */

class Solution {
public:
    string getHappyString(int n, int k) {
        auto prem = 1 << (n - 1);
        if (k > 3 * prem)
            return "";
        string s = string(1, 'a' + (k - 1) / prem);
        while (prem > 1) {
            k -= prem * ((k - 1) / prem);
            prem >>= 1;
            s += (k - 1) / prem == 0 ? 'a' + (s.back() == 'a') : 'b' + (s.back() != 'c');
        }
        return s;
    }
};
