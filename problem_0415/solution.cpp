/*
415. Add Strings

    User Accepted: 744
    User Tried: 800
    Total Accepted: 756
    Total Submissions: 1753
    Difficulty: Easy

Given two non-negative numbers num1 and num2 represented as string, return
the sum of num1 and num2.

Note:

    The length of both num1 and num2 is < 5100.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.

 */

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        ostringstream oss;
        int carry = 0;
        for (size_t i = 0; i < num1.size() || i < num2.size() || carry; ++i) {
            int sum = carry;
            if (i < num1.size()) sum += (num1[i] - '0');
            if (i < num2.size()) sum += (num2[i] - '0');
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            } else
                carry = 0;
            oss << sum;
        }
        string ret = oss.str();
        reverse(ret.begin(), ret.end());

        return ret;
    }
};

int main()
{
    Solution sol;
    string num1, num2;
    num1 = "123";
    num2 = "45";
    cout << "Result: " << sol.addStrings(num1, num2) << endl;

    return 0;
}

