/*
1244. Design A Leaderboard
Medium

Design a Leaderboard class, which has 3 functions:

* addScore(playerId, score): Update the leaderboard by adding score to the given player's score. If there is no player with such id in the leaderboard, add him to the leaderboard with the given score.
* top(K): Return the score sum of the top K players.
* reset(playerId): Reset the score of the player with the given id to 0. It is guaranteed that the player was added to the leaderboard before calling this function.

Initially, the leaderboard is empty.

Example 1:
Input: 
["Leaderboard","addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","top"]
[[],[1,73],[2,56],[3,39],[4,51],[5,4],[1],[1],[2],[2,51],[3]]
Output: 
[null,null,null,null,null,null,73,null,null,null,141]

Explanation: 
Leaderboard leaderboard = new Leaderboard ();
leaderboard.addScore(1,73);   // leaderboard = [[1,73]];
leaderboard.addScore(2,56);   // leaderboard = [[1,73],[2,56]];
leaderboard.addScore(3,39);   // leaderboard = [[1,73],[2,56],[3,39]];
leaderboard.addScore(4,51);   // leaderboard = [[1,73],[2,56],[3,39],[4,51]];
leaderboard.addScore(5,4);    // leaderboard = [[1,73],[2,56],[3,39],[4,51],[5,4]];
leaderboard.top(1);           // returns 73;
leaderboard.reset(1);         // leaderboard = [[2,56],[3,39],[4,51],[5,4]];
leaderboard.reset(2);         // leaderboard = [[3,39],[4,51],[5,4]];
leaderboard.addScore(2,51);   // leaderboard = [[2,51],[3,39],[4,51],[5,4]];
leaderboard.top(3);           // returns 141 = 51 + 51 + 39;
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

class Leaderboard {
public:
    Leaderboard() = default;
    
    void addScore(int playerId, int score) {
        int last_score = players[playerId];
        scores[last_score].erase(playerId);
        int new_score = score + last_score;
        players[playerId] = new_score;
        scores[new_score].emplace(playerId);
    }
    
    int top(int K) {
        int res = 0, count = 0;
        for (auto it = scores.crbegin(); it != scores.crend() && count < K; ++it) {
            res += it->first * min(static_cast<int>(it->second.size()), K- count);
            count += it->second.size();
        }
        return res;
    }
    
    void reset(int playerId) {
        addScore(playerId, -players[playerId]);
    }
    
    unordered_map<int, int> players;
    map<int, set<int>> scores;
};


int main() {
    return 0;
}
