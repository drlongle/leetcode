/*
242. Valid Anagram
Total Accepted: 88541 Total Submissions: 207954 Difficulty: Easy

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
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
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;
        for (auto& c: s)
            ++count[c];
        
        for (auto& c: t)
        {
            unordered_map<char, int>::iterator it = count.find(c);
            if (it == count.end())
                return false;
            if (--it->second == 0)
                count.erase(it);
        }
        return count.empty();
    }
    
    bool isAnagram_2(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main()
{
    Solution sol;
    string s, t;
    s = "a";
    t = "a";
    cout << "Result: " << sol.isAnagram(s,t) << endl;

    return 0;
}

