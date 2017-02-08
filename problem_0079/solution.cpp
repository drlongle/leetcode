/*
79. Word Search
Total Accepted: 77855 Total Submissions: 334028 Difficulty: Medium

Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
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

bool search(vector<vector<char>>& board, int i, int j, string& word,
  size_t index, vector<vector<bool> >& used)
{
    if (index+1 == word.size())
        return true;
    int rows = board.size();
    int columns = board[0].size();
    array<array<int,2>, 4> offsets = {1,0,-1,0,0,1,0,-1};
    used[i][j] = true;
    char next_ch = word[index+1];
    for (const auto& offset: offsets)
    {
        int next_i = i + offset[0];
        int next_j = j + offset[1];
        if (next_i >= 0 && next_i < rows && next_j >= 0 && next_j < columns &&
            !used[next_i][next_j] && next_ch == board[next_i][next_j] &&
            search(board, next_i, next_j, word, index+1, used))
            return true;
    }
    used[i][j] = false;

    return false;
}

bool sanity_check(vector<vector<char>>& board, string word)
{
    unordered_map<char, int> count;
    for (auto& w: word)
        ++count[w];

    unordered_map<char,int>::iterator it;
    for (int i = 0; i < static_cast<int>(board.size()); ++i)
        for (int j = 0; j < static_cast<int>(board[0].size()); ++j)
        {
            char ch = board[i][j];
            it = count.find(ch);
            if (it != count.end())
            {
                if (--it->second == 0)
                    count.erase(it);
            }
        }

    return count.empty();
}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty())
            return true;
        int rows = board.size();
        if (!rows)
            return false;
        int columns = board[0].size();
        vector<vector<bool> > used =
            vector<vector<bool>>(rows, vector<bool>(columns,false));
        if (!sanity_check(board, word))
            return false;

        char ch = word[0];
        for (int i = 0; i < static_cast<int>(board.size()); ++i)
            for (int j = 0; j < static_cast<int>(board[0].size()); ++j)
            {
                if (ch == board[i][j] && search(board, i, j, word, 0, used))
                    return true;
            }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board;
    vector<string> input;
    string word;
    input = {"ABCE","SFCS","ADEE"};
    word = "ABCCED";

    board = vector<vector<char>>(input.size());
    for (size_t i =  0; i < input.size(); ++i)
    {
        string& s = input[i];
        copy(s.begin(), s.end(), back_inserter(board[i]));
    }
    cout << "Result: " << boolalpha << sol.exist(board, word) << endl;

    return 0;
}

