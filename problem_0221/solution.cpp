/*
221. Maximal Square
Total Accepted: 30047 Total Submissions: 126573 Difficulty: Medium

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4.
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) ;
};

int Solution::maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    if (!rows) return 0;
    int columns = matrix[0].size();
    if (!columns) return 0;
    vector<vector<int>> height =
        vector<vector<int>>(rows, vector<int>(columns,0));
    vector<vector<int>> width =
        vector<vector<int>>(rows, vector<int>(columns,0));
    int area = 0;
    for (int i = rows-1; i >= 0; --i)
        for (int j = columns-1; j >= 0; --j)
        {
            if (matrix[i][j] == '0')
                height[i][j] = 0;
            else
                height[i][j] = 1 + ((i == rows-1) ? 0 : height[i+1][j]);
        }

    for (int i = rows-1; i >= 0; --i)
        for (int j = columns-1; j >= 0; --j)
        {
            if (matrix[i][j] == '0')
                width[i][j] = 0;
            else
                width[i][j] = 1 + ((j == columns-1) ? 0 : width[i][j+1]);
        }

    for (int i = rows-1; i >= 0; --i)
        for (int j = columns-1; j >= 0; --j)
        {
            int h = height[i][j];
            int w = numeric_limits<int>::max();
            for (int index = 1; index <= h; ++index)
            {
                if (width[i+index-1][j] < w)
                    w = width[i+index-1][j];
                if (index == w && area < index*w)
                    area = index*w;
            }
        }

    return area;
}

int main()
{
    Solution sol;
    vector<vector<char>> matrix;
    matrix = { {'1','1','1'}, {'1','1','1'}};

    vector<string> strings =
        {"11111111","11111110","11111110","11111000","01111000"};
    matrix.resize(strings.size());
    for (int i = 0; i < static_cast<int>(strings.size()); ++i)
    {
        matrix[i].clear();
        copy(strings[i].begin(), strings[i].end(), back_inserter(matrix[i]));
    }
    cout << "Result: " << sol.maximalSquare(matrix) << endl;

    return 0;
}

