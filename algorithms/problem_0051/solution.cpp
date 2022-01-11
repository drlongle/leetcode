/*
51. N-Queens
Total Accepted: 54805 Total Submissions: 209969 Difficulty: Hard

The n-queens puzzle is the problem of placing n queens on an nxn chessboard
such that no two queens attack each other. Given an integer n, return all distinct solutions to the n-queens puzzle. Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
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

bool good_position(vector<int>& columns, int index)
{
    for (int i = 0; i < index; ++i)
    {
        if (columns[i] == columns[index] ||
            abs(columns[index]-columns[i]) == index-i)
            return false;
    }
    return true;
}

void print_board(vector<int>& columns, vector<vector<string> >& result)
{
    int nsize = columns.size();
    vector<string> one_result;
    for (int i = 0; i < nsize; ++i)
    {
        stringstream ss;
        for (int j = 0; j < nsize; ++j)
            ss << ((columns[i] == j) ? 'Q' : '.');
        one_result.emplace_back(ss.str());
    }
    result.emplace_back(one_result);
}

void solve_n_queens(vector<int>& columns, int index,
    vector<vector<string> >& result)
{
    int nsize = columns.size();
    if (index == nsize)
    {
        print_board(columns, result);
        return;
    }
    
    for (int i = 0; i < nsize; ++i)
    {
        columns[index] = i;
        if (good_position(columns, index))
            solve_n_queens(columns, index+1, result);
    }
}

class Solution {
public:
    vector<vector<string>> solveNQueens(int n);

};

vector<vector<string>> Solution::solveNQueens(int n) {
    vector<vector<string> > result;
    vector<int> columns(n);

    solve_n_queens(columns, 0, result);
    return result;
}

int main()
{
    Solution sol;
    vector<vector<string> > result;
    int n;
  
    n = 1;
    result = sol.solveNQueens(n);
    for (int i = 0; i < static_cast<int>(result.size()); ++i)
    {
        copy(result[i].begin(), result[i].end(),
            ostream_iterator<string>(cout, "\n"));
        cout << endl;
    }
  
    return 0;
}

