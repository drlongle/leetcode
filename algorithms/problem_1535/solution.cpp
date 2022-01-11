/*
1535. Find the Winner of an Array Game
Medium

Given an integer array arr of distinct integers and an integer k.

A game will be played between the first two elements of the array (i.e. arr[0] and arr[1]).
In each round of the game, we compare arr[0] with arr[1], the larger integer wins and remains
at position 0 and the smaller integer moves to the end of the array. The game ends when an
integer wins k consecutive rounds.

Return the integer which will win the game.

It is guaranteed that there will be a winner of the game.

Example 1:
Input: arr = [2,1,3,5,4,6,7], k = 2
Output: 5
Explanation: Let's see the rounds of the game:
Round |       arr       | winner | win_count
  1   | [2,1,3,5,4,6,7] | 2      | 1
  2   | [2,3,5,4,6,7,1] | 3      | 1
  3   | [3,5,4,6,7,1,2] | 5      | 1
  4   | [5,4,6,7,1,2,3] | 5      | 2
So we can see that 4 rounds will be played and 5 is the winner because it wins 2 consecutive games.

Example 2:
Input: arr = [3,2,1], k = 10
Output: 3
Explanation: 3 will win the first 10 rounds consecutively.

Example 3:
Input: arr = [1,9,8,2,3,7,6,4,5], k = 7
Output: 9

Example 4:
Input: arr = [1,11,22,33,44,55,66,77,88,99], k = 1000000000
Output: 99

Constraints:
2 <= arr.length <= 10^5
1 <= arr[i] <= 10^6
arr contains distinct integers.
1 <= k <= 10^9
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

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int sz = arr.size();
        if (k >= sz-1) {
            return *max_element(arr.begin(), arr.end());
        }
        int res = arr[0];
        for (int i = 1, cnt = 0; i < sz; ++i) {
            if (arr[i] < res)
                ++cnt;
            else {
                res = arr[i];
                cnt = 1;
            }
            if (cnt == k)
                return res;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int k;

    //Output: 5
    arr = {2,1,3,5,4,6,7}, k = 2;
    cout << sol.getWinner(arr, k) << endl;

    //Output: 3
    arr = {3,2,1}, k = 10;
    cout << sol.getWinner(arr, k) << endl;

    //Output: 9
    arr = {1,9,8,2,3,7,6,4,5}, k = 7;
    cout << sol.getWinner(arr, k) << endl;

    //Output: 99
    arr = {1,11,22,33,44,55,66,77,88,99}, k = 1000000000;
    cout << sol.getWinner(arr, k) << endl;

    return 0;
}
