/*
97. Interleaving String

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false. 
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

struct Entry {
    Entry(size_t i1, size_t i2, size_t i3) : index1(i1), index2(i2), index3(i3)
    {

    }
    size_t index1, index2, index3;
};

class Solution {
public:

    bool simple_checks(string& s1, string& s2, string& s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        if (s3.size() == 0) return true;
        if (s1.size() == 0) return s2.compare(s3) == 0;
        if (s2.size() == 0) return s1.compare(s3) == 0;
        if (s3.back() != s1.back() && s3.back() != s2.back()) return false;

        map<char, int> count;
        map<char, int>::iterator it;
        for (const auto& c : s1) {
            it = count.find(c);
            if (it != count.end()) it->second++;
            else count[c] = 1;
        }
        for (const auto& c : s2) {
            it = count.find(c);
            if (it != count.end()) it->second++;
            else count[c] = 1;
        }
        for (const auto& c : s3) {
            it = count.find(c);
            if (it != count.end()) {
                it->second -= 1;
                if (it->second == 0) count.erase(it);
            }
            else
                return false;
        }

        return true;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (!simple_checks(s1,s2,s3)) return false;
            return isInterleave_iterative(s1,s2,s3);
    }

    bool isInterleave_recursive(string& s1, size_t index1, string& s2,
        size_t index2,  string& s3, size_t index3)
    {
        if (index1 == s1.size())
            return s2.compare(index2, s2.size()-index2, s3, index3,
                s3.size()-index3) == 0;
        if (index2 == s2.size())
            return s1.compare(index1, s1.size()-index1, s3, index3,
                s3.size()-index3) == 0;

        if (s1[index1] == s3[index3])
            if (isInterleave_recursive(s1, index1+1, s2, index2, s3, index3+1))
                return true;
        if (s2[index2] == s3[index3])
            if (isInterleave_recursive(s1, index1, s2, index2+1, s3, index3+1))
                return true;

        return false;
    }

    bool isInterleave_iterative(string s1, string s2, string s3) {
        size_t size1 = s1.size();
        size_t size2 = s2.size();
        size_t size3 = s3.size();
        if (size1 + size2 != size3)
            return false;

        queue<Entry> entries;
        entries.emplace(0,0,0);
        set<pair<int,int>> hash;
        while(entries.size()) {
            Entry& e = entries.front();
            if (e.index1 == size1 && e.index2 == size2 && e.index3 == size3)
                return true;
            if (e.index1 == size1)
                if (s2.compare(e.index2, size2-e.index2, s3, e.index3,
                    size3-e.index3) == 0)
                    return true;
            if (e.index2 == size2)
                if (s1.compare(e.index1, size1-e.index1, s3, e.index3,
                    size3-e.index3) == 0)
                    return true;

            if (s1[e.index1] == s3[e.index3])
            {
                pair<int,int> p(e.index1+1,e.index2);
                if (hash.find(p) == hash.end()) {
                    hash.emplace(p);
                    entries.emplace(e.index1+1, e.index2, e.index3+1);
                }
            }

            if (s2[e.index2] == s3[e.index3])
            {
                pair<int,int> p(e.index1,e.index2+1);
                if (hash.find(p) == hash.end()) {
                    hash.emplace(p);
                    entries.emplace(e.index1, e.index2+1, e.index3+1);
                }
            }
            entries.pop();
        }
  
        return false;
    }
};

int main()
{
    Solution sol;
    string s1, s2, s3;
    // expected true;
    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbcbcac",
    cout << "Result: " << boolalpha << sol.isInterleave(s1,s2,s3) << endl;

    return 0;
}
