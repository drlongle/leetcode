/*
74. Search a 2D Matrix

Total Accepted: 76812 Total Submissions: 227707 Difficulty: Medium

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return true. 
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
        row_size = matrix.size();
        if (!row_size)
            return false;
        column_size = matrix[0].size();

        int begin = 0, end = rowColumnToIndex(row_size-1, column_size-1);
        while (begin <= end)
        {
            int mid = begin + ((end-begin) >> 1);
            pair<int,int> index = indexToRowColumn(mid);
            if (matrix[index.first][index.second] == target)
                return true;
            else if (matrix[index.first][index.second] > target)
                end = mid-1;
            else
                begin = mid+1;
        }

        return false;
    }
    
    int rowColumnToIndex(int row, int column)
    {
        return row*column_size + column;
    }
    
    pair<int,int> indexToRowColumn(int index)
    {
        int row = index / column_size;
        int column = index - row*column_size;
        return make_pair(row,column);
    }

    int row_size, column_size;
};

int main()
{
    Solution sol;
    vector<vector<int> > matrix;
    int target;
  
    matrix = { {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50} };
    target = 3;
    cout << "Result: " << boolalpha << sol.searchMatrix(matrix, target) << endl;

    return 0;
}

