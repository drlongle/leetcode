/*
131. Palindrome Partitioning
Total Accepted: 65326 Total Submissions: 236375 Difficulty: Medium

Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return
  [
    ["aa","b"],
    ["a","a","b"]
  ]
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
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

bool is_palindrome(const string& s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        ++i, --j;
    }
    return true;
}

vector<vector<string>> palindrome_partition(string s, int index)
{
    vector<vector<string> > result;
    int ssize = s.size();
    for (int i = index; i < ssize; ++i)
    {
        vector<vector<string> > tempresult;
        if (!is_palindrome(s, index, i))
            continue;
        string subst = s.substr(index, i-index+1);
        if (i+1 == ssize)
        {
            vector<string> v;
            v.emplace_back(subst);
            result.emplace_back(v);
        } else
        {
            tempresult = palindrome_partition(s, i+1);
            for (auto& t: tempresult)
            {
                t.insert(t.begin(), subst);
                result.emplace_back(t);
            }
        }
    }
    
    return result;
}

class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        return palindrome_partition(s, 0);
    }
};

int main()
{
    Solution sol;
    string s;
    vector<vector<string> > result;
    s = "aab";
  
    result = sol.partition(s);
    for (size_t i = 0; i < result.size(); ++i)
    {
        copy(result[i].begin(), result[i].end(),
            ostream_iterator<string>(cout, ", "));
        cout << endl;
    }
    return 0;
}

