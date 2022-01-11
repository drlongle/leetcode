/*
767. Reorganize String
Medium

Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:
Input: S = "aab"
Output: "aba"

Example 2:
Input: S = "aaab"
Output: ""

Note:
S will consist of lowercase letters and have length in range [1, 500]
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
    string reorganizeString(string S) {
        vector<int> lookup(26, 0);
        for (char ch: S)
            ++lookup[ch - 'a'];
        multimap<int, char, greater<int>> cnt;

        for (int i = 0; i < 26; ++i) {
            int num = lookup[i];
            char ch = 'a' + i;
            if (num > 0)
                cnt.emplace(num, ch);
        }
        string res;
        while (!cnt.empty()) {
            bool inserted = false;
            for (auto it = cnt.begin(); it != cnt.end() && !inserted; ++it) {
                char ch = it->second;
                if (res.empty() || res.back() != ch) {
                    res.push_back(it->second);
                    int num = it->first - 1;
                    cnt.erase(it);
                    if (num > 0)
                        cnt.emplace(num, ch);
                    inserted = true;
                }
            }
            if (!inserted)
                return "";
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    string S;

    // Output: "aba"
    S = "aab";
    cout << sol.reorganizeString(S) << endl;
    

    // Output: ""
    S = "aaab";
    cout << sol.reorganizeString(S) << endl;
    
    
    return 0;
}
