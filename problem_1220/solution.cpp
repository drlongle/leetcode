/*
1220. Count Vowels Permutation
Hard

Given an integer n, your task is to count how many strings of length n
can be formed under the following rules:

- Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
- Each vowel 'a' may only be followed by an 'e'.
- Each vowel 'e' may only be followed by an 'a' or an 'i'.
- Each vowel 'i' may not be followed by another 'i'.
- Each vowel 'o' may only be followed by an 'i' or a 'u'.
- Each vowel 'u' may only be followed by an 'a'.

Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".

Example 2:
Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".

Example 3: 
Input: n = 5
Output: 68
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
    int countVowelPermutation(int n) {
        array<map<char, int>, 2> count;
        vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
        constexpr int mod_factor = pow(10, 9) + 7;
        for (char ch: vowels)
            count[1][ch] = 1;

        for (int i = 2; i <= n; ++i) {
            for (char ch: vowels) {
                switch (ch) {
                    case 'a':
                        count[i % 2][ch] = count[(i -1) % 2]['e'];
                        break;
                    case 'e':
                        count[i % 2][ch] = (count[(i -1) % 2]['a'] + count[(i -1) % 2]['i']) % mod_factor;
                        break;
                    case 'i': {
                        int a = (count[(i -1) % 2]['a'] + count[(i -1) % 2]['e']) % mod_factor;
                        int b = (count[(i -1) % 2]['o'] + count[(i -1) % 2]['u']) % mod_factor;
                        count[i % 2][ch] = (a + b) % mod_factor;
                        break;
                    }
                    case 'o':
                        count[i % 2][ch] = (count[(i -1) % 2]['i'] + count[(i -1) % 2]['u']) % mod_factor;
                        break;
                    case 'u':
                        count[i % 2][ch] = count[(i -1) % 2]['a'];
                        break;
                }
            }
        }
        int res = 0;
        for (auto& p: count[n % 2])
            res = (res + p.second) % mod_factor;
        
        return res;
    }
};

int main() {
    Solution sol;
    int n;

    // OUtput: 5
    n = 1;

    // OUtput: 10
    n = 2;
    
    // OUtput: 68
    n = 5;

    // Expeted: 18208803
    n = 144;
    
    cout << "Result: " << sol.countVowelPermutation(n) << endl;
    
    return 0;
}
