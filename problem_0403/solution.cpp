/*
403. Frog Jump
Difficulty: Hard

A frog is crossing a river. The river is divided into x units and at each unit
there may or may not exist a stone. The frog can jump on a stone, but it must
not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order,
determine if the frog is able to cross the river by landing on the last stone.
Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either k - 1, k,
or k + 1 units. Note that the frog can only jump in the forward direction.

Note:

The number of stones is >= 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.
Example 1:
[0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping 
1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
2 units to the 4th stone, then 3 units to the 6th stone, 
4 units to the 7th stone, and 5 units to the 8th stone.

Example 2:
[0,1,2,3,4,8,9,11]
Return false. There is no way to jump to the last stone as 
the gap between the 5th and 6th stone is too large.
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
    
    bool jump(int pos, int distance) {
        if (cache[pos].count(distance))
            return false;
        if (pos == cache.rbegin()->first)
            return true;
        array<int, 3> offsets {-1, 0, 1};
        for (auto offset: offsets) {
            int d = distance + offset;
            if (d > 0 && cache.count(pos + d) && jump (pos + d, d))
                return true;
        }
        cache[pos].emplace(distance);
        return false;
    }
    
    bool canCross(vector<int>& stones) {
        for (auto stone: stones)
            cache[stone] = set<int>{};
        if (!cache.count(1))
            return false;
        return jump(0, 1);
    }
    
    map<int, set<int>> cache;
};

int main(int argc, char** argv) {
    Solution sol;
    vector<int> stones;

    // Expected: true
    stones = {0,1,3,5,6,8,12,17};

    // Expected: false
    stones = {0,1,2,3,4,8,9,11};

    stones = {0,2};

    cout << "Result: " << boolalpha << sol.canCross(stones) << endl;

    return 0;
}
