/*
1710. Maximum Units on a Truck
Easy

You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes,
where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck.
You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

Example 1:
Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.

Example 2:
Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91

Constraints:
1 <= boxTypes.length <= 1000
1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
1 <= truckSize <= 106
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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

#include "common/ListNode.h"
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        using PAIR = pair<int, int>;
        auto comp = [] (PAIR& p1, PAIR& p2) {return p1.second < p2.second;};
        priority_queue<PAIR, vector<PAIR>, decltype(comp)> pq(comp);
        for (auto& box: boxTypes)
            pq.emplace(box[0], box[1]);
        int res = 0;
        while (!pq.empty() && truckSize > 0) {
            auto [box, unit] = pq.top();
            pq.pop();
            box = min(box, truckSize);
            res += box * unit;
            truckSize -= box;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> boxTypes;
    int truckSize;

    // Output: 8
    boxTypes = {{1,3},{2,2},{3,1}}, truckSize = 4;
    cout << sol.maximumUnits(boxTypes, truckSize) << endl;

    // Output: 91
    boxTypes = {{5,10},{2,5},{4,7},{3,9}}, truckSize = 10;
    cout << sol.maximumUnits(boxTypes, truckSize) << endl;

    return 0;
}
