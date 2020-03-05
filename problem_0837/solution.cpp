/*
837. New 21 Game
Medium

Alice plays the following game, loosely based on the card game "21".

Alice starts with 0 points, and draws numbers while she has less than K points.  During each draw, she gains an integer number of points randomly from the range [1, W], where W is an integer.  Each draw is independent and the outcomes have equal probabilities.

Alice stops drawing numbers when she gets K or more points. What is the probability that she has N or less points?

Example 1:
Input: N = 10, K = 1, W = 10
Output: 1.00000
Explanation: Alice gets a single card, then stops.

Example 2:
Input: N = 6, K = 1, W = 10
Output: 0.60000
Explanation: Alice gets a single card, then stops.
In 6 out of W = 10 possibilities, she is at or below N = 6 points.

Example 3:
Input: N = 21, K = 17, W = 10
Output: 0.73278

Note:
0 <= K <= N <= 10000
1 <= W <= 10000
Answers will be accepted as correct if they are within 10^-5 of the correct answer.
The judging time limit has been reduced for this question.
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
    double new21Game(int N, int K, int W) {
        if(K == 0) {
            return 1;
        }
        if(N == 0) {
            return 0;
        }
        if(K > N) {
            return 0;
        }
        // dp[i] represent that the probability when get i points totally, final answer is sum(dp[k:])
        vector<double>dp(N + 1, 0);
        dp[0] = 1.0;
        double ans = 0.0;
        double psum = 1.0;
        for(int i = 1; i <= N; i++) {
            dp[i] = 1.0 * psum / W;
            if(i < K) {
                psum += dp[i];
            }
            else {
                ans += dp[i];
            }
            if(i >= W) { 
                psum -= dp[i - W];
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    int K, N, W;

    // Output: 1.00000
    N = 10, K = 1, W = 10;
    //cout << sol.new21Game(N, K, W) << endl;
    
    // Output: 0.60000
    N = 6, K = 1, W = 10;
    //cout << sol.new21Game(N, K, W) << endl;
    
    // Output: 0.73278
    N = 21, K = 17, W = 10;
    cout << sol.new21Game(N, K, W) << endl;

    // Output: 1.0
    N = 0, K = 0, W = 1;
    cout << sol.new21Game(N, K, W) << endl;

    // Output: 1.0
    N = 1, K = 0, W = 1;
    cout << sol.new21Game(N, K, W) << endl;
    
    // Output: 1.0
    N = 0, K = 0, W = 2;
    cout << sol.new21Game(N, K, W) << endl;

    // Output: 0.88889
    N = 3, K = 2, W = 3;
    cout << sol.new21Game(N, K, W) << endl;

    N = 421, K = 400, W = 47;
    cout << sol.new21Game(N, K, W) << endl;

    N = 9811, K = 8776, W = 1096;
    cout << sol.new21Game(N, K, W) << endl;
    
    return 0;
}
