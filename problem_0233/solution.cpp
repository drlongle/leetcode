/*
233. Number of Digit One

Total Accepted: 17904 Total Submissions: 73264 Difficulty: Hard

Given an integer n, count the total number of digit 1 appearing in all
non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13. 
*/

#include <algorithm>
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
#include <vector>

/*
Example for how we count the '1' in 922.
- We count the '1' in 1xx (we have 100 of '1')
- Then we count the '1' in xx and multiply this result by the leading digit
  ('9' in this case)
- Then we count the '1' in the remainer ("22" in this case) 
*/

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        if (n <= 9) return 1;

        int result = 0;
        string st = to_string(n);
        int first = st[0]-'0';
        int remain = n - first*pow(10.0,st.size()-1);
        if (first > 1)
            result = pow(10.0,st.size()-1);
        else
            result = remain+1;

        int temp = countDigitOne(pow(10.0,st.size()-1)-1);
        result += countDigitOne(remain) + first*temp;
        return result;
    }
};

int main()
{
    Solution sol;
    int input;
    cout << "Input: ";
    cin >> input;
    cout << "Result: " << sol.countDigitOne(input) << endl;

    return 0;
}

