/*
1461. Check If a String Contains All Binary Codes of Size K
Medium

Given a binary string s and an integer k.
Return True if all binary codes of length k is a substring of s. Otherwise, return False.

Example 1:
Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indicies 0, 1, 3 and 2 respectively.

Example 2:
Input: s = "00110", k = 2
Output: true

Example 3:
Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 

Example 4:
Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and doesn't exist in the array.

Example 5:
Input: s = "0000000001011100", k = 4
Output: false

Constraints:
1 <= s.length <= 5 * 10^5
s consists of 0's and 1's only.
1 <= k <= 20
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size(), num = 0;
        vector<int> bitmask((1 << k) / 32 + 1);
        for (int i = 0; i < n; ++i) {
            num <<= 1;
            num &= ((1 << k) - 1);
            num |= (s[i] - '0');
            if (i >= k - 1) {
                int index = num / 32;
                int bit = num % 32;
                bitmask[index] |= (1 << bit);
            }
        }

        for (int num = 0; num < (1 << k); ++num) {
            int index = num / 32;
            int bit = num % 32;
            if (!(bitmask[index] & (1 << bit)))
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s;
    int k;

    // Output: true
    s = "00110110", k = 2;
    //cout << boolalpha << sol.hasAllCodes(s, k) << endl;
    
    // Output: true
    s = "00110", k = 2;
    //cout << boolalpha << sol.hasAllCodes(s, k) << endl;
        
    // Output: true
    s = "0110", k = 1;
    //cout << boolalpha << sol.hasAllCodes(s, k) << endl;
    
    // Output: false
    s = "0110", k = 2;
    //cout << boolalpha << sol.hasAllCodes(s, k) << endl;
    
    // Output: false
    s = "0000000001011100", k = 4;
    //cout << boolalpha << sol.hasAllCodes(s, k) << endl;

    // False
    s = "0110100100110010110101011001101100111101", k = 6;
    //cout << boolalpha << sol.hasAllCodes(s, k) << endl;
    
    s = "00011010100001110010011010010101000110010010001010", k = 7;
    cout << boolalpha << sol.hasAllCodes(s, k) << endl;
    
    return 0;
}
