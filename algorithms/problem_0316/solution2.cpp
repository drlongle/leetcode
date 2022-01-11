/*
316. Remove Duplicate Letters

Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:

Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"

Algorithm sketch.
Scan through the input string, if we see the last occurrence of a character,
insert it into the output string. We also want to insert other characters that
have a lower order.
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <string.h>

using namespace std;

class Solution {
public:

    int find_smaller(vector<int>& pos, int index) {
        int lo = 0, hi = pos.size() - 1, res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (pos[mid] <= index) {
                lo = mid + 1;
                res = pos[mid];
            } else {
                hi = mid - 1;
            }
        }
        return res;
    }

    int find_greater(vector<int>& pos, int index) {
        int lo = 0, hi = pos.size() - 1, res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (pos[mid] <= index)
                lo = mid + 1;
            else {
                res = pos[mid];
                hi = mid - 1;
            }
        }
        return res;
    }

    string removeDuplicateLetters(string s) {
        vector<vector<int>> cnt(26);
        set<char> chars;
        int sz = s.size(), last_print = -1;
        for (int i = 0; i < sz; ++i) {
            cnt[s[i] - 'a'].emplace_back(i);
            chars.emplace(s[i]);
            char ch = s[i];
            while (i+1 < sz && s[i+1] == ch)
                ++i;
        }

        ostringstream oss;
        for (int i = 0; i < sz; ++i) {
            char ch = s[i];
            int index = ch - 'a';
            if (chars.count(ch) == 0)
                continue;
            // Insert if this is the last character.
            if (cnt[index].back() == i) {
                oss << ch;
                last_print = i;
                chars.erase(ch);
                continue;
            }

            int next_ind = numeric_limits<int>::max();
            for (int j = index; j < 26; ++j) {
                if (cnt[j].empty() || (chars.count('a' + j) == 0))
                    continue;
                int cand_ind = find_greater(cnt[j], i);
                if (cnt[j].back() == cand_ind)
                    next_ind = min(next_ind, cand_ind);
            }
            bool print = false;
            if (next_ind != numeric_limits<int>::max()) {
                if (find_smaller(cnt[index], next_ind) == i) {
                    print = true;
                } else {
                    for (auto it = chars.begin(); !print && *it < s[next_ind]; ++it) {
                        int ind = find_greater(cnt[*it-'a'], i);
                        if (ind >= 0 && i < next_ind)
                            print = true;
                    }
                }
            }

            bool flag = false;
            for (int j = index - 1; !flag && j >= 0; --j) {
                if (chars.count('a' + j) == 0)
                    continue;
                int ind = find_greater(cnt[j], i);
                if (ind != -1 && ind < next_ind)
                    flag = true;
            }
            if ((!flag && print) || *chars.begin() == ch) {
                char c = numeric_limits<char>::max();
                for (int k = last_print+1; k < i; ++k) {
                    if (s[k] < ch && chars.count(s[k])) {
                        c = min(c, s[k]);
                    }
                }
                if (c != numeric_limits<char>::max()) {
                    oss << c;
                    chars.erase(c);
                }
                oss << ch;
                chars.erase(ch);
                last_print = i;
            }

        }

        return oss.str();
    }
};

int main()
{
    Solution sol;
    string s;

    // Expected output: "abc"
    s = "bcabc";
    //cout << "Result: " << sol.removeDuplicateLetters(s) << endl;

    // Output: "acdb"
    s = "cbacdcbc";
    //cout << "Result: " << sol.removeDuplicateLetters(s) << endl;

    // Output: "bac"
    s = "bbbacacca";
    //cout << "Result: " << sol.removeDuplicateLetters(s) << endl;

    s = "abccb";
    // cout << "Result: " << sol.removeDuplicateLetters(s) << endl;

    s = "bccab";
    //cout << "Result: " << sol.removeDuplicateLetters(s) << endl;

    s = "mitnlruhznjfyzmtmfnstsxwktxlboxutbic";
    //cout << "Result: " << sol.removeDuplicateLetters(s) << endl;

    s = "rusrbofeggbbkyuyjsrzornpdguwzizqszpbicdquakqws";
    //cout << "Result: " << sol.removeDuplicateLetters(s) << endl;

    s = "yioccqiorhtoslwlvfgzycahonecugtatbyphpuunwvaalcpndabyldkdtzfjlgwqk";
    // cout << "Result: " << sol.removeDuplicateLetters(s) << endl;

    s = "eywdgenmcnzhztolafcfnirfpuxmfcenlppegrcalgxjlajxmphwidqqtrqnmmbssotoywfrtylm";
    //cout << "Result: " << sol.removeDuplicateLetters(s) << endl;

    s = "wmxkuuoordmnpnebikzzujdpscpedcrsjphcaykjsmobturjjxxpoxvvrynmapegvtlasmyuddgxygkaztmbpkrnukbxityz";
    cout << "Result: " << sol.removeDuplicateLetters(s) << endl;

    return 0;
}

