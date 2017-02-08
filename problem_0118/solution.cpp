/*
118. Pascal's Triangle
Total Accepted: 87830 Total Submissions: 258114 Difficulty: Easy

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows <= 0)
            return res;

        for (int i = 1; i <= numRows; ++i)
        {
            vector<int> curr(i, 1);
            for (int j = 1; j < i-1; ++j)
                curr[j] = res.back()[j-1] + res.back()[j];

            res.emplace_back(curr);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    int numRows;
    vector<vector<int> > res;
    cout << "Input: ";
    cin >> numRows;
    res = sol.generate(numRows);
    for (auto& r: res)
    {
        copy(r.begin(), r.end(), ostream_iterator<int>(cout, ","));
        cout << endl;
    }

    return 0;
}

