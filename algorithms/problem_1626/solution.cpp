/*
1626. Best Team With No Conflicts
Medium

You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest
overall score. The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly
higher score than an older player. A conflict does not occur between players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player,
respectively, return the highest overall score of all possible basketball teams.

Example 1:
Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
Output: 34
Explanation: You can choose all the players.

Example 2:
Input: scores = [4,5,6,5], ages = [2,1,2,1]
Output: 16
Explanation: It is best to choose the last 3 players. Notice that you are allowed to choose multiple people of the same age.

Example 3:
Input: scores = [1,2,3,5], ages = [8,9,10,1]
Output: 6
Explanation: It is best to choose the first 3 players.

Constraints:
1 <= scores.length, ages.length <= 1000
scores.length == ages.length
1 <= scores[i] <= 10^6
1 <= ages[i] <= 1000
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
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

using namespace std;

/*
Idea is to first sort the players by their age so that we don't have to always check both the scores and
the age to see whether these two players can be in the same team.

We sort first in the descending order of the ages.

Now we know that for any player i, we can choose any player from 0 to i-1 as long as that player has higher
score than this i-th player.

dp[i] stores the maximum score that can be obtained when i-th player is included and
all other players are between indices 0 and i-1.

Once we get the answer for all indices, we can simply find the max and that will be the answer.
*/

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int sz = ages.size();
        vector<pair<int, int>> persons;
        vector<int> dp(sz);
        for (int i = 0; i < sz; ++i) {
            persons.emplace_back(ages[i], scores[i]);
        }
        sort(begin(persons), end(persons), greater<>());
        int ans = 0;
        for (int i = 0; i < sz; ++i) {
            int score = persons[i].second;
            dp[i] = score;
            for (int j = 0; j < i; ++j) {
                // age of j is certainly >= i, so the only important part is to check
                // the score before we add i and j to the same team.
                if (persons[j].second >= score) {
                    dp[i] = max(dp[i], dp[j] + score);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> scores, ages;

    // Output: 34
    scores = {1,3,5,10,15}, ages = {1,2,3,4,5};
    cout << sol.bestTeamScore(scores, ages) << endl;

    // Output: 16
    scores = {4,5,6,5}, ages = {2,1,2,1};
    cout << sol.bestTeamScore(scores, ages) << endl;

    // Output: 6
    scores = {1,2,3,5}, ages = {8,9,10,1};
    cout << sol.bestTeamScore(scores, ages) << endl;

    // Output: 29
    scores = {1,3,7,3,2,4,10,7,5}, ages = {4,5,2,1,1,2,4,1,4};
    cout << sol.bestTeamScore(scores, ages) << endl;

    // Output: 3578
    scores = {675,541,232,428,760,11,136,890,984,695,249,558};
    ages = {93,100,100,73,68,14,68,74,76,18,7,54};
    cout << sol.bestTeamScore(scores, ages) << endl;

    // Output: 3287
    scores = {596,277,897,622,500,299,34,536,797,32,264,948,645,537,83,589,770};
    ages = {18,52,60,79,72,28,81,33,96,15,18,5,17,96,57,72,72};
    cout << sol.bestTeamScore(scores, ages) << endl;

    return 0;
}
