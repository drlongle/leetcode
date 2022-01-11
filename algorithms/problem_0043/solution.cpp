/*
43. Multiply Strings

Given two numbers represented as strings, return multiplication of the numbers as a string. Note: The numbers can be arbitrarily large and are non-negative.
*/

#include <algorithm>
#include <cassert>
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
    string multiply(string num1, string num2)
    {
        string result(1, '0');
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < static_cast<int>(num2.size()); ++i)
        {
            string temp = multiply(num1, num2[i] - '0');
            if (i > 0)
                temp.append(i, '0');
            result = add(result, temp);
        }

        int i, size = static_cast<int>(result.size());
        for (i = 0; i < size; ++i)
            if (result[i] != '0')
                break;
        if (i == size)
            return "0";
        return result.substr(i, size-i);
    }

    string multiply(string num, int digit)
    {
        reverse(num.begin(), num.end());
        int size = static_cast<int>(num.size());
        string result(size, '0');
        int sum, carry = 0;
        for (int index = 0; index < size; ++index)
        {
            sum = (num[index]-'0') * digit + carry;
            result[index] = '0' + (sum % 10);
            carry = sum / 10;
        }
        if (carry)
            result.append(1, '0' + carry);
        reverse(result.begin(), result.end());
        return result;
    }

    string add(string num1, string num2)
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        int digit1, digit2;
        int size1 = static_cast<int>(num1.size());
        int size2 = static_cast<int>(num2.size());
        int size = max(size1, size2);
        string result(size, '0');
        for (int index = 0; index < size; ++index) {
            digit1 = (index < size1) ? num1[index] - '0' : 0;
            digit2 = (index < size2) ? num2[index] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            } else
                carry = 0;
            result[index] = sum + '0';
        }
        if (carry)
            result.append("1");
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution sol;
    string num1, num2;

    num1 = "999";
    num2 = "345";
    cout << "Result: " << sol.multiply(num1, num2);

    return 0;
}
