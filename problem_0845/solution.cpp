/*
845. Longest Mountain in Array
Medium

Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:

B.length >= 3
There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
(Note that B could be any subarray of A, including the entire array A.)

Given an array A of integers, return the length of the longest mountain.

Return 0 if there is no mountain.

Example 1:
Input: [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

Example 2:
Input: [2,2,2]
Output: 0
Explanation: There is no mountain.

Note:
0 <= A.length <= 10000
0 <= A[i] <= 10000

Follow up:
Can you solve it using only one pass?
Can you solve it in O(1) space?
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

#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    enum class State {SEARCH, ASCEND, DESCEND};

    int longestMountain(vector<int>& A) {
        int res = 0, n = A.size(), start = 0;
        State state(State::SEARCH);
        for (int i = 1; i < n; ++i) {
            switch (state) {
                case State::SEARCH:
                    if (A[i] > A[i-1]) {
                        state = State::ASCEND;
                        start = i - 1;
                    }
                    break;
                case State::ASCEND:
                    if (A[i] < A[i-1])
                        state = State::DESCEND;
                    else if (A[i] == A[i-1])
                        state = State::SEARCH;
                    break;
                case State::DESCEND:
                    if (A[i] >= A[i-1]) {
                        res = max(res, i - start);
                        if (A[i] == A[i-1])
                            state = State::SEARCH;
                        else {
                            state = State::ASCEND;
                            start = i - 1;
                        }
                    }
            }
        }
        if (state == State::DESCEND)
            res = max(res, n - start);

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> A;

    // Output: 5
    A = {2,1,4,7,3,2,5};
    cout << sol.longestMountain(A) << endl;

    // Output: 0
    A = {2,2,2};
    cout << sol.longestMountain(A) << endl;

    // Output: 11
    A = {0,1,2,3,4,5,4,3,2,1,0};
    cout << sol.longestMountain(A) << endl;

    // Output: 3
    A = {0,1,0};
    cout << sol.longestMountain(A) << endl;

    // Output: 4
    A = {875,884,239,731,723,685};
    cout << sol.longestMountain(A) << endl;

    // Output: 5
    A = {2,1,4,7,3,2,5};
    cout << sol.longestMountain(A) << endl;

    return 0;
}
