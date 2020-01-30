/*
1335. Minimum Difficulty of a Job Schedule
Hard

You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the i-th job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done in that day.

Given an array of integers jobDifficulty and an integer d. The difficulty of the i-th job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.

Example 1:
Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7 

Example 2:
Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.

Example 3:
Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.

Example 4:
Input: jobDifficulty = [7,1,7,1,7,1], d = 3
Output: 15

Example 5:
Input: jobDifficulty = [11,111,22,222,33,333,44,444], d = 6
Output: 843

Constraints:
1 <= jobDifficulty.length <= 300
0 <= jobDifficulty[i] <= 1000
1 <= d <= 10
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
    int minDifficulty(vector<int>& job, int D) {
        int sz = job.size();
        if (sz < D)
            return -1;
        vector<int> dp(sz, numeric_limits<int>::max());

        dp[0] = job[0];
        int mx = job[0];
        for (int i = 1; i < sz; ++i) {
            mx = max(mx, job[i]);
            dp[i] = mx;
        }
        
        for (int d = 2; d <= D; ++d) {
            vector<int> new_dp(sz, numeric_limits<int>::max());
            for (int i = d-1; i < sz; ++i) {
                int mx = job[i];
                for (int j = i; j >= d-1; --j) {
                    mx = max(mx, job[j]);
                    new_dp[i] = min(new_dp[i], mx + dp[j-1]);
                }
            }
            dp = new_dp;
        }   
        return dp[sz-1];
    }
};

int main() {
    Solution sol;
    vector<int> jobDifficulty;
    int d;

    // Output: 7
    jobDifficulty = {6,5,4,3,2,1}, d = 2;

    // Output: -1
    jobDifficulty = {9,9,9}, d = 4;

    // Output: 3
    jobDifficulty = {1,1,1}, d = 3;

    // Output: 15
    jobDifficulty = {7,1,7,1,7,1}, d = 3;

    // Output: 843
    jobDifficulty = {11,111,22,222,33,333,44,444}, d = 6;

    cout << "Result: " << sol.minDifficulty(jobDifficulty, d) << endl;
    
    return 0;
}
