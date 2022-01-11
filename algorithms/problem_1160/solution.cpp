/*
1160. Find Words That Can Be Formed by Characters
Easy

You are given an array of strings words and a string chars. A string is good if it can
be forme by characters from chars (each character can only be used once).
Return the sum of lengths of all good strings in words.

Example 1:
Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: 
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

Example 2:
Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: 
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
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

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> ref_count;
        for (char ch: chars)
            ++ref_count[ch];
        int res = 0;
        for (auto& word: words) {
            map<char, int> count;
            bool valid = true;
            for (char ch: word) {
                if (++count[ch] > ref_count[ch]) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                res += word.size();
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words;
    string chars;

    // Output: 6
    words = {"cat","bt","hat","tree"}, chars = "atach";

    // Output: 10
    //words = {"hello","world","leetcode"}, chars = "welldonehoneyr";

    cout << "Result: " << sol.countCharacters(words, chars) << endl;
    
    return 0;
}
