/*
1441. Build an Array With Stack Operations
Easy

Given an array target and an integer n. In each iteration, you will read a number from  list = {1,2,3..., n}.

Build the target array using the following operations:

Push: Read a new element from the beginning list, and push it in the array.
Pop: delete the last element of the array.
If the target array is already built, stop reading more elements.
You are guaranteed that the target array is strictly increasing, only containing numbers between 1 to n inclusive.

Return the operations to build the target array.

You are guaranteed that the answer is unique.

Example 1:
Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]
Explanation: 
Read number 1 and automatically push in the array -> [1]
Read number 2 and automatically push in the array then Pop it -> [1]
Read number 3 and automatically push in the array -> [1,3]

Example 2:
Input: target = [1,2,3], n = 3
Output: ["Push","Push","Push"]

Example 3:
Input: target = [1,2], n = 4
Output: ["Push","Push"]
Explanation: You only need to read the first 2 numbers and stop.

Example 4:
Input: target = [2,3,4], n = 4
Output: ["Push","Pop","Push","Push","Push"]

Constraints:

1 <= target.length <= 100
1 <= target[i] <= 100
1 <= n <= 100
target is strictly increasing.
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

#define ll long long
#define ull unsigned long long

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        bool has_prev_element = false;
        for (int i = 1, index = 0; i <= n; ++i) {
            if (has_prev_element)
                res.emplace_back("Pop");
            res.emplace_back("Push");
            if (i < target[index])
                has_prev_element = true;
            else {
                has_prev_element = false;
                if (++index == static_cast<int>(target.size()))
                    break;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> target;
    int n;
    vector<string> res;
    
    // Output: {"Push","Push","Pop","Push"}
    target = {1,3}, n = 3;
    res = sol.buildArray(target, n);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;
    
    // Output: {"Push","Push","Push"}
    target = {1,2,3}, n = 3;
    res = sol.buildArray(target, n);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;
    
    // Output: {"Push","Push"}
    target = {1,2}, n = 4;
    res = sol.buildArray(target, n);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;
    
    // Output: {"Push","Pop","Push","Push","Push"}
    target = {2,3,4}, n = 4;
    res = sol.buildArray(target, n);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;
    
    return 0;
}
