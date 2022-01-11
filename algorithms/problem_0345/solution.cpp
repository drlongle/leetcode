/*
345. Reverse Vowels of a String
Total Accepted: 20738 Total Submissions: 58509 Difficulty: Easy

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede". 
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
    bool isVowel(char ch)
    {
        switch (tolower(ch))
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
    }

    string reverseVowels(string s) {
        int begin = 0, end = s.size()-1;
        while (begin < end)
        {
            while (begin < end && !isVowel(s[begin]))
                ++begin;
            while (begin < end && !isVowel(s[end]))
                --end;
            swap(s[begin++],s[end--]);
        }
        return s;
    }
};

int main()
{
    Solution sol;
    string input;
    cout << "Input: ";
    cin >> input;
    cout << "Result: " << sol.reverseVowels(input) << endl;

    return 0;
}

