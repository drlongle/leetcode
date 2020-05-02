/*
1423. Maximum Points You Can Obtain from Cards
Medium

There are several cards arranged in a row, and each card has an associated number of points.
The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row.
You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Example 1:
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12

Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

Example 2:
Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.

Example 3:
Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.

Example 4:
Input: cardPoints = [1,1000,1], k = 1
Output: 1
Explanation: You cannot take the card in the middle. Your best score is 1. 

Example 5:
Input: cardPoints = [1,79,80,1,1,1,200,1], k = 3
Output: 202

Constraints:
1 <= cardPoints.length <= 10^5
1 <= cardPoints[i] <= 10^4
1 <= k <= cardPoints.length
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
#define ull unsigned long long

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int K) {
        vector<int> prefix{0}, suffix{0};
        partial_sum(begin(cardPoints), begin(cardPoints) + K, back_inserter(prefix));
        partial_sum(cardPoints.rbegin(), cardPoints.rbegin()  + K, back_inserter(suffix));
        int res = 0;
        for (int k = 0; k <= K; ++k) {
            res = max(res, prefix[k] + suffix[K-k]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> cardPoints;
    int k;

    // Output: 12
    cardPoints = {1,2,3,4,5,6,1}, k = 3;
    cout << sol.maxScore(cardPoints, k) << endl;

    // Output: 4
    cardPoints = {2,2,2}, k = 2;
    cout << sol.maxScore(cardPoints, k) << endl;

    // Output: 55
    cardPoints = {9,7,7,9,7,7,9}, k = 7;
    cout << sol.maxScore(cardPoints, k) << endl;

    // Output: 1
    cardPoints = {1,1000,1}, k = 1;
    cout << sol.maxScore(cardPoints, k) << endl;

    // Output: 202
    cardPoints = {1,79,80,1,1,1,200,1}, k = 3;
    cout << sol.maxScore(cardPoints, k) << endl;

    // Expected: 248
    cardPoints = {100,40,17,9,73,75}, k = 3;
    cout << sol.maxScore(cardPoints, k) << endl;

    return 0;
}
