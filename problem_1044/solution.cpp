/*
1044. Longest Duplicate Substring
Hard

Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)
Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

Example 1:
Input: "banana"
Output: "ana"

Example 2:
Input: "abcd"
Output: ""

Note:
2 <= S.length <= 10^5
S consists of lowercase English letters.
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

class Solution {
public:
    static constexpr long long MOD = 1000000007;
    bool check(string& s, int len) {
        unordered_map<long long, vector<int>> lookup;
        long long sum = 0, mult = 1;
        for (int i = 0; i < n; ++i) {
            int num = s[i] - 'a';
            sum = (sum * 26 + num) % MOD;
            if (i >= len) {
                sum = (sum - mult * (s[i-len] - 'a')) % MOD;
                while (sum < 0)
                    sum += MOD;
                sum %= MOD;
            } else
                mult = (mult * 26) % MOD;
            auto& vect = lookup[sum];
            int index = i-len+1;
            for (int j: vect) {
                if (s.compare(index, len, s, j, len) == 0) {
                    pos = j, length = len;
                    return true;
                }
            }
            if (i >= len - 1)
                vect.push_back(index);
        }
        return false;
    }

    int n, pos, length;
    string longestDupSubstring(string& S) {
        vector<vector<int>> indexes(26);
        n = S.size();
        length = -1;
        int lo = 1, hi = n-1;
        while (lo <= hi) {
            int mid = (lo+hi) / 2;
            if (check(S, mid))
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return (length >= 0) ? S.substr(pos, length) : "";
    }
};

int main() {
    string s;

    // Output: "ana"
    {
        Solution sol;
        s = "banana";
        cout << sol.longestDupSubstring(s) << endl;
    }

    // Output: ""
    {
        Solution sol;
        s = "abcd";
        cout << sol.longestDupSubstring(s) << endl;
    }

    // Output: "ttatt"
    {
        Solution sol;
        s = "ttattattt";
        cout << sol.longestDupSubstring(s) << endl;
    }

    return 0;
}
