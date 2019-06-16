/*
1090. Largest Values From Labels
Difficulty: Medium

We have a set of items: the i-th item has value values[i] and label labels[i].

Then, we choose a subset S of these items, such that:
|S| <= num_wanted
For every label L, the number of items in S with label L is <= use_limit.
Return the largest possible sum of the subset S.

Example 1:
Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], num_wanted = 3, use_limit = 1
Output: 9
Explanation: The subset chosen is the first, third, and fifth item.

Example 2:
Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], num_wanted = 3, use_limit = 2
Output: 12
Explanation: The subset chosen is the first, second, and third item.

Example 3:
Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 1
Output: 16
Explanation: The subset chosen is the first and fourth item.

Example 4:
Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 2
Output: 24
Explanation: The subset chosen is the first, second, and fourth item.
 
Note:

1 <= values.length == labels.length <= 20000
0 <= values[i], labels[i] <= 20000
1 <= num_wanted, use_limit <= values.length
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        unordered_map<int, multiset<int, greater<int>>> items;
        int ssize = values.size();
        for (int i = 0; i < ssize; ++i) {
            items[labels[i]].emplace(values[i]);
        }

        multiset<int, greater<int>> candidates;
        for (auto& item: items) {
            auto it = item.second.cbegin();
            for (int i = 0; i < use_limit && it != item.second.cend(); ++i, ++it) {
                candidates.emplace(*it);
            }
        }

        auto it = candidates.cbegin();
        int sum = 0;
        for (int i = 0; i < num_wanted && it != candidates.cend(); ++i, ++it) {
            sum += *it;
        }

        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> labels, values;
    int num_wanted, use_limit;

    // Expected: 9
    values = {5,4,3,2,1}, labels = {1,1,2,2,3}, num_wanted = 3, use_limit = 1;


    // 50 / 81 test cases passed.
    // Expected: 6
    values = {3,2,3,2,1}, labels = {1,0,2,2,1}, num_wanted = 2, use_limit = 1;


    cout << "Result: " << sol.largestValsFromLabels(values, labels, num_wanted, use_limit) << endl;

    return 0;
}

