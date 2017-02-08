/*
316. Remove Duplicate Letters

Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:

Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb" 

Algoritghm sketch.
Consider all characters within a certain range of the string. The range is
chosen such that it's possible to pick any of these characters and we
can still reproduce the rest of the string.

The range can be defined as positions where a new character occurs in the
string. Among the characters in the range, choose the smallest character. 
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

struct CharEntry
{
    CharEntry(char c, int o, int pos): ch(c), occur(o), position(pos) { }
    bool operator<(const CharEntry& other) const
    {
        if (ch == other.ch) return position < other.position;
        return ch < other.ch;
    }
 
    char ch;
    int occur;
    int position;
};

class Solution {
public:
    void insertChar(string& st, const CharEntry& e, map<char,int>& hash,
        int& last_push_pos)
    {
        char ch = e.ch;
        if (hash.find(ch) == hash.end())
            return;
        if (last_push_pos > e.position)
            return;
        last_push_pos = e.position;
        st.push_back(ch);
        hash.erase(ch);
    }

    string removeDuplicateLetters(string s) {
        map<int, set<CharEntry>> lookup;
        map<char,int> hash;
        int size = static_cast<int>(s.size());
        for (int i = size-1; i >= 0; --i)
        {
            char ch = s[i];
            ++hash[ch];
            CharEntry entry(ch, hash[ch], i);
            lookup[hash.size()].emplace(entry);
        }

        string res;
        map<int, set<CharEntry>>::const_reverse_iterator it1;

        // candidates are characters in the input string that can be copied to
        // the result string. 
        set<CharEntry> candidates;
        int last_push_pos = -1;

        for (it1 = lookup.crbegin(); it1 != lookup.crend(); ++it1)
        {
            const set<CharEntry>& entry = it1->second;
            set<CharEntry>::const_iterator it2;

            for (it2 = entry.cbegin(); it2 != entry.cend(); ++it2)
            {
                // we copy it2->ch to the result string if this is its last
                // occurance or it2->ch is the
                // first character among all mising characters
                if (((it2->occur == 1 && hash.find(it2->ch) != hash.end())
                    || (hash.size() && hash.begin()->first == it2->ch))
                    && (it2->position > last_push_pos))
                {

                    // before copying it2->ch to the result string,
                    // let's consider all previous candidates
                    for (auto const& e: candidates)
                    {
                        if (e.ch <= it2->ch && e.position < it2->position) 
                            insertChar(res, e, hash, last_push_pos);
                    }

                    insertChar(res, *it2, hash, last_push_pos);
                }

                if ((it2 != entry.cbegin() ||
                    (hash.size() && hash.begin()->first != it2->ch) )
                    && it2->occur > 1) {
                    if (it2->position > last_push_pos)
                        candidates.insert({it2->ch, it2->occur, it2->position});
                    continue;
                }

                const char ch = it2->ch;
                if (hash.find(ch) != hash.end()) {
                    for (auto const& e: candidates)
                        insertChar(res, e, hash, last_push_pos);
                    candidates.clear();
                    insertChar(res, *it2, hash, last_push_pos);
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    string input;
    // Expected output: "abc"
    input = "bcabc";
    cout << "Result: " << sol.removeDuplicateLetters(input);

    return 0;
}

