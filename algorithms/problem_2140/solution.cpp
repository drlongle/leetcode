/*
2140. Solving Questions With Brainpower
Medium

You are given a 0-indexed 2D integer array questions where questions[i] = [points[i], brainpower[i]].

The array describes the questions of an exam, where you have to process the questions in order
(i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question
i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions.
If you skip question i, you get to make the decision on the next question.

For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be
unable to solve questions 2 and 3. Return the maximum points you can earn for the exam.

Example 1:
Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.

Example 2:
Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.

Constraints:
1 <= questions.length <= 10^5
questions[i].length == 2
1 <= points[i], brainpower[i] <= 10^5
*/

#include <algorithm>
#include <atomic>
#include <bit>
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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
public:
    vector<long> dp;
    int sz;

    long long solve(vector<vector<int>>& questions, int index) {
        if (index >= sz) {
            return 0;
        }
        if (dp[index]!= -1) {
            return dp[index];
        }
        auto a = questions[index][0]+ solve(questions, index + 1 + questions[index][1]);
        auto b = solve(questions, index + 1);
        dp[index] = max(a, b);

        return dp[index];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        sz = questions.size();
        dp.resize(sz, -1);
        return solve(questions, 0);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> questions;

    questions = {{3,2},{4,3},{4,4},{2,5}};
    cout << sol.mostPoints(questions) << std::endl;

    questions = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    cout << sol.mostPoints(questions) << std::endl;

    return 0;
}
