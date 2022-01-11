/*
1165. Single-Row Keyboard
Difficulty: Easy

There is a special keyboard with all keys in a single row.

Given a string keyboard of length 26 indicating the layout of the keyboard (indexed from 0 to 25), initially your finger is at index 0. To type a character, you have to move your finger to the index of the desired character. The time taken to move your finger from index i to index j is |i - j|.

You want to type a string word. Write a function to calculate how much time it takes to type it with one finger.

Example 1:
Input: keyboard = "abcdefghijklmnopqrstuvwxyz", word = "cba"
Output: 4
Explanation: The index moves from 0 to 2 to write 'c' then to 1 to write 'b' then to 0 again to write 'a'.
Total time = 2 + 1 + 1 = 4. 

Example 2:
Input: keyboard = "pqrstuvwxyzabcdefghijklmno", word = "leetcode"
Output: 73
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
    int calculateTime(string keyboard, string word) {
        map<char, int> pos;
        for (int i = 0; i < static_cast<int>(keyboard.size()); ++i)
            pos[keyboard[i]] = i;
        int res = 0;
        for (int i = 0, prev = 0, curr = 0; i < static_cast<int>(word.size()); ++i) {
            curr = pos[word[i]];
            res += abs(curr - prev);
            prev = curr;
        }
        return res;
    }
};

int main() {
    Solution sol;
    string keyboard, word;

    // Output: 4
    keyboard = "abcdefghijklmnopqrstuvwxyz", word = "cba";

    // Output: 73
    //keyboard = "pqrstuvwxyzabcdefghijklmno", word = "leetcode";

    cout << "Result: " << sol.calculateTime(keyboard, word) << endl;
    
    return 0;
}
