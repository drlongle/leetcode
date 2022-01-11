/*
85. Maximal Rectangle
Total Accepted: 42292 Total Submissions: 179161 Difficulty: Hard

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area. 
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
    int maximalRectangle(vector<vector<char>>& matrix) ;
};

int Solution::maximalRectangle(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    if (!rows)
        return 0;
    int columns = matrix[0].size();
    if (!columns)
        return 0;
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
                if (area < index*w)
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

    // Expected: 21
    vector<string> strings =
        {"11111111","11111110","11111110","11111000","01111000"};

    matrix.resize(strings.size());
    for (int i = 0; i < static_cast<int>(strings.size()); ++i)
    {
        matrix[i].clear();
        copy(strings[i].begin(), strings[i].end(), back_inserter(matrix[i]));
    }
    cout << "Result: " << sol.maximalRectangle(matrix) << endl;

    return 0;
}

