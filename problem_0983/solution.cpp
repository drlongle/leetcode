/*
Problem 983. Minimum Cost For Tickets
Difficulty: Medium

In a country popular for train travel, you have planned some train travelling
one year in advance. The days of the year that you will travel is given as an
array days. Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

a 1-day pass is sold for costs[0] dollars;
a 7-day pass is sold for costs[1] dollars;
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel. For example, if we get a
7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given
list of days.

Example 1:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: 
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total you spent $11 and covered all the days of your travel.

Example 2:
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: 
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total you spent $17 and covered all the days of your travel.

Note:
1. 1 <= days.length <= 365
2. 1 <= days[i] <= 365
3. days is in strictly increasing order.
4. costs.length == 3
5. 1 <= costs[i] <= 1000
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
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

class Solution {
public:

    int cost(vector<int>& days, int index, vector<int>& costs) {
        if (index >= days.size())
            return 0;
        if (index == days.size() - 1)
            return costs[0];
        auto it = cache.find(index);
        if (it != cache.cend())
            return it->second;
        int res1 = costs[0] + cost(days, index+1, costs);
        int i = index+1;
        for ( ; i < days.size(); ++i)
            if (days[i] - days[index] >= 7)
                break;
        int res2 = costs[1] + cost(days, i, costs);
        
        int j = i+1;
        for ( ; j < days.size(); ++j)
            if (days[j] - days[index] >= 30)
                break;
        int res3 = costs[2] + cost(days, j, costs);
        int res = min({res1, res2, res3});
        cache[index] = res;
        return res;
    }
        
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return cost(days, 0, costs);
    }
    
    unordered_map<int, int> cache;
};

int main(int argc, char** argv) {
    Solution sol;
    vector<int> days, costs;
    
    // Expected: 11
    days = {1,4,6,7,8,20}, costs = {2,7,15};
    
    // Expected: 17
    //days = {1,2,3,4,5,6,7,8,9,10,30,31}, costs = {2,7,15};
    
    cout << "Result: " << sol.mincostTickets(days, costs) << endl;
    
    return 0;
}
