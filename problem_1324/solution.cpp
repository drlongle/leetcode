/*
1324. Print Words Vertically
Medium

Given a string s. Return all the words vertically in the same order in which they appear in s.
Words are returned as a list of strings, complete with spaces when is necessary. (Trailing spaces are not allowed).
Each word would be put on only one column and that in one column there will be only one word. 

Example 1:
Input: s = "HOW ARE YOU"
Output: ["HAY","ORO","WEU"]
Explanation: Each word is printed vertically. 
 "HAY"
 "ORO"
 "WEU"

Example 2:
Input: s = "TO BE OR NOT TO BE"
Output: ["TBONTB","OEROOE","   T"]
Explanation: Trailing spaces is not allowed. 
"TBONTB"
"OEROOE"
"   T"

Example 3:
Input: s = "CONTEST IS COMING"
Output: ["CIC","OSO","N M","T I","E N","S G","T"]

Constraints:
1 <= s.length <= 200
s contains only upper case English letters.
It's guaranteed that there is only one space between 2 words.
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
    vector<string> printVertically(string s) {
        istringstream iss(s);
        string part;
        vector<string> lines;
        while (getline(iss, part, ' ')) {
            lines.emplace_back(part);
        }
        
        int sz = lines.size();
        vector<int> max_len(sz, 0);
        int curr = 0;
        for (int i = sz -1 ; i >= 0; --i) {
            curr = max(curr, static_cast<int>(lines[i].size()));
            max_len[i] = curr;
        }
        vector<string> res(max_len[0]);
        for (int i = 0 ; i < max_len[0]; ++i) {
            for (int j = 0; j < sz; ++j) {
                if (i < (int) lines[j].size())
                    res[i].push_back(lines[j][i]);
                else if (i < max_len[j])
                    res[i].push_back(' ');
            }
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: ["HAY","ORO","WEU"]
    s = "HOW ARE YOU";

    // Output: ["TBONTB","OEROOE","   T"]
    s = "TO BE OR NOT TO BE";

    // Output: ["CIC","OSO","N M","T I","E N","S G","T"]
    s = "CONTEST IS COMING";

    auto res = sol.printVertically(s);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    return 0;
}
