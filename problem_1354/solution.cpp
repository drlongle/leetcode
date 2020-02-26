/*
1354. Construct Target Array With Multiple Sums
Hard

Given an array of integers target. From a starting array, A consisting of all 1's,
you may perform the following procedure:

let x be the sum of all elements currently in your array.
choose index i, such that 0 <= i < target.size and set the value of A at index i to x.
You may repeat this procedure as many times as needed.
Return True if it is possible to construct the target array from A otherwise return False.

Example 1:
Input: target = [9,3,5]
Output: true
Explanation: Start with [1, 1, 1] 
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done

Example 2:
Input: target = [1,1,1,2]
Output: false
Explanation: Impossible to create target array from [1,1,1,1].

Example 3:
Input: target = [8,5]
Output: true

Constraints:
N == target.length
1 <= target.length <= 5 * 10^4
1 <= target[i] <= 10^9
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    using ll == long long;
    bool check(vector<ll>& target) {
        auto min_it = min_element(begin(target), end(target));
        auto max_it = max_element(begin(target), end(target));
        auto lambda = [](auto a, auto b) {return (ll) a + (ll) b;};
        ll sum = accumulate(begin(target), end(target), (ll) 0, lambda);
        ll rest = sum - *max_it;
        if (*min_it == 1 && *max_it == 1)
            return true;
        if (*min_it <= 0 || rest <= 0 || rest > *max_it) {
            return false;
        }
        if (target.size() == 2) {
            switch (*min_it) {
                case 1:
                    return true;
                case 2:
                    if (*max_it % 2 == 1)
                        return true;
                    else {
                        return false;
                    }
            }
        }
        if (*max_it > 2*rest)
            *max_it = rest + (*max_it % rest);
        else
            *max_it = 2*(*max_it) - sum;

        return check(target);
    }
    
    bool isPossible(vector<int>& target) {
        vector<ll> nums(begin(target), end(target));
        return check(nums);
    }
};

int main() {
    Solution sol;
    vector<int> target;

    // Output: true
    target = {9,3,5};

    // Output: false
    //target = {1,1,1,2};

    // Output: true
    //target = {8,5};

    // True
    //target = {1,1000000000};

    // true
    //target = {2,900000001};

    // true
    //target = {5,2};

    // true
    //target = {1,1,999999999};
    
    cout << boolalpha << sol.isPossible(target) << endl;

    return 0;
}
