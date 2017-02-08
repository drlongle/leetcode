/*
87. Scramble String
Total Accepted: 47655 Total Submissions: 177525 Difficulty: Hard

Given a string s1, we may represent it as a binary tree by partitioning it to
two non-empty substrings recursively.
Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two children.
For example, if we choose the node "gr" and swap its two children, it produces
a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".
Similarly, if we continue to swap the children of nodes "eat" and "at", it produces
a scrambled string "rgtae".
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
    bool isScramble(string s1, string s2)
    {
        if (s1.size() != s2.size()) return false;
        int nsize = s1.size();
        if (s1 == s2) return true;
        
        unordered_map<char,int> count1, count2;
        int index1 = 0, index2 = nsize-1;
        for ( ; index1 < nsize-1; ++index1,--index2)
        {
            ++count1[s1[index1]];
            ++count2[s2[index2]];
            if (count1 == count2)
            {
                if (isScramble(s1.substr(0,index1+1),s2.substr(index2))
                    && isScramble(s1.substr(index1+1),s2.substr(0,index2)))
                    return true;
            }
        }
        
        count1.clear(), count2.clear();
        ++count1[s1[0]];
        ++count2[s2[0]];
        for (index1 = 1; index1 < nsize-1; ++index1)
        {
            ++count1[s1[index1]];
            ++count2[s2[index1]];
            if (count1 == count2 &&
                isScramble(s1.substr(0,index1+1),s2.substr(0, index1+1))
                && isScramble(s1.substr(index1+1),s2.substr(index1+1)))
                return true;
        }

        if (s1.front() == s2.back() &&
            isScramble(s1.substr(1),s2.substr(0,nsize-1)))
            return true;
        if (s1.back() == s2.front() &&
            isScramble(s1.substr(0,nsize-1),s2.substr(1)))
            return true;
        if (s1.front() == s2.front() && isScramble(s1.substr(1),s2.substr(1)))
            return true;
        if (s1.back() == s2.back() &&
            isScramble(s1.substr(0,nsize-1),s2.substr(0,nsize-1)))
            return true;                
            
        return false;
    }
};

int main()
{
    Solution sol;
    string s1, s2;
    s1 = "great";
    s2 = "rgtae";
    cout << "Result: " << boolalpha << sol.isScramble(s1,s2) << endl; 

    return 0;
}

