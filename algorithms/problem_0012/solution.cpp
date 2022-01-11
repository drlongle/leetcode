/*
12. Integer to Roman

Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
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
    string intToRoman(int num) {
        ostringstream oss;
        while(num >= 1000) {
            oss << "M";
            num -= 1000;
        }
        if (num >= 900) {
            oss << "CM";
            num -= 900;
        }
        if (num >= 500) {
            oss << "D";
            num -= 500;
        }
        if (num >= 400) {
            oss << "CD";
            num -= 400;
        }
        while(num >= 100) {
            oss << "C";
            num -= 100;
        }
        if (num >= 90) {
            oss << "XC";
            num -= 90;
        }
        if (num >= 50) {
            oss << "L";
            num -= 50;
        }
        if (num >= 40) {
            oss << "XL";
            num -= 40;
        }
        while(num >= 10) {
            oss << "X";
            num -= 10;
        }
        if (num >= 9) {
            oss << "IX";
            num -= 9;
        }
        if (num >= 5) {
            oss << "V";
            num -= 5;
        }
        if (num >= 4) {
            oss << "IV";
            num -= 4;
        }
        while(num > 0) {
            oss << "I";
            num -= 1;
        }
        string ret = oss.str();
        return ret;
    }
};

int main()
{
    Solution solution;
    int param;
    cin >> param;
    cout << solution.intToRoman(param) << endl;

    return 0;
}

