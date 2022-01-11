/*
52. N-Queens II
Total Accepted: 44869 Total Submissions: 113129 Difficulty: Hard

Follow up for N-Queens problem. Now, instead outputting board configurations, return the total number of distinct solutions.
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
        if (columns[i] == columns[index] || abs(columns[index]-columns[i]) == index-i)
            return false;
    }
    return true;
}

int solve_n_queens(vector<int>& columns, int index)
{
    int nsize = columns.size();
    int result = 0;
    
    for (int i = 0; i < nsize; ++i)
    {
        columns[index] = i;
        if (good_position(columns, index))
        {
            if (index == nsize-1)
                ++result;
            else
                result += solve_n_queens(columns, index+1);
        }
    }
    
    return result;
}

class Solution {
public:
    int totalNQueens(int n);
};

int Solution::totalNQueens(int n) {
    vector<int> columns(n);
    return solve_n_queens(columns, 0);
}

int main()
{
    Solution sol;
    int n;
  
    // Expected: 2
    n = 4;
    cout << "Result: " << sol.totalNQueens(n) << endl;
  
    return 0;
}

