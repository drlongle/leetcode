/*
1307. Verbal Arithmetic Puzzle
Hard

Given an equation, represented by words on left side and the result on right side.
You need to check if the equation is solvable under the following rules:
Each character is decoded as one digit (0 - 9).
Every pair of different characters they must map to different digits.
Each words[i] and result are decoded as one number without leading zeros.
Sum of numbers on left side (words) will equal to the number on right side (result). 
Return True if the equation is solvable otherwise return False.

Example 1:
Input: words = ["SEND","MORE"], result = "MONEY"
Output: true
Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652

Example 2:
Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
Output: true
Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214

Example 3:
Input: words = ["THIS","IS","TOO"], result = "FUNNY"
Output: true

Example 4:
Input: words = ["LEET","CODE"], result = "POINT"
Output: false

Constraints:

2 <= words.length <= 5
1 <= words[i].length, results.length <= 7
words[i], result contains only upper case English letters.
Number of different characters used on the expression is at most 10.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

// Solution not accepted, runs for too long.
class Solution {
public:
    bool eval(vector<string>& words, string& result) {
        ostringstream oss;
        for (int i = 0, carry = 0; i < msz || carry; ++i) {
            for (auto& word: words) {
                if (i < static_cast<int>(word.size()))
                    carry += (word[i]);
            }
            char ch = carry % 10;
            oss << ch;
            carry /= 10;
        }

        return oss.str() == result;
    }
    
    bool explore(vector<string>& words, string& result, size_t level) {
        if (level == chars.size())
            return eval(words, result);
        char ch = chars[level];
        for (char i = 0; i < 10; ++i) {
            if (used_digits[i] == 0) {
                used_digits[i] = 1;
                for (auto& word: words) {
                    for (char& c: word) {
                        if (ch == c)
                            c = i;
                    }
                }
                for (char& c: result) {
                    if (ch == c)
                        c = i;
                }
                if (explore(words, result, level + 1))
                    return true;

                for (auto& word: words) {
                    for (char& c: word) {
                        if (i == c)
                            c = ch;
                    }
                }
                for (char& c: result) {
                    if (i == c)
                        c = ch;
                }
                
                used_digits[i] = 0;
            }
        }
        
        return false;
    }
    
    bool isSolvable(vector<string>& words, string result) {
        set<char> uniq;
        msz = 0;
        for (auto& word: words) {
            reverse(begin(word), end(word));
            msz = max(msz, static_cast<int>(word.size()));
            for (char ch: word)
                uniq.emplace(ch);
        }
        int rsz = result.size();
        reverse(begin(result), end(result));
        for (char ch: result)
            uniq.emplace(ch);
        
        if (rsz < msz || rsz > msz + 1)
            return false;
        for (char ch: uniq)
            chars.emplace_back(ch);
        used_digits.resize(10, 0);

        return explore(words, result, 0);
    }
    
    int msz;
    vector<char> chars;
    vector<int> used_digits;
};

int main() {
    Solution sol;
    vector<string> words;
    string result;

    // Expected: true
    words = {"SEND","MORE"}, result = "MONEY";

    // Expected: true
    words = {"SIX","SEVEN","SEVEN"}, result = "TWENTY";

    // Expected: true
    words = {"THIS","IS","TOO"}, result = "FUNNY";

    // Expected: false
    //words = {"LEET","CODE"}, result = "POINT";

    // Expected: false
    // words = {"TO","BE","OR","NOT"}, result = "TOBE";

    // Expected: true
    //words = {"AA","BB"}, result = "AA";

    // Expected: true
    //words = {"SATURN","URANUS"}, result = "PLANETS";
    
    cout << boolalpha << "Result: " << sol.isSolvable(words, result) << endl;
    
    return 0;
}
