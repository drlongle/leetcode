/*
Leftmost Column with at Least a One

This problem is an interactive problem.

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

Example 1:
Input: mat = [[0,0],[1,1]]
Output: 0

Example 2:
Input: mat = [[0,0],[0,1]]
Output: 1

Example 3:
Input: mat = [[0,0],[0,0]]
Output: -1

Example 4:
Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1

Constraints:
1 <= mat.length, mat[i].length <= 100
mat[i][j] is either 0 or 1.
mat[i] is sorted in a non-decreasing way.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class BinaryMatrix {
public:
    BinaryMatrix(vector<vector<int>>&& m): matrix(move(m)) {}
    int get(int x, int y) {return matrix[x][y];}
    vector<int> dimensions() {return {(int) matrix.size(), (int) matrix[0].size()};}
    vector<vector<int>> matrix;
};

class Solution {
public:
    vector<int> cache;
    int rows, columns;
    bool check(BinaryMatrix &matrix, int index) {
        for (int r = 0; r < rows; ++r) {
            if (cache[r] >= 0 && cache[r] >= index)
                continue;
            if (matrix.get(r, index))
                return true;
            cache[r] = index;
        }
        return false;
    }
    
    int leftMostColumnWithOne(BinaryMatrix &matrix) {
        auto dimens = matrix.dimensions();
        rows = dimens[0], columns = dimens[1];
        int lo = 0, hi = columns - 1;
        int res = -1;
        cache.resize(rows, -1);
        while (lo <= hi) {
            int mid = (lo +hi) / 2;
            if (check(matrix, mid)) {
                res = mid;
                hi = mid - 1;
            } else
                lo = mid + 1;
        }
        return res;
    }
};

void test_1() {
    vector<vector<int>> matrix;
    matrix = {{0,0},{1,1}};
    Solution sol;
    BinaryMatrix bm(move(matrix));
    cout << sol.leftMostColumnWithOne(bm) << endl;
}

void test_2() {
    vector<vector<int>> matrix;
    matrix = {{0,0},{0,1}};
    Solution sol;
    BinaryMatrix bm(move(matrix));
    cout << sol.leftMostColumnWithOne(bm) << endl;
}


int main() {
    test_1();
    test_2();
    return 0;
}
