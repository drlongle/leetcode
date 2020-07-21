/*
1518. Water Bottles
Easy

Given numBottles full water bottles, you can exchange numExchange empty water bottles for one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Return the maximum number of water bottles you can drink.

Example 1:
Input: numBottles = 9, numExchange = 3
Output: 13
Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 9 + 3 + 1 = 13.

Example 2:
Input: numBottles = 15, numExchange = 4
Output: 19
Explanation: You can exchange 4 empty bottles to get 1 full water bottle. 
Number of water bottles you can drink: 15 + 3 + 1 = 19.

Example 3:
Input: numBottles = 5, numExchange = 5
Output: 6

Example 4:
Input: numBottles = 2, numExchange = 3
Output: 2

Constraints:
1 <= numBottles <= 100
2 <= numExchange <= 100
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

class Solution {
public:
    int numWaterBottles(int num, int numExchange) {
        int res = 0, empty = 0;
        while (num > 0) {
            res += num;
            empty += num;
            num = empty / numExchange;
            empty = (empty % numExchange);
        }
        return res;
    }
};

int main() {
    Solution sol;
    int numBottles, numExchange;

    // Output: 13
    numBottles = 9, numExchange = 3;
    cout << sol.numWaterBottles(numBottles, numExchange) << endl;

    // Output: 19
    numBottles = 15, numExchange = 4;
    cout << sol.numWaterBottles(numBottles, numExchange) << endl;

    // Output: 6
    numBottles = 5, numExchange = 5;
    cout << sol.numWaterBottles(numBottles, numExchange) << endl;

    // Output: 2
    numBottles = 2, numExchange = 3;
    cout << sol.numWaterBottles(numBottles, numExchange) << endl;

    return 0;
}
