/*
1564. Put Boxes Into the Warehouse I
Medium
You are given two arrays of positive integers, boxes and warehouse, representing the heights of
some boxes of unit width and the heights of n rooms in a warehouse respectively. The warehouse's
rooms are labelled from 0 to n - 1 from left to right where warehouse{i] (0-indexed) is the height
of the ith room.

Boxes are put into the warehouse by the following rules:

Boxes cannot be stacked.
You can rearrange the insertion order of the boxes.
Boxes can only be pushed into the warehouse from left to right only.
If the height of some room in the warehouse is less than the height of a box, then that box
and all other boxes behind it will be stopped before that room.
Return the maximum number of boxes you can put into the warehouse.

Example 1:
Input: boxes = [4,3,4,1], warehouse = [5,3,3,4,1]
Output: 3

Explanation:
We can first put the box of height 1 in room 4. Then we can put the box of height 3 in either of
the 3 rooms 1, 2, or 3. Lastly, we can put one box of height 4 in room 0. There is no way we can fit
all 4 boxes in the warehouse.

Example 2:
Input: boxes = [1,2,2,3,4], warehouse = [3,4,1,2]
Output: 3
Explanation:
Notice that it's not possible to put the box of height 4 into the warehouse since it cannot
pass the first room of height 3. Also, for the last two rooms, 2 and 3, only boxes of height 1 can fit.
We can fit 3 boxes maximum as shown above. The yellow box can also be put in room 2 instead.
Swapping the orange and green boxes is also valid, or swapping one of them with the red box.

Example 3:
Input: boxes = [1,2,3], warehouse = [1,2,3,4]
Output: 1
Explanation: Since the first room in the warehouse is of height 1, we can only put boxes of height 1.

Example 4:
Input: boxes = [4,5,6], warehouse = [3,3,3,3,3]
Output: 0

Constraints:
n == warehouse.length
1 <= boxes.length, warehouse.length <= 10^5
1 <= boxes[i], warehouse[i] <= 10^9
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:

    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int res = 0, n = warehouse.size(), minh = INT_MAX;
        map<int, int> heights;
        for (int i = 0; i < n; ++i) {
            if (minh > warehouse[i]) {
                minh = warehouse[i];
                heights.emplace(minh, i);
            }
        }

        sort(begin (boxes), end(boxes), less<int>());
        int index = n - 1; // Start at the latest position in the warehouse.
        for (int i = 0, sz = boxes.size(); i < sz && index >= 0; ++i) {
            int box = boxes[i];
            auto it = heights.lower_bound(box);
            if (it == heights.end())
                break;

            if (it != heights.begin()) {
                auto pit = prev(it);
                if (pit->first < box) {
                    index = min(index, pit->second-1);
                    if (index < 0)
                        break;
                }
            }

            --index;
            ++res;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> boxes, warehouse;

    // Output: 3
    boxes = {4,3,4,1}, warehouse = {5,3,3,4,1};
    cout << sol.maxBoxesInWarehouse(boxes, warehouse) << endl;

    // Output: 3
    boxes = {1,2,2,3,4}, warehouse = {3,4,1,2};
    cout << sol.maxBoxesInWarehouse(boxes, warehouse) << endl;

    // Output: 1
    boxes = {1,2,3}, warehouse = {1,2,3,4};
    cout << sol.maxBoxesInWarehouse(boxes, warehouse) << endl;

    // Output: 0
    boxes = {4,5,6}, warehouse = {3,3,3,3,3};
    cout << sol.maxBoxesInWarehouse(boxes, warehouse) << endl;

    // Output: 3
    boxes = {4,3,4,1}, warehouse = {5,3,3,4,1};
    cout << sol.maxBoxesInWarehouse(boxes, warehouse) << endl;

    // Output: 1
    boxes = {2,5,5,2}, warehouse = {6,1,1,2,3,4,3,7,5,6,2,8,8,5};
    cout << sol.maxBoxesInWarehouse(boxes, warehouse) << endl;

    // Output: 0
    boxes = {11,8,13,7,16,7,10,12}, warehouse = {5,8,14,15,11,1,13,2,9,8,4,10,6,16,16,1,15};
    cout << sol.maxBoxesInWarehouse(boxes, warehouse) << endl;

    // Output: 4
    boxes = {4,4,1,1}, warehouse = {5,4,3,3,1};
    cout << sol.maxBoxesInWarehouse(boxes, warehouse) << endl;

    // Output: 3
    boxes = {31,28,1,22,28,22,26,26,16,24,36,31,21,9,3,12,4,1,13};
    warehouse = {12,1,14,37,34,25,4,13,7,37,22,21,20,29};
    cout << sol.maxBoxesInWarehouse(boxes, warehouse) << endl;

    return 0;
}
