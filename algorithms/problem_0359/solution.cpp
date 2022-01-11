/*
359. Logger Rate Limiter
Easy

Design a logger system that receives a stream of messages along with their timestamps. Each unique message
should only be printed at most every 10 seconds (i.e. a message printed at timestamp t will prevent other
identical messages from being printed until timestamp t + 10).

All messages will come in chronological order. Several messages may arrive at the same timestamp.

Implement the Logger class:
- Logger() Initializes the logger object.
- bool shouldPrintMessage(int timestamp, string message) Returns true if the message should be printed
  in the given timestamp, otherwise returns false.

Example 1:
Input:
["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage",
 "shouldPrintMessage", "shouldPrintMessage"]
[[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
Output:
[null, true, true, false, false, false, true]

Explanation
Logger logger = new Logger();
logger.shouldPrintMessage(1, "foo");  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
logger.shouldPrintMessage(2, "bar");  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
logger.shouldPrintMessage(3, "foo");  // 3 < 11, return false
logger.shouldPrintMessage(8, "bar");  // 8 < 12, return false
logger.shouldPrintMessage(10, "foo"); // 10 < 11, return false
logger.shouldPrintMessage(11, "foo"); // 11 >= 11, return true, next allowed timestamp for "foo" is
                                      // 11 + 10 = 21

Constraints:
0 <= timestamp <= 10^9
Every timestamp will be passed in non-decreasing order (chronological order).
1 <= message.length <= 30
At most 10^4 calls will be made to shouldPrintMessage.
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

class Logger {
public:
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = cache.find(message);
        if (it == cache.end() || timestamp - it->second >= 10){
            cache[message] = timestamp;
            return true;
        } else
            return false;
    }
    unordered_map <string,int> cache;
};

int main() {
    Solution sol;

    return 0;
}
