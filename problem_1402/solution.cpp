/*
1402. Reducing Dishes
Hard

A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level  i.e.  time[i]*satisfaction[i]

Return the maximum sum of Like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

Example 1:
Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total Like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14). Each dish is prepared in one unit of time.

Example 2:
Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

Example 3:
Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People don't like the dishes. No dish is prepared.

Example 4:
Input: satisfaction = [-2,5,-1,0,3,-3]
Output: 35

Constraints:
n == satisfaction.length
1 <= n <= 500
-10^3 <= satisfaction[i] <= 10^3
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
    int maxSatisfaction(vector<int>& satisfaction) {
        int sum = 0, res = 0, sz = satisfaction.size();
        sort(begin(satisfaction), end(satisfaction));
        for (int i = sz-1; i >= 0; --i) {
            int value = satisfaction[i];
            if (0 <= value || sum + value >= 0) {
                res += sum;
                res += value;
                sum += value;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> values;

    // Output: 14
    values = {-1,-8,0,5,-9};
    cout << sol.maxSatisfaction(values) << endl;

    // Output: 20
    values = {4,3,2};
    cout << sol.maxSatisfaction(values) << endl;
    
    // Output: 0
    values = {-1,-4,-5};
    cout << sol.maxSatisfaction(values) << endl;
    
    // Output: 35
    values = {-2,5,-1,0,3,-3};
    cout << sol.maxSatisfaction(values) << endl;
    
    return 0;
}
