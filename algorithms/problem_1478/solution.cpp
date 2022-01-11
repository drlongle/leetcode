/*
1478. Allocate Mailboxes
Hard

Given the array houses and an integer k. where houses[i] is the location of the ith house
along a street, your task is to allocate k mailboxes in the street.

Return the minimum total distance between each house and its nearest mailbox.

The answer is guaranteed to fit in a 32-bit signed integer.

Example 1:
Input: houses = [1,4,8,10,20], k = 3
Output: 5
Explanation: Allocate mailboxes in position 3, 9 and 20.
Minimum total distance from each houses to nearest mailboxes is |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 

Example 2:
Input: houses = [2,3,5,12,18], k = 2
Output: 9
Explanation: Allocate mailboxes in position 3 and 14.
Minimum total distance from each houses to nearest mailboxes is |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9.

Example 3:
Input: houses = [7,4,6,1], k = 1
Output: 8

Example 4:
Input: houses = [3,6,14,10], k = 4
Output: 0

Constraints:
n == houses.length
1 <= n <= 100
1 <= houses[i] <= 10^4
1 <= k <= n
Array houses contain unique integers.
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:

    int get_cost(vector<int> &houses, int i, int j)
    {
        int c = 0;
        while (i < j) {
            c += houses[j] - houses[i];
            ++i, --j;
        }
        return c;
    }

    vector<vector<int>> cost;

    int minDistance(vector<int> &houses, int K)
    {
        sort(begin(houses), end(houses));
        int n = houses.size();
        vector<int> dp(n), ndp(n);
        cost.resize(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= i; ++j)
            {
                cost[j][i] = get_cost(houses, j, i);
            }

        for (int i = 0; i < n; ++i)
            dp[i] = cost[0][i];
        for (int k = 2; k <= K; ++k)
        {
            for (int i = k - 1; i < n; ++i)
            {
                ndp[i] = numeric_limits<int>::max();
                for (int j = k - 1; j <= i; ++j)
                {
                    ndp[i] = min(ndp[i], cost[j][i] + ((k == 1) ? 0 : dp[j - 1]));
                }
            }

            swap(dp, ndp);
        }
        return dp[n - 1];
    }
};

int main()
{
    vector<int> houses;
    int k;

    {
        // Output: 5
        Solution sol;
        houses = {1, 4, 8, 10, 20}, k = 3;
        cout << sol.minDistance(houses, k) << endl;
    }

    {
        // Output: 9
        Solution sol;
        houses = {2, 3, 5, 12, 18}, k = 2;
        cout << sol.minDistance(houses, k) << endl;
    }

    {
        // Output: 8
        Solution sol;
        houses = {7, 4, 6, 1}, k = 1;
        cout << sol.minDistance(houses, k) << endl;
    }

    {
        // Output: 0
        Solution sol;
        houses = {3, 6, 14, 10}, k = 4;
        cout << sol.minDistance(houses, k) << endl;
    }

    {
        // Output: 2904
        Solution sol;
        houses = {2973, 9950, 709, 7492, 6043, 9053, 2839, 5183, 3894, 1151, 7039, 4145, 2710, 179, 9365, 1798, 1643, 3138, 8886, 5935, 2507, 8727, 4128, 6065, 2746, 319, 5074, 822, 8739, 1536, 7450, 272, 6181, 1511, 1645, 745, 1001, 2947, 5308, 3599, 677, 8064, 8654, 1533, 2519, 1686, 5940, 5913, 848, 154, 3683, 8091, 3846, 6847, 2367, 5822, 9141, 1894, 9898, 3390, 1165, 7150, 5955, 2326, 9114, 1025, 5994, 4713, 7339, 2854, 2338, 7611, 747, 7963};
        k = 27;
        cout << sol.minDistance(houses, k) << endl;
    }

    return 0;
}
