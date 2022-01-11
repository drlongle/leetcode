/*
1222. Queens That Can Attack the King
Medium

On an 8x8 chessboard, there can be multiple Black Queens and one White King.

Given an array of integer coordinates queens that represents the positions of the Black Queens,
and a pair of coordinates king that represent the position of the White King,
return the coordinates of all the queens (in any order) that can attack the King.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    double distance(vector<int>& p1, vector<int>& p2) {
        return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
    }
    
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> res;
        vector<vector<int>> candidates(8);
        for (auto& queen: queens) {
            int dfx = queen[0] - king[0];
            int dfy = queen[1] - king[1];
            int index = -1;
            if (dfx == 0) {
                if (dfy > 0)
                    index = 0;
                else
                    index = 1;
            } else if (dfy == 0) {
                if (dfx > 0)
                    index = 2;
                else
                    index = 3;
            } else if (abs(dfx) == abs(dfy)) {
                if (dfx > 0) {
                    if (dfy > 0)
                        index = 4;
                    else
                        index = 5;
                } else {
                    if (dfy > 0)
                        index = 6;
                    else
                        index = 7;
                }
            }
            if (index >= 0) {
                if (candidates[index].empty() || distance(candidates[index], king) > distance(queen, king))
                    candidates[index] = queen;
            }
        }
        for (auto& c: candidates) {
            if (!c.empty())
                res.emplace_back(c);
        }

        return res;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> queens;
    vector<int> king;
    
    // Output: {{0,1},{1,0},{3,3}}
    queens = {{0,1},{1,0},{4,0},{0,4},{3,3},{2,4}}, king = {0,0};

    // Output: {{2,2},{3,4},{4,4}}
    queens = {{0,0},{1,1},{2,2},{3,4},{3,5},{4,4},{4,5}}, king = {3,3};

    // Output: {{2,3},{1,4},{1,6},{3,7},{4,3},{5,4},{4,5}}
    queens = {{5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7}};
    king = {3,4};

    auto res = sol.queensAttacktheKing(queens, king);
    for (auto& q: res)
        cout << q[0] << ", " << q[1] << endl;
    
    return 0;
}
