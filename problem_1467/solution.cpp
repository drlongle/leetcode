/*
1467. Probability of a Two Boxes Having The Same Number of Distinct Balls
Hard

Given 2n balls of k distinct colors. You will be given an integer array balls of size k where balls[i] is the number of balls of color i. 

All the balls will be shuffled uniformly at random, then we will distribute the first n balls to the first box and the remaining n balls to the other box (Please read the explanation of the second example carefully).

Please note that the two boxes are considered different. For example, if we have two balls of colors a and b, and two boxes [] and (), then the distribution [a] (b) is considered different than the distribution [b] (a) (Please read the explanation of the first example carefully).

We want to calculate the probability that the two boxes have the same number of distinct balls.

Example 1:
Input: balls = [1,1]
Output: 1.00000
Explanation: Only 2 ways to divide the balls equally:
- A ball of color 1 to box 1 and a ball of color 2 to box 2
- A ball of color 2 to box 1 and a ball of color 1 to box 2
In both ways, the number of distinct colors in each box is equal. The probability is 2/2 = 1

Example 2:
Input: balls = [2,1,1]
Output: 0.66667
Explanation: We have the set of balls [1, 1, 2, 3]
This set of balls will be shuffled randomly and we may have one of the 12 distinct shuffles with equale probability (i.e. 1/12):
[1,1 / 2,3], [1,1 / 3,2], [1,2 / 1,3], [1,2 / 3,1], [1,3 / 1,2], [1,3 / 2,1], [2,1 / 1,3], [2,1 / 3,1], [2,3 / 1,1], [3,1 / 1,2], [3,1 / 2,1], [3,2 / 1,1]
After that we add the first two balls to the first box and the second two balls to the second box.
We can see that 8 of these 12 possible random distributions have the same number of distinct colors of balls in each box.
Probability is 8/12 = 0.66667

Example 3:
Input: balls = [1,2,1,2]
Output: 0.60000
Explanation: The set of balls is [1, 2, 2, 3, 4, 4]. It is hard to display all the 180 possible random shuffles of this set but it is easy to check that 108 of them will have the same number of distinct colors in each box.
Probability = 108 / 180 = 0.6

Example 4:
Input: balls = [3,2,1]
Output: 0.30000
Explanation: The set of balls is [1, 1, 1, 2, 2, 3]. It is hard to display all the 60 possible random shuffles of this set but it is easy to check that 18 of them will have the same number of distinct colors in each box.
Probability = 18 / 60 = 0.3

Example 5:
Input: balls = [6,6,6,6,6,6]
Output: 0.90327

Constraints:
1 <= balls.length <= 8
1 <= balls[i] <= 6
sum(balls) is even.
Answers within 10^-5 of the actual value will be accepted as correct.
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

#define ll long long

class Solution {
public:
    int n, sz;
    double total, match;
    static constexpr int fact[7] = {1, 1, 2, 6, 24, 120, 720};
    void dfs(vector<int>& balls, int cnt1, int cnt2, int color1, int color2, int index, double permu1, double permu2) {
        if (cnt1 > n/2 || cnt2 > n/2)
            return;
        if (index == sz) {
            double prod = permu1 * permu2;
            total += prod;
            match += (color1 == color2) ? prod : 0;
        } else {
            for (int j = 0, k = balls[index]; k >= 0; ++j, --k) {
                dfs(balls, cnt1 + j, cnt2 + k, color1 + (j > 0), color2 + (k > 0),
                    index+1, permu1 / fact[j], permu2 / fact[k]);
            }
        }
    }
    double factorial(int n) { return n < 3 ? n : n * factorial(n - 1); }
    double getProbability(vector<int>& balls) {
        sz = balls.size();
        n = accumulate(begin(balls), end(balls), 0);
        total = match = 0.0;
        dfs(balls, 0, 0, 0, 0, 0, factorial(n/2), factorial(n/2));
        return static_cast<double>(match) / total;
    }
};

int main() {

    vector<int> balls;

    {
        // Output: 1.00000
        Solution sol;
        balls = {1,1};
        cout << sol.getProbability(balls) << endl;
    }

    {
        // Output: 0.66667
        Solution sol;
        balls = {2,1,1};
        cout << sol.getProbability(balls) << endl;
    }

    {
        // Output: 0.60000
        Solution sol;
        balls = {1,2,1,2};
        cout << sol.getProbability(balls) << endl;
    }

    {
        // Output: 0.30000
        Solution sol;
        balls = {3,2,1};
        cout << sol.getProbability(balls) << endl;
    }

    {
        // Output: 0.90327
        Solution sol;
        balls = {6,6,6,6,6,6};
        cout << sol.getProbability(balls) << endl;
    }
    
    return 0;
}
