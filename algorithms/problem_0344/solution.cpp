/*
344. Reverse String
Total Accepted: 35214 Total Submissions: 59959 Difficulty: Easy

Write a function that takes a string as input and returns the string reversed.
Example:
Given s = "hello", return "olleh".
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
    string reverseString(vector<char>& s) {
        int begin = 0, end = s.size()-1;
        while (begin < end) {
            swap(s[begin++], s[end--]);
        }
        string res(s.begin(), s.end());
        return res;
    }
};

int main()
{
    Solution sol;
    vector<char> s;

    s = {'h','e','l','l','o'};
    cout << sol.reverseString(s) << endl;

    s = {'a','b','c','d','e', 'f'};
    cout << sol.reverseString(s) << endl;

    return 0;
}

