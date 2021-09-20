/*
568. Maximum Vacation Days
Hard

LeetCode wants to give one of its best employees the option to travel among n cities to collect algorithm problems.
But all work and no play makes Jack a dull boy, you could take vacations in some particular cities and weeks.
Your job is to schedule the traveling to maximize the number of vacation days you could take, but there are certain
rules and restrictions you need to follow.

Rules and restrictions:
- You can only travel among n cities, represented by indexes from 0 to n - 1. Initially, you are in the city indexed 0 on Monday.
- The cities are connected by flights. The flights are represented as an n x n matrix (not necessarily symmetrical),
  called flights representing the airline status from the city i to the city j. If there is no flight from the city i
  to the city j, flights[i][j] == 0; Otherwise, flights[i][j] == 1. Also, flights[i][i] == 0 for all i.
- You totally have k weeks (each week has seven days) to travel. You can only take flights at most once per day and can
  only take flights on each week's Monday morning. Since flight time is so short, we do not consider the impact of flight time.
- For each city, you can only have restricted vacation days in different weeks, given an n x k matrix called days
  representing this relationship. For the value of days[i][j], it represents the maximum days you could take a vacation
  in the city i in the week j.
- You could stay in a city beyond the number of vacation days, but you should work on the extra days, which will
  not be counted as vacation days.
- If you fly from city A to city B and take the vacation on that day, the deduction towards vacation days will
  count towards the vacation days of city B in that week.
- We do not consider the impact of flight hours on the calculation of vacation days.
Given the two matrices flights and days, return the maximum vacation days you could take during k weeks.

Example 1:
Input: flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[1,3,1],[6,0,3],[3,3,3]]
Output: 12
Explanation:
One of the best strategies is:
1st week : fly from city 0 to city 1 on Monday, and play 6 days and work 1 day.
(Although you start at city 0, we could also fly to and start at other cities since it is Monday.)
2nd week : fly from city 1 to city 2 on Monday, and play 3 days and work 4 days.
3rd week : stay at city 2, and play 3 days and work 4 days.
Ans = 6 + 3 + 3 = 12.

Example 2:
Input: flights = [[0,0,0],[0,0,0],[0,0,0]], days = [[1,1,1],[7,7,7],[7,7,7]]
Output: 3
Explanation:
Since there are no flights that enable you to move to another city, you have to stay at city 0 for the whole 3 weeks.
For each week, you only have one day to play and six days to work.
So the maximum number of vacation days is 3.
Ans = 1 + 1 + 1 = 3.

Example 3:
Input: flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[7,0,0],[0,7,0],[0,0,7]]
Output: 21
Explanation:
One of the best strategies is:
1st week : stay at city 0, and play 7 days.
2nd week : fly from city 0 to city 1 on Monday, and play 7 days.
3rd week : fly from city 1 to city 2 on Monday, and play 7 days.
Ans = 7 + 7 + 7 = 21

Constraints:
n == flights.length
n == flights[i].length
n == days.length
k == days[i].length
1 <= n, k <= 100
flights[i][j] is either 0 or 1.
0 <= days[i] <= 7
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

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), K = days[0].size(), res = 0;
        vector<vector<int>> dp(K, vector<int>(n, 0));
        for (int k = K - 1; k >= 0; --k) {
            for (int i = 0; i < n; ++i) {
                dp[k][i] = days[i][k];
                if (k == K - 1)
                    continue;
                int t = 0;
                for (int j = 0; j < n; ++j) {
                    if (flights[i][j] || i == j) {
                        t = max(t, dp[k+1][j]);
                    }
                }
                dp[k][i] += t;
                if (k == 0 && (i == 0 || flights[0][i]))
                    res = max(res, dp[0][i]);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
