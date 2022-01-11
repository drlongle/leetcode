/*
567. Permutation in String
Medium

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
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
    bool checkInclusion(string s1, string s2) {
        map<char, int> c1, c2;
        int sz1 = s1.size();
        int sz2 = s2.size();
        for (char ch: s1)
            ++c1[ch];
        for (int head = 0, tail = 0; head < sz2; ++head) {
            ++c2[s2[head]];
            if (head - tail + 1 == sz1) {
                bool match = true;
                for (auto& p: c1) {
                    char ch = p.first;
                    if (p.second > c2[ch]) {
                        match = false;
                        break;
                    }
                }
                if (match)
                    return true;
                --c2[s2[tail]];
                ++tail;
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    string s1, s2;
    
    // Output: True
    s1 = "ab", s2 = "eidbaooo";

    // Output: False
    s1= "ab", s2 = "eidboaoo";

    cout << "Result: " << sol.checkInclusion(s1, s2) << endl;
    
    return 0;
}
