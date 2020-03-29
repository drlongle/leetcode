/*
1395. Count Number of Teams
Medium

There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
You have to form a team of 3 soldiers amongst them under the following rules:
Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if:  (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

Example 1:
Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 

Example 2:
Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.

Example 3:
Input: rating = [1,2,3,4]
Output: 4

Constraints:
n == rating.length
1 <= n <= 200
1 <= rating[i] <= 10^5
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
#include <memory>
#include <numeric>
#include <queue>
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
    int numTeams(vector<int>& rating) {
        int res = 0, sz = rating.size();
        for (int i = 0; i < sz; ++i)
            for (int j = i+1; j < sz; ++j)
                for (int k = j+1; k < sz; ++k) {
                    if ((rating[i] > rating[j] && rating[j] > rating[k]) ||
                        (rating[i] < rating[j] && rating[j] < rating[k]))
                        ++res;
                }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> rating;

    // Output: 3
    rating = {2,5,3,4,1};
    //cout << sol.numTeams(rating) << endl;
    
    // Output: 0
    rating = {2,1,3};
    //cout << sol.numTeams(rating) << endl;
    
    // Output: 4
    rating = {1,2,3,4};
    //cout << sol.numTeams(rating) << endl;
    
    // Output: 3
    rating = {3,6,7,5,1};
    cout << sol.numTeams(rating) << endl;
    
    return 0;
}
