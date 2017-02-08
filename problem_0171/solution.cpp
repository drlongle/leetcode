/*
171. Excel Sheet Column Number
Total Accepted: 84910 Total Submissions: 199489 Difficulty: Easy

Related to question "168. Excel Sheet Column Title"
Given a column title as appear in an Excel sheet, return its corresponding
column number.

For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
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
    int titleToNumber(string s) {
        int res = 0, ssize = s.size();
        for (int i = 0; i < ssize; ++i)
            res = res*26 + s[i] - 'A' + 1;
        return res;
    }
};

int main()
{
    Solution sol;
    string s;
    cout << "Input: ";
    cin >> s;
    cout << "Result: " << sol.titleToNumber(s) << endl;

    return 0;
}

