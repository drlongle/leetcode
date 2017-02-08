/*
168. Excel Sheet Column Title
Total Accepted: 64668 Total Submissions: 289831 Difficulty: Easy

Given a positive integer, return its corresponding column title as appear in
an Excel sheet.

For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
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
    string convertToTitle(int n) {
        stringstream ss;
        while (true)
        {
            --n;
            ss << static_cast<char>('A' + n % 26);
            n /= 26;
            if (!n)
                break;
        }
        string s = ss.str();
        reverse(s.begin(), s.end());
        return s;
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Result: " << sol.convertToTitle(n) << endl;

    return 0;
}

