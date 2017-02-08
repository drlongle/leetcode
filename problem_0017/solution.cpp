/*
17. Letter Combinations of a Phone Number

Given a digit string, return all possible letter combinations that the number
could represent.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

#include <algorithm>
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
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

vector<char> digit_to_chars(char digit)
{
    vector<char> result;
    char ch;
    switch(digit)
    {
    case '1':
        break;
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
        if (digit >= '2' && digit <= '6')
        {
            ch = 'a' + (digit - '2')*3;
            for (int i = 0; i < 3; ++i)
                result.emplace_back(ch++);
        }
        break;
    case '7':
        result = {'p','q','r','s'};
        break;
    case '8':
        result = {'t','u','v'};
        break;
    case '9':
        result = {'w','x','y','z'};
        break;
    }

    return result;
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size()) {
            string one_result;
            letterCombinations(digits, 0, one_result, result);
        }
        return result;
    }

    void letterCombinations(string digits, size_t index, string& temp,
        vector<string>& results) {
        if (index ==  digits.size()) {
            results.emplace_back(temp);
            return;
        }
        vector<char> chs = digit_to_chars(digits[index]);
        for (auto& ch: chs) {
            temp.push_back(ch);
            letterCombinations(digits, index+1, temp, results);
            temp.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    string digits = "23";
    vector<string> result = sol.letterCombinations(digits);
    copy(result.begin(), result.end(), ostream_iterator<string>(cout, ", "));

    return 0;
}

