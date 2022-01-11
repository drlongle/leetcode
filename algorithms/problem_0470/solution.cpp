/*
470. Implement Rand10() Using Rand7()
Medium

Given a function rand7 which generates a uniform random integer in the range 1 to 7,
write a function rand10 which generates a uniform random integer in the range 1 to 10.

Do NOT use system's Math.random().

Example 1:
Input: 1
Output: [7]

Example 2:
Input: 2
Output: [8,4]

Example 3:
Input: 3
Output: [8,1,10]

Note:
rand7 is predefined.
Each testcase has one argument: n, the number of times that rand10 is called.

Follow up:
What is the expected value for the number of calls to rand7() function?
Could you minimize the number of calls to rand7()?
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

int rand7()
{
    return 0;
}

class Solution {
public:
    int rand10() {
        int r;
        while (true) {
            r = rand7();
            if (r <= 6)
                break;
        }

        int res = (r <= 3) ? 0 : 5;
        while (true) {
            r = rand7();
            if (r <= 5)
                break;
        }

        return res + r;
    }
};

int main() {
    return 0;
}
