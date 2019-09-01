/*
1176. Diet Plan Performance
Easy

A dieter consumes calories[i] calories on the i-th day.  For every consecutive sequence of
k days, they look at T, the total calories consumed during that sequence of k days:

If T < lower, they performed poorly on their diet and lose 1 point;
If T > upper, they performed well on their diet and gain 1 point;
Otherwise, they performed normally and there is no change in points.
Return the total number of points the dieter has after all calories.length days.

Note that: The total points could be negative.

Example 1:
Input: calories = [1,2,3,4,5], k = 1, lower = 3, upper = 3
Output: 0
Explaination: calories[0], calories[1] < lower and calories[3], calories[4] > upper, total points = 0.

Example 2:
Input: calories = [3,2], k = 2, lower = 0, upper = 1
Output: 1
Explaination: calories[0] + calories[1] > upper, total points = 1.

Example 3:
Input: calories = [6,5,0,0], k = 2, lower = 1, upper = 5
Output: 0
Explaination: calories[0] + calories[1] > upper, calories[2] + calories[3] < lower, total points = 0.
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
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper)
    {
        int sum = accumulate(begin(calories), begin(calories) + k, 0);
        int points = 0;

        auto update = [&points, lower, upper](int sum) {
            if (sum < lower)
                --points;
            else if (sum > upper)
                ++points;
        };

        update(sum);
        for (int i = k; i < static_cast<int>(calories.size()); ++i) {
            sum -= calories[i - k];
            sum += calories[i];
            update(sum);
        }

        return points;
    }
};

int main()
{
    Solution sol;
    vector<int> calories;
    int k, lower, upper;

    // Output: 0
    calories = {1, 2, 3, 4, 5}, k = 1, lower = 3, upper = 3;

    // Output: 1
    calories = {3, 2}, k = 2, lower = 0, upper = 1;

    // Output: 0
    calories = {6, 5, 0, 0}, k = 2, lower = 1, upper = 5;

    cout << "Result: " << sol.dietPlanPerformance(calories, k, lower, upper) << endl;

    return 0;
}
