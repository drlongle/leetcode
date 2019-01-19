/*
395. Longest Substring with At Least K Repeating Characters
Difficulty: Medium

Find the length of the longest substring T of a given string (consists of
lowercase letters only) such that every character in T appears no less than k
times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3
The longest substring is "aaa", as 'a' is repeated 3 times.

Example 2:

Input:
s = "ababbc", k = 2

Output:
5
The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is
repeated 3 times.
*/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    
    int longestSubstring(const string& s, int begin, int end, int k) {
        map<char, pair<bool, vector<int>>> pos;
        vector<int> holes;
        for (int i = begin; i < end; ++i) {
            char ch = s[i];
            if (pos[ch].first)
                continue;
            pos[ch].second.emplace_back(i);
            if (pos[ch].second.size() >= k) {
                pos[ch].first = true;
                pos[ch].second.resize(0);
            }
        }
        
        for (const auto& p: pos) {
            if (!p.second.first)
                copy(p.second.second.begin(), p.second.second.end(),
                        back_inserter(holes));
        }
        if (holes.empty())
            return end - begin;
        
        sort(holes.begin(), holes.end());
        int prev = begin;
        int res = 0;
        for (size_t i = 0; i < holes.size(); ++i) {
            int curr = holes[i];
            if (curr - prev >= k) {
                int temp = longestSubstring(s, prev, curr, k);
                res = max(temp, res);
            }
            prev = curr + 1;
        }
        if (end - prev >= k) {
            int temp = longestSubstring(s, prev, end, k);
            res = max(temp, res);
        }
            

        return res;
    }
    
    int longestSubstring(string s, int k) {
        return longestSubstring(s, 0, s.size(), k);
    }
};

int main(int argc, char** argv) {
    Solution sol;
    string s;
    int k;
    
    // Expected: 3
    s = "aaabb", k = 3;
    
    // Expected: 5
    s = "ababbc", k = 2;
    
    // Expected: 3
    s = "bbaaacbd", k = 3;
    
    cout << "Result: " << sol.longestSubstring(s, k) << endl;

    return 0;
}
