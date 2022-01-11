/*
8. String to Integer (atoi)

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

 */

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>
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

#include <string.h>

using namespace std;

class Solution {
public:
    int myAtoi(string st) {
        double result = 0, sign = 1;
        int i, s_size = static_cast<int>(st.size());
        for (i = 0; i < s_size; ++i) {
            if (st[i] != ' ' && st[i] != '\t')
                break;
        }
        if (st[i] == '-') {
            sign = -1; ++i;
        }
        else if (st[i] == '+') ++i;

        for ( ; i < s_size; ++i) {
            if (st[i] < '0' || st[i] > '9')
                break;
            result = result*10 + st[i] - '0';
        }

        result =  result * sign;
        if (result > numeric_limits<int>::max())
            result = numeric_limits<int>::max();
        else if (result < numeric_limits<int>::min())
            result = numeric_limits<int>::min();
        return (int) result;
    }
};


int main()
{
    Solution sol;
    string s("9223372036854775809");
    cout << "--> " << sol.myAtoi(s) << endl;

    return 0;
}
