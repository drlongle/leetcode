/*
29. Divide Two Integers

Divide two integers without using multiplication, division and mod operator.
If it is overflow, return INT_MAX.
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
    bool is_negative(int64_t num) { return num < 0; }

    int divide(int dividend, int divisor) {
        int64_t a = dividend;
        int64_t b = divisor;
        return divide(a, b);
    }

    int divide(int64_t dividend, int64_t divisor) {
        if (!divisor) return INT_MAX;
        if (divisor == dividend) return 1;
        if (dividend == 0) return 0;
        if (divisor ==1) return dividend;
        if (divisor ==numeric_limits<int>::min()) return 0;

        if (divisor ==numeric_limits<int>::max()) {
            if (dividend ==numeric_limits<int>::min() || dividend ==numeric_limits<int>::min()+1)
                return -1;
            else
                return 0;
        }
        bool negative = is_negative(dividend) != is_negative(divisor);
        dividend = abs(dividend);
        divisor = abs(divisor);
        int i = 31;
        int64_t result = 0;
        while(dividend>= divisor && i >= 0) {
            long long temp = divisor << i;
            if (temp > 0 && dividend >= (divisor << i)) {
                result += ((long long) 1) << i;
                dividend -= divisor << i;
            }
            --i;
        }

        if (negative) result = -result;
        result = min(result, static_cast<int64_t>(numeric_limits<int>::max()));
        result = max(result, static_cast<int64_t>(numeric_limits<int>::min()));
        return static_cast<int>(result);
    }
};

int main()
{
    Solution sol;
    int dividend, divisor;

    cout << "Input dividend: ";
    cin >> dividend;
    cout << "divisor: ";
    cin >> divisor;
    cout << "Result: " << sol.divide(dividend, divisor) << endl;

    return 0;
}

