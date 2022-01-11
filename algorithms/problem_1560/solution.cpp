/*
1560. Most Visited Sector in a Circular Track
Easy

Given an integer n and an integer array rounds. We have a circular track which consists of n sectors labeled from
1 to n. A marathon will be held on this track, the marathon consists of m rounds. The ith round starts at sector
rounds[i - 1] and ends at sector rounds[i]. For example, round 1 starts at sector rounds[0] and ends at sector rounds[1].

Return an array of the most visited sectors sorted in ascending order.

Notice that you circulate the track in ascending order of sector numbers in the counter-clockwise direction (See the first example).

Example 1:
Input: n = 4, rounds = [1,3,1,2]
Output: [1,2]
Explanation: The marathon starts at sector 1. The order of the visited sectors is as follows:
1 --> 2 --> 3 (end of round 1) --> 4 --> 1 (end of round 2) --> 2 (end of round 3 and the marathon)
We can see that both sectors 1 and 2 are visited twice and they are the most visited sectors. Sectors 3 and 4 are visited only once.

Example 2:
Input: n = 2, rounds = [2,1,2,1,2,1,2,1,2]
Output: [2]

Example 3:
Input: n = 7, rounds = [1,3,5,7]
Output: [1,2,3,4,5,6,7]

Constraints:
2 <= n <= 100
1 <= m <= 100
rounds.length == m + 1
1 <= rounds[i] <= n
rounds[i] != rounds[i + 1] for 0 <= i < m
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
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> sectors(n+1, 0);
        int highest = -1;
        for (size_t i = 1; i < rounds.size(); ++i) {
            int start = (rounds[i-1] + ((i > 1) ? 1 : 0)) % (n+1);
            int end = rounds[i];
            int j = start;
            while (true) {
                highest = max(highest, ++sectors[j]);
                if (j == end)
                    break;
                j = (j + 1) % (n +1);
                if (j == 0)
                    ++j;
            }
        }

        vector<int> res;
        for (int j = 1; j <= n; ++j)
            if (sectors[j] == highest)
                res.emplace_back(j);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> rounds, sectors;
    int n;

    n = 4, rounds = {1,3,1,2};
    sectors = sol.mostVisited(n, rounds);
    copy(begin(sectors), end(sectors), ostream_iterator<int>(cout, ", "));
    cout << endl;

    n = 2, rounds = {2,1,2,1,2,1,2,1,2};
    sectors = sol.mostVisited(n, rounds);
    copy(begin(sectors), end(sectors), ostream_iterator<int>(cout, ", "));
    cout << endl;

    n = 7, rounds = {1,3,5,7};
    sectors = sol.mostVisited(n, rounds);
    copy(begin(sectors), end(sectors), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
