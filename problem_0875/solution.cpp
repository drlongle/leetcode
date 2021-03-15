/*
875. Koko Eating Bananas
Medium

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile
of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats
all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23

Constraints:
1 <= piles.length <= 10^4
piles.length <= h <= 10^9
1 <= piles[i] <= 10^9
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    bool check (vector <int>& piles, int speed, int hour) {
        auto lambda = [speed] (int s, int p) {return s+ceil(((double) p)/speed);};
        return accumulate(piles.begin(),piles.end(),0, lambda) <= hour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = INT_MAX, res = INT_MAX;
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if (check(piles, mid, h)) {
                res = min(res,mid);
                hi = mid-1;
            } else
                lo = mid+1;
        }
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
