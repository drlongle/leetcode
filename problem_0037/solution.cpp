/*
37. Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells. Empty cells are indicated by the character '.'. You may assume that there will be only one unique solution. 
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
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

#include <string.h>

using namespace std;

class Cell
{
public:
    Cell(int row, int column) : m_row(row), m_column(column)
    {

    }

    int m_row, m_column;
};

class Solution {
public:
    static const int ROW_SIZE = 9;
    static const int COLUMN_SIZE = 9;
    static const int NR_ROWS = 9;
    static const int NR_COLUMNS = 9;

    bool solveSudoku(vector<vector<char>>& board, deque<Cell>& misscells)
    {
        if (misscells.empty())
            return true;

        Cell cell = misscells.front();
        misscells.pop_front();
        int row = cell.m_row;
        int column = cell.m_column;
        assert(!isdigit(board[row][column]));
        set<char> scratch{'1','2','3','4','5','6','7','8','9'};

        for (int i = 0; i < ROW_SIZE; ++i)
        {
            char ch = board[row][i];
            if (isdigit(ch))
                scratch.erase(ch);
        }

        for (int i = 0; i < COLUMN_SIZE; ++i)
        {
            char ch = board[i][column];
            if (isdigit(ch))
                scratch.erase(ch);
        }

        int matrix_row = row / 3;
        int matrix_column = column / 3;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                char ch = board[matrix_row*3+i][matrix_column*3+j];
                if (isdigit(ch))
                    scratch.erase(ch);
            }
        }

        for (const auto s: scratch)
        {
            board[row][column] = s;
            if (solveSudoku(board, misscells))
                return true;
        }

        misscells.emplace_front(cell);
        board[row][column] = '.';

        return false;
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        deque<Cell> misscells;
        for (int row = 0; row < NR_ROWS; ++row)
            for (int column = 0; column < NR_COLUMNS; ++column)
                if(!isdigit(board[row][column]))
                    misscells.emplace_back(row, column);
        solveSudoku(board, misscells);
    }

    void printBoard(vector<vector<char>>& board)
    {
        for (int row = 0; row < NR_ROWS; ++row)
        {
            for (int column = 0; column < NR_COLUMNS; ++column)
                cout << board[row][column];
            cout << endl;
        }
    }

    bool compareBoard(vector<vector<char>>& board1,vector<vector<char>>& board2)
    {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board1[i][j] != board2[i][j]) return false;
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (int i = 0; i < NR_ROWS; ++i)
            if (!isValidRow(board,i)) return false;

        for (int i = 0; i < NR_COLUMNS; ++i)
            if (!isValidColumn(board,i)) return false;

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (!isValidMatrix(board,i,j)) return false;

        return true;
    }

    bool isValidRow(vector<vector<char> >& board, int row)
    {
        set<char> scratch;
        for (int i = 0; i < ROW_SIZE; ++i)
        {
            char ch = board[row][i];
            if (isdigit(ch))
            {
                if (scratch.find(ch) != scratch.end())
                    return false;
                else
                    scratch.emplace(ch);
            }
        }
        return true;
    }

    bool isValidColumn(vector<vector<char> >& board, int column)
    {
        set<char> scratch;
        for (int i = 0; i < COLUMN_SIZE; ++i)
        {
            char ch = board[i][column];
            if (isdigit(ch))
            {
                if (scratch.find(ch) != scratch.end())
                    return false;
                else
                    scratch.emplace(ch);
            }
        }
        return true;
    }

    bool isValidMatrix(vector<vector<char> >& board, int row, int column)
    {
        set<char> scratch;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                char ch = board[row*3+i][column*3+j];
                if (isdigit(ch))
                {
                    if (scratch.find(ch) != scratch.end())
                        return false;
                    else
                        scratch.emplace(ch);
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board(9, vector<char>(9));
    vector<vector<char>> expected_board(9, vector<char>(9));
    vector<string> input;

    vector<string> expected_output = {"534678912","672195348","198342567","859761423","426853791","713924856","961537284","287419635","345286179"};
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            expected_board[i][j] = expected_output[i][j];

    input  = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            board[i][j] = input[i][j];

    sol.solveSudoku(board);
    cout << "Compare: " << sol.compareBoard(board, expected_board) << endl;
    cout << "Valid board: " << sol.isValidSudoku(board) << endl;
    sol.printBoard(board);

    return 0;
}
