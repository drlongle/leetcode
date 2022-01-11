/*
The first thing we should be able to realize about this problem is that it will be easier to start from the
small palindrome and square it, rather than starting from the large palindrome and square-rooting it.
This is especially useful because the constraint on the large palindrome goes up to 18 digits which means
the small palindrome can only go up to 9 digits.

Consider the palindrome values found between "1" and "9999999999999":
[1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101,
 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111,
 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011,
 1101011, 1102011, 1110111, 1111111, 2000002, 2001002]

Right away, we can notice that, with the exception of the 3, only the numbers 0, 1, & 2 are used in each value.
We could, at this point, fairly easily write a function that would iterate through every base3 number
from 1 to the maximum value of 19683 (3^9, since the small palindrome is limited to 9 digits) and check
 it the same way as before. This is a major drop from 1000000000 iterations to only 19683 iterations.
 */

// Check all possible values between 1 and 19683
class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        int ans = 9 >= stol(left) && 9 <= stol(right) ? 1 : 0;
        for (int i = 1; i < 19684; i++) {
            string num = base3(i);
            if (isPal(num)) {
                long square = stol(num) * stol(num);
                if (square > stol(right)) return ans;
                if (square >= stol(left) && isPal(to_string(square))) ans++;
            }
        }
        return ans;
    }

    string base3(int n) {
        vector<char> nums;
        while (n) {
            div_t divres = div(n, 3);
            nums.push_back((char)(divres.rem + '0'));
            n = divres.quot;
        }
        reverse(nums.begin(), nums.end());
        return string (nums.begin(), nums.end());
    }

    bool isPal(string str) {
        for (int i = 0, j = str.length() - 1; i < j; i++, j--)
            if (str[i] != str[j]) return false;
        return true;
    }
};


// Build out the strings
class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        int ans = 9 >= stol(left) && 9 <= stol(right) ? 1 : 0;
        for (int dig = 1; dig < 10; dig++) {
            bool isOdd = dig % 2 && dig != 1;
            int innerLen = (dig >> 1) - 1,
                    innerLim = max(1, (int)pow(2, innerLen)),
                    midPos = dig >> 1, midLim = isOdd ? 3 : 1;
            for (int edge = 1; edge < 3; edge++) {
                string pal(dig, '0');
                pal[0] = (char)(edge + 48);
                pal[dig-1] = (char)(edge + 48);
                if (edge == 2) innerLim = 1, midLim = min(midLim, 2);
                for (int inner = 0; inner < innerLim; inner++) {
                    if (inner > 0) {
                        string innerStr = bitset<3>(inner).to_string();
                        innerStr = innerStr.substr(3 - innerLen);
                        for (int i = 0; i < innerLen; i++) {
                            pal[1+i] = innerStr[i];
                            pal[dig-2-i] = innerStr[i];
                        }
                    }
                    for (int mid = 0; mid < midLim; mid++) {
                        if (isOdd) pal[midPos] = (char)(mid + 48);
                        long square = stol(pal) * stol(pal);
                        if (square > stol(right)) return ans;
                        if (square >= stol(left) && isPal(to_string(square))) ans++;
                    }
                }
            }
        }
        return ans;
    }

    bool isPal(string str) {
        for (int i = 0, j = str.length() - 1; i < j; i++, j--)
            if (str[i] != str[j]) return false;
        return true;
    }
};
