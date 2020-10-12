/*
859. Buddy Strings
Easy

Given two strings A and B of lowercase letters, return true if you can swap two letters in A so the result is equal to B, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at A[i] and A[j]. For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

Example 1:
Input: A = "ab", B = "ba"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal to B.

Example 2:
Input: A = "ab", B = "ab"
Output: false
Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b', which results in "ba" != B.

Example 3:
Input: A = "aa", B = "aa"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'a' to get "aa", which is equal to B.

Example 4:
Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true

Example 5:
Input: A = "", B = "aa"
Output: false

Constraints:
0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist of lowercase letters.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (B.size() != A.size())
            return false;
        int sz = A.size(), i1 = -1, i2 = -2, even_cnt = 0;
        vector<int> cnt(26, 0);
        for (int i = 0; i < sz; ++i) {
            if (++cnt[A[i]-'a'] >= 2)
                ++even_cnt;
            if (A[i] == B[i])
                continue;
            if (i1 < 0)
                i1 = i;
            else if (i2 < 0)
                i2 = i;
            else
                return false;
        }
        
        if (i1 < 0 || i2 < 0)
	    return even_cnt > 0 && A == B;
        swap(A[i1], A[i2]);
        
        return A == B;
    }
};


int main() {
    Solution sol;
    string A, B;

    A = "aa", B = "aa";
    cout << boolalpha << sol.buddyStrings(A, B) << endl;

    A = "ab", B = "ba";
    cout << boolalpha << sol.buddyStrings(A, B) << endl;

    A = "ab", B = "ab";
    cout << boolalpha << sol.buddyStrings(A, B) << endl;

    A = B = string(100000, 'a');
    cout << boolalpha << sol.buddyStrings(A, B) << endl;

    A = B = string(100000, 'a');
    A[0] = 'b';
    cout << boolalpha << sol.buddyStrings(A, B) << endl;


    return 0;
}
