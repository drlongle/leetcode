/*
258. Add Digits
Total Accepted: 103780 Total Submissions: 211836 Difficulty: Easy

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hint:
    A naive implementation of the above process is trivial. Could you come up with other methods?
    What are all the possible results?
    How do they occur, periodically or randomly?
    You may find this article useful: https://en.wikipedia.org/wiki/Digital_root
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
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
    int addDigits(int num) {
        while (num > 9)
        {
            int temp = 0;
            while (num > 0)
            {
                temp += num % 10;
                num /= 10;
            }
            num = temp;
        }

        return num;
    }

    int addDigits_2(int num) {
        return num - 9*floor((num-1)/9);
    }
};

int main()
{
    Solution sol;
    int num;
    cout << "Input: ";
    cin >> num;
    cout << "Result: " << sol.addDigits(num) << endl;

    return 0;
}

