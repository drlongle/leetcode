/*
132. Palindrome Partitioning II
Total Accepted: 50682 Total Submissions: 231707 Difficulty: Hard

Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. 
*/

#include <algorithm>
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
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

unordered_map<int, int> cache;
vector<vector<bool> > palin_cache;

void expand_palindrome(const string& s, int i, int j)
{
    int ssize = s.size();
    while (i >= 0 && j < ssize && s[i] == s[j])
    {
        palin_cache[i][j] = true;
        --i, ++j;
    }
}

int palindrome_mincut(string s, int index)
{
    unordered_map<int,int>::iterator it = cache.find(index);
    if (it != cache.end())
        return it->second;

    int result = numeric_limits<int>::max();
    int ssize = s.size();
    for (int i = ssize-1; i >= index && result > 1; --i)
    {
        if (!palin_cache[index][i])
            continue;
        if (i == ssize-1)
            result = 0;
        else
        {
            int tempresult = palindrome_mincut(s, i+1);
            if (result > tempresult+1)
                result = tempresult+1;
        }
    }
    
    cache[index] = result;
    return result;
}

class Solution {
public:
    int minCut(string s) {
        cache.clear();
        int ssize = s.size();
        palin_cache = vector<vector<bool> >(ssize, vector<bool>(ssize, false));
        for (int i = 0; i < ssize; ++i)
        {
            expand_palindrome(s, i, i);
            if (i+1 < ssize && s[i] == s[i+1])
                expand_palindrome(s, i, i+1);
        }
        if (palin_cache[0][s.size()-1]) return 0;
        return palindrome_mincut(s, 0);
    }

    int min_cut_iterative(string s) {
        int ssize = s.size();
        vector<int> cuts(ssize);
        iota(cuts.begin(), cuts.end(), 0);
        for (int i = 1; i < ssize; ++i)
        {
            for (int j = 0; j < i && cuts[i] > 1; ++j)
            {
                if (!palin_cache[i][j])
                    continue;
                if (cuts[i] > cuts[j]+1)
                    cuts[i] = cuts[j]+1;
            }
        }
        return cuts[ssize-1];
    }
};

int main()
{
    Solution sol;
    string s;
    int result;
  
    // Expected: 1
    s = "aab";
    result = sol.minCut(s);
    cout << "Result: " << result << endl;

    return 0;
}

