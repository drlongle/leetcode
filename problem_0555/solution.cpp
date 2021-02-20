/*
555. Split Concatenated Strings
Medium

Given a list of strings, you could concatenate these strings together into a loop, where for each string
you could choose to reverse it or not. Among all the possible loops, you need to find the lexicographically
biggest string after cutting the loop, which will make the looped string into a regular one.

Specifically, to find the lexicographically biggest string, you need to experience two phases:

Concatenate all the strings into a loop, where you can reverse some strings or not and connect them in the
same order as given. Cut and make one breakpoint in any place of the loop, which will make the looped string
into a regular one starting from the character at the cutpoint. And your job is to find the lexicographically
biggest one among all the possible regular strings.

Example:
Input: "abc", "xyz"
Output: "zyxcba"
Explanation: You can get the looped string "-abcxyz-", "-abczyx-", "-cbaxyz-", "-cbazyx-",
where '-' represents the looped status.
The answer string came from the fourth looped one,
where you could cut from the middle character 'a' and get "zyxcba".

Note:
The input strings will only contain lowercase letters.
The total length of all the strings will not over 1,000.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:

    bool need_reverse(string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            int diff = s[i] - s[j];
            if (diff > 0)
                return false;
            if (diff < 0)
                return true;
            ++i, --j;
        }
        return false;
    }

    void max_rotation(string& s, int index) {
        string res;
        string t = s + s;
        for (size_t i = 1, sz = s.size(); i < sz; ++i) {
            string_view cur(t.c_str() + i, sz);
            if (cur > res) {
                res = cur.substr();
                splitted[index].first = s.substr(i, sz - i);
                splitted[index].second = s.substr(0, i);
            }
        }

        reverse(begin(s), end(s));
        reverse(begin(t), end(t));
        for (size_t i = 1, sz = s.size(); i < sz; ++i) {
            string_view cur(t.c_str() + i, sz);
            if (cur > res) {
                res = cur.substr();
                splitted[index].first = s.substr(i, sz - i);
                splitted[index].second = s.substr(0, i);
            }
        }

        s = res;
    }

    string res;
    ostringstream oss;
    int sz;

    vector <string> reversed;
    vector <string> max_strs;
    vector<pair<string, string>> splitted;

    string splitLoopedString(vector<string>& strs) {
        reversed = strs;
        max_strs = strs;
        sz = strs.size();
        splitted.resize(sz);
        for (int i = 0; i < sz; ++i) {
            max_rotation(max_strs[i], i);
            if (need_reverse(reversed[i]))
                reverse(begin(reversed[i]), end(reversed[i]));
        }

        if (sz == 1)
            return max(reversed[0], max_strs[0]);

        compute_max_string(strs);
        compute_max_string_with_rotation(strs);

        return res;
    }

    void compute_max_string(vector<string>& strs) {
        for (int i = 0; i < sz; ++i) {
            int j = (i + sz - 1) % sz;
            string& t = strs[j];
            char ch = reversed[i][0];
            int len = 0;
            for (int k = t.size()-1; k >= 0; --k) {
                if (t[k] < ch)
                    break;
                ++len;
            }
            oss.str("");
            if (len > 0)
                oss << t.substr(t.size() - len);

            for (int k = 0; k + 1 < sz; ++k) {
                oss << reversed[(i+k) % sz];
            }
            if (len > 0)
                oss << t.substr(0, t.size() - len);
            else
                oss << reversed[j];
            string new_res = oss.str();
            res = max(res, new_res);
        }
    }

    void compute_max_string_with_rotation(vector<string>& strs) {
        for (int i = 0; i < sz; ++i) {
            if (splitted[i].second.empty())
                continue;

            oss.str("");
            oss << splitted[i].first;
            for (int k = 1; k < sz; ++k) {
                oss << reversed[(i+k) % sz];
            }
            oss << splitted[i].second;
            string new_res = oss.str();
            res = max(res, new_res);
        }
    }
};

int main() {
    vector<string> strs;

    // "zyxcba"
    {
        Solution sol;
        strs = {"abc", "xyz"};
        //cout << sol.splitLoopedString(strs) << endl;
    }

    // "zzzyxa"
    {
        Solution sol;
        strs = {"azz", "xyz"};
        //cout << sol.splitLoopedString(strs) << endl;
    }

    // "zzzzzzyxa"
    {
        Solution sol;
        strs = {"azz", "xyzzzz"};
        //cout << sol.splitLoopedString(strs) << endl;
    }

    // "cab"
    {
        Solution sol;
        strs = {"a", "b", "c"};
        //cout << sol.splitLoopedString(strs) << endl;
    }

    // "sbcda"
    {
        Solution sol;
        strs = {"asb", "c", "d"};
        //cout << sol.splitLoopedString(strs) << endl;
    }

    // cba
    {
        Solution sol;
        strs = {"abc"};
        //cout << sol.splitLoopedString(strs) << endl;
    }

    // "zfewafewafwaezdaefffawezfewafawe"
    {
        Solution sol;
        strs = {"awef","eawf","zdaeff","awefzewaf","awefzewaf"};
        cout << sol.splitLoopedString(strs) << endl;
    }

    return 0;
}
