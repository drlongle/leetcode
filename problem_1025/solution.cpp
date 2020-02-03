/*
1025. Divisor Game
Easy

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard. On each player's turn, that player makes a move consisting of:
Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally. 

Example 1:
Input: 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.

Example 2:
Input: 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.

Note:
1 <= N <= 1000
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
    bool divisorGame(int N) {
        dp.resize(1001, -1);
        return play(N);
    }
    
    bool play(int N) {
        if (N == 1)
            return false;
        int res = dp[N];
        if (res >= 0)
            return res;
        if (play(N-1) == false)
            return (dp[N] = true);
        
        int bound = sqrt(N);
        for (int i = 2; i <= bound; ++i) {
            if (N % i == 0 && play(N-i) == false)
                return (dp[N] = true);
        }

        return (dp[N] = false);
    }

    vector<int> dp;
};

int main() {
    Solution sol;
    int n;

    // True
    n = 2;

    // False
    n = 3;

    // False
    n = 5;
    
    cout << "Result: " << sol.divisorGame(n) << endl;
    return 0;
}
