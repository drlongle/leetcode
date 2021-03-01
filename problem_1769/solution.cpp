/*
1769. Minimum Number of Operations to Move All Balls to Each Box
Medium

You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0'
if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j
if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed
to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.

Example 1:
Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations,
and move one ball from the second box to the third box in one operation.

Example 2:
Input: boxes = "001011"
Output: [11,8,5,4,3,4]

Constraints:
n == boxes.length
1 <= n <= 2000
boxes[i] is either '0' or '1'.
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
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                answer[i] += (boxes[j] - '0') * (i - j);
            }
            for (int j = n-1; j > i; --j) {
                answer[i] += (boxes[j] - '0') * (j - i);
            }
        }

        return answer;
    }
};

int main() {
    Solution sol;
    string boxes;
    vector<int> answer;

    boxes = "110";
    answer = sol.minOperations(boxes);
    copy(begin(answer), end(answer), ostream_iterator<int>(cout, ", "));
    cout << endl;

    boxes = "001011";
    answer = sol.minOperations(boxes);
    copy(begin(answer), end(answer), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
