/*
1578. Minimum Deletion Cost to Avoid Repeating Letters
Medium

Given a string s and an array of integers cost where cost[i] is the cost of deleting the ith character in s.

Return the minimum cost of deletions such that there are no two identical letters next to each other.

Notice that you will delete the chosen characters at the same time, in other words, after deleting a character, the costs of deleting other characters will not change.

Example 1:
Input: s = "abaac", cost = [1,2,3,4,5]
Output: 3
Explanation: Delete the letter "a" with cost 3 to get "abac" (String without two identical letters next to each other).

Example 2:
Input: s = "abc", cost = [1,2,3]
Output: 0
Explanation: You don't need to delete any character because there are no identical letters next to each other.

Example 3:
Input: s = "aabaa", cost = [1,2,3,4,1]
Output: 2
Explanation: Delete the first and the last character, getting the string ("aba").

Constraints:
s.length == cost.length
1 <= s.length, cost.length <= 10^5
1 <= cost[i] <= 10^4
s contains only lowercase English letters.
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

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int res = 0, sz = s.size();
        int head = 0;
        while (head < sz) {
            int tail = head;
            int running_cost = 0, max_cost = 0;
            while (head < sz && s[head] == s[tail]) {
                running_cost += cost[head];
                max_cost = max(max_cost, cost[head]);
                ++head;
            }
            res += running_cost - max_cost;
        }

        return res;
    }
};

int main() {
    Solution sol;
    string s;
    vector<int> cost;

    // Output: 3
    s = "abaac", cost = {1,2,3,4,5};
    cout << sol.minCost(s, cost) << endl;

    // Output: 0
    s = "abc", cost = {1,2,3};
    cout << sol.minCost(s, cost) << endl;

    // Output: 2
    s = "aabaa", cost = {1,2,3,4,1};
    cout << sol.minCost(s, cost) << endl;

    // Output: 23
    s = "bbbaaa", cost = {4,9,3,8,8,9};
    cout << sol.minCost(s, cost) << endl;

    return 0;
}
