/*
293. Flip Game
Easy

You are playing a Flip Game with your friend.

You are given a string currentState that contains only '+' and '-'. You and your friend take turns to
flip two consecutive "++" into "--". The game ends when a person can no longer make a move, and
therefore the other person will be the winner.

Return all possible states of the string currentState after one valid move. You may return the
answer in any order. If there is no valid move, return an empty list [].

Example 1:
Input: currentState = "++++"
Output: ["--++","+--+","++--"]

Example 2:
Input: currentState = "+"
Output: []

Constraints:
1 <= currentState.length <= 500
currentState[i] is either '+' or '-'.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector <string > res;
        for (int i=1, n = s.size (); i < n; ++i) {
            if (s[i-1]==s[i] && s [i]=='+'){
                s[i-1]=s[i]='-';
                res.push_back(s);
                s[i-1]=s[i]='+';
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
