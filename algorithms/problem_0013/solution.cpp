/*
13. Roman to Integer
Total Accepted: 88737 Total Submissions: 221292 Difficulty: Easy

Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
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
    int romanToInt(string s)
    {
        int index, res = 0, ssize = s.size();
        for (index = 0; index < ssize; ++index)
        {
            switch (s[index])
            {
            case 'M':
                res += 1000;
                break;
            case 'D':
                res += 500;
                break;
            case 'C':
                if (index+1 < ssize && (s[index+1] == 'M' || s[index+1] == 'D'))
                {
                    if (s[++index] == 'M')
                        res += 900;
                    else
                        res += 400;
                }
                else
                    res += 100;
                break;
            case 'L':
                res += 50;
                break;
            case 'X':
                if (index+1 < ssize && (s[index+1] == 'L' || s[index+1] == 'C'))
                {
                    if (s[++index] == 'C')
                        res += 90;
                    else
                        res += 40;
                }
                else
                    res += 10;
                break;
            case 'V':
                res += 5;
                break;
            case 'I':
                if (index+1 < ssize && (s[index+1] == 'X' || s[index+1] == 'V'))
                {
                    if (s[++index] == 'X')
                        res += 9;
                    else
                        res += 4;
                }
                else
                    ++res;
                break;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    string input;
    cout << "Input: "; cin >> input;
    cout << "Result: " << sol.romanToInt(input) << endl;

    return 0;
}

