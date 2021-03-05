/*
575. Distribute Candies
Easy

Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that
she started to gain weight, so she visited a doctor.

The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes
her candies very much, and she wants to eat the maximum number of different types of candies while
still following the doctor's advice.

Given the integer array candyType of length n, return the maximum number of different types of
candies she can eat if she only eats n / 2 of them.

Example 1:
Input: candyType = [1,1,2,2,3,3]
Output: 3
Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.

Example 2:
Input: candyType = [1,1,2,3]
Output: 2
Explanation: Alice can only eat 4 / 2 = 2 candies. Whether she eats types [1,2], [1,3], or [2,3], she still
can only eat 2 different types.

Example 3:
Input: candyType = [6,6,6,6]
Output: 1
Explanation: Alice can only eat 4 / 2 = 2 candies. Even though she can eat 2 candies, she only has 1 type.

Constraints:
n == candyType.length
2 <= n <= 10^4
n is even.
-10^5 <= candyType[i] <= 10^5
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
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> cnt(candyType.begin(), candyType.end());
        return min(candyType.size() / 2, cnt.size());
    }
};

int main() {
    Solution sol;

    return 0;
}
