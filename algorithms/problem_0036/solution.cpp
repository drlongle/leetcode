/*
36. Valid Sudoku

Determine if a Sudoku is valid, according to http://sudoku.com.au/TheRules.aspx. The Sudoku board could be partially filled, where empty cells are filled with the character '-'. Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated. 
*/

#include <algorithm>
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

class Solution {
public:

    static const int ROW_SIZE = 9;
    static const int COLUMN_SIZE = 9;
    static const int NR_ROWS = 9;
    static const int NR_COLUMNS = 9;

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
  vector<string> input;

  input  = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};

  for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j)
          board[i][j] = input[i][j];

  cout << "Result: " << sol.isValidSudoku(board) << endl;
  return 0;
}

