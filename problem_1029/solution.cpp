/*
1029. Two City Scheduling
Easy

There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

Example 1:
Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.

Note:
1 <= costs.length <= 100
It is guaranteed that costs.length is even.
1 <= costs[i][0], costs[i][1] <= 1000
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

/*
The idea here is to compue the difference between the costs of city A and city B. If the difference of costs[Ai] - costs[Bi] comes out to be negative, this means that it is profitable to go to city A and vice versa. Sorting it using comparator and sending the first n/2 people to city A and the next n/2 people to city B would minimise the total cost.
 */

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto lambda = [] (vector<int>& a, vector<int>& b) {
                          return a[1]-a[0] > b[1]-b[0];        
                      };
        sort(begin(costs), end(costs), lambda);
        
        int n = costs.size();
        int res = 0;
        for (int i = 0 ; i < n; i++)
            res += (i < n/2) ? costs[i][0] : costs[i][1];

        return res;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> costs;

    // Output: 110
    costs = {{10,20},{30,200},{400,50},{30,20}};
    cout << sol.twoCitySchedCost(costs) << endl;

    // Output: 4723
    costs = {{70,311},{74,927},{732,711},{126,583},{857,118},{97,928},{975,843},{175,221},{284,929},{816,602},{689,863},{721,888}};
    cout << sol.twoCitySchedCost(costs) << endl;
    
    return 0;
}
