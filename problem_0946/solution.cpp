/*
946. Validate Stack Sequences
Medium

Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

Example 1:
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

Example 2:
Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.

Note:
0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed is a permutation of popped.
pushed and popped have distinct values.
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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size())
            return false;
        stack<int> st;
        int n = pushed.size();
        for (int i = 0, j = 0; i < n; ++i) {
            st.push(pushed[i]);
            while (!st.empty() && (st.top() == popped[j])) {
                st.pop();
                ++j;
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;
    vector<int> pushed, popped;

    // Output: true
    pushed = {1,2,3,4,5}, popped = {4,5,3,2,1};
    cout << boolalpha << sol.validateStackSequences(pushed, popped) << endl;
    
    // Output: false
    pushed = {1,2,3,4,5}, popped = {4,3,5,1,2};
    cout << boolalpha << sol.validateStackSequences(pushed, popped) << endl;
    
    return 0;
}
