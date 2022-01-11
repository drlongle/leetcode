/*
170. Two Sum III - Data structure design
Easy

Design a data structure that accepts a stream of integers and checks if it has
a pair of integers that sum up to a particular value.

Implement the TwoSum class:

TwoSum() Initializes the TwoSum object, with an empty array initially.
void add(int number) Adds number to the data structure.
boolean find(int value) Returns true if there exists any pair of numbers whose sum is equal to value,
otherwise, it returns false.

Example 1:
Input
["TwoSum", "add", "add", "add", "find", "find"]
[[], [1], [3], [5], [4], [7]]
Output
[null, null, null, null, true, false]

Explanation
TwoSum twoSum = new TwoSum();
twoSum.add(1);   // [] --> [1]
twoSum.add(3);   // [1] --> [1,3]
twoSum.add(5);   // [1,3] --> [1,3,5]
twoSum.find(4);  // 1 + 3 = 4, return true
twoSum.find(7);  // No two integers sum up to 7, return false

Constraints:
-10^5 <= number <= 10^5
-2^31 <= value <= 2^31 - 1
At most 5 * 10^4 calls will be made to add and find.
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

class TwoSum {
public:

    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++nums[number];
    }

    unordered_map <int, int> nums;
    using ll = long long;
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto& [k, v]: nums){
            if ((2*k == value && v >= 2) || (2*k != value && nums.count((ll) value - k)))
                return true;
        }

        return false;
    }
};

int main() {
    return 0;
}
