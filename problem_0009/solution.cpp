/*
9. Palindrome Number
Total Accepted: 127900 Total Submissions: 398413 Difficulty: Easy

Determine whether an integer is a palindrome. Do this without extra space.

Some hints:

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long reversed = 0, temp = x;
        while (temp)
        {
            reversed = reversed*10 + (temp %10);
            temp /= 10;
        }
        return reversed == x;
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Result: " << boolalpha << sol.isPalindrome(n) << endl;

    return 0;
}

