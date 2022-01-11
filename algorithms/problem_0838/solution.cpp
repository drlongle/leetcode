/*
838. Push Dominoes
Medium

There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously
push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly,
the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to
a falling or already fallen domino.

You are given a string dominoes representing the initial state where:
dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.

Example 1:
Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.

Example 2:
Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."

Constraints:
n == dominoes.length
1 <= n <= 10^5
dominoes[i] is either 'L', 'R', or '.'.
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        queue<int> q;
        int n = dominoes.size();
        for (int i = 0; i < n; ++i) {
            char& c = dominoes[i];
            if (c != '.')
                q.push(i);
        }

        unordered_map<int, char> candidates;
        while (!q.empty()) {
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                if (dominoes[i] == 'L' && i > 0 && dominoes[i-1] == '.') {
                    auto [it, inserted] = candidates.emplace(i-1, 'L');
                    if (!inserted)
                        candidates.erase(it);
                }
                if (dominoes[i] == 'R' && i + 1 < n && dominoes[i+1] == '.') {
                    auto [it, inserted] = candidates.emplace(i + 1, 'R');
                    if (!inserted) {
                        candidates.erase(it);
                    }
                }
            }
            for (auto [i, c]: candidates) {
                q.push(i);
                dominoes[i] = c;
            }
            candidates.clear();
        }

        return dominoes;
    }
};

int main() {
    Solution sol;
    string dominoes;

    // Output: "RR.L"
    dominoes = "RR.L";
    cout << sol.pushDominoes(dominoes) << endl;

    // Output: "LL.RR.LLRRLL.."
    dominoes = ".L.R...LR..L..";
    cout << sol.pushDominoes(dominoes) << endl;

    return 0;
}
