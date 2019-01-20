/*
398. Random Pick Index
Difficulty: Medium

Given an array of integers with possible duplicates, randomly output the index
of a given target number. You can assume that the given target number must exist
in the array.

Note:
The array size can be very large. Solution that uses too much extra space will
not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should
have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
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
    Solution(vector<int> nums) {
        for (int i = 0; i < nums.size(); ++i) {
            pos[nums[i]].emplace_back(i);
        }
    }
    
    int pick(int target) {
        vector<int>& v = pos[target];
        int index = rand() % v.size();
        return v[index];
    }
    
    unordered_map<int, vector<int>> pos;
};

int main(int argc, char** argv) {
    Solution sol(vector<int>{1,2,3,3,3});
    
    cout << "Pick: " << sol.pick(3) << endl;
    
    return 0;
}
