/*
294. Flip Game II
Medium

You are playing a Flip Game with your friend.

You are given a string currentState that contains only '+' and '-'. You and your friend take
turns to flip two consecutive "++" into "--". The game ends when a person can no longer make
a move, and therefore the other person will be the winner.

Return true if the starting player can guarantee a win, and false otherwise.

Example 1:
Input: currentState = "++++"
Output: true
Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Example 2:
Input: currentState = "+"
Output: false

Constraints:
1 <= currentState.length <= 60
currentState[i] is either '+' or '-'.

Follow up: Derive your algorithm's runtime complexity.
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
    unordered_map<string, bool> dp;

    bool canWin(string s) {
        auto it = dp.find(s);
        if (it != dp.end())
            return it->second;
        bool res = false;
        for (int i=1, n = s.size (); i < n && !res; ++i) {
            if (s[i-1]==s[i] && s[i]=='+'){
                s[i-1]=s[i]='-';
                if (!canWin(s))
                    res = true;
                s[i-1]=s[i]='+';
            }
        }

        return dp[s] = res;
    }
};

int main() {
    Solution sol;

    return 0;
}
