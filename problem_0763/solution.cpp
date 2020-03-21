/*
763. Partition Labels
Medium

A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
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
#include <memory>
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
    vector<int> partitionLabels(string& s) {
        vector<int> last_seen(26, -1);
        int sz = s.size();
        for (int i = 0; i < sz; ++i) {
            last_seen[s[i] - 'a'] = i;
        }

        vector<int> res;
        int start_index = 0;
        while (start_index < sz) {
            int index = start_index;
            int limit = last_seen[s[index] - 'a'];
            for (; index < limit; ++index) {
                limit = max(limit, last_seen[s[index] - 'a']);
            }
            res.emplace_back(index - start_index + 1);
            start_index = index + 1;
        }

        return res;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: [9,7,8]
    s = "ababcbacadefegdehijhklij";
    auto res = sol.partitionLabels(s);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    return 0;
}
