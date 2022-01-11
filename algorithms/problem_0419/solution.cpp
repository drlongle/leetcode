/*
 419. Battleships in a Board

    Total Accepted: 321
    Total Submissions: 579
    Difficulty: Medium
    Contributors: ben65

Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

    You receive a valid board, made of only battleships or empty slots.
    Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column).
    At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.

Example:

X..X
...X
...X

In the above board there are 2 battleships.

Your algorithm should not modify the value of the board.
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
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
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        vector<vector<char>> b;
        b = board;
        int rows = b.size();
        if (!rows) return 0;
        int columns = b[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (b[i][j] != 'X')
                    continue;
                ++res;
                int len = 1;
                for (int k = j+1; k < columns && b[i][k] == 'X'; ++k)
                    ++len;
                bool bflag = true;
                for (int k = i+1; k < rows; ++k) {
                    for (int l = 0; l < len && bflag; ++l) {
                        if (b[k][j+l] != 'X')
                            bflag = false;
                    }
                    for (int l = 0; l < len && bflag; ++l)
                        b[k][j+l] = '.';
                }
                for (int l = 0; l < len; ++l)
                    b[i][j+l] = '.';
            }
        }

        return res;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    vector<vector<char>> board;

    vector<string> input;
    input = {"X..X", "...X", "...X"};
    input = {"X", "X", "X"};
    input = {"XXX"};

    board.resize(input.size());
    for (size_t i = 0; i < input.size(); ++i) {
        for (char c: input[i])
            board[i].emplace_back(c);
    }
    cout << "Result: " << sol.countBattleships(board) << endl;

    return 0;
}

