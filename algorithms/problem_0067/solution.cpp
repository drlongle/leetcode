/*
67. Add Binary
Total Accepted: 88132 Total Submissions: 315728 Difficulty: Easy

Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100". 
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
    ll str_to_int(const string& s)
    {
        ll res = 0;
        int ssize = s.size();
        for (int i = 0; i < ssize; ++i)
            res = (res << 1) + s[i] - '0';
        return res;
    }

    string int_to_string(ll& num)
    {
        if (!num) return "0";
        string res;
        while (num)
        {
            res.push_back('0' + (num & 1));
            num >>= 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string addBinary(string a, string b) {
        if (a.size() < b.size()) swap(a,b);
        string res = a;
        int r_index = res.size()-1;
        int b_index = b.size()-1;
        bool carry = false;

        while (r_index >= 0 && (carry || b_index >= 0))
        {
            res[r_index] += (b_index >= 0 ? b[b_index] - '0' : 0) +
                (carry ? 1 : 0);
            if (res[r_index] >= '2')
            {
                res[r_index] -= 2;
                carry = true;
            }
            else
                carry = false;
            --r_index, --b_index;
        }

        if (r_index < 0 && carry)
            res.insert(res.begin(), '1');

        return res;
    }
};

int main()
{
    Solution sol;
    string a,b,res;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    res = sol.addBinary(a,b);
    cout << "Result: " << res << endl;

    return 0;
}

