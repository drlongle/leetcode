/*
240. Search a 2D Matrix II

Total Accepted: 34513 Total Submissions: 100388 Difficulty: Medium

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

For example,
Consider the following matrix:
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given target = 5, return true.

Given target = 20, return false.
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

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size, column_size;
        row_size = matrix.size();
        if (!row_size) return false;
        column_size = matrix[0].size();
        int row = 0;
        int column = column_size-1;
        while (row < row_size && column >= 0)
        {
            if (matrix[row][column] == target)
                return true;
            else if (matrix[row][column] > target)
                column--;
            else
                row++;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int> > matrix;
    int target;
    
    matrix =
    {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    target = 20;
    cout << "Result: " << boolalpha << sol.searchMatrix(matrix, target) << endl;

    return 0;
}

