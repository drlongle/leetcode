/*
368. Largest Divisible Subset

Given a set of distinct positive integers, find the largest subset such that
every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Example 2:
Input: [1,2,4,8]
Output: [1,2,4,8]
*/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        sort(begin(nums), end(nums));
        int best = -1;
        vector<pair<int, int>> index(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            index[i] = make_pair<int,int>(1, -1);
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (index[i].first < index[j].first + 1) {
                        index[i].first = index[j].first + 1;
                        index[i].second = j;
                    }
                }
            }
            if (best == -1 || index[i].first > index[best].first) {
                best = i;
            }
        }

        int ind = best;
        while (ind >= 0) {
            res.emplace_back(nums[ind]);
            ind = index[ind].second;
        }
        
        return res;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<int> input, res;

    // Expected: 
    input = vector<int>{1,2,3};
    res = sol.largestDivisibleSubset(input);

    // Expected: [1,2,4,8]
    input = vector<int>{1,2,4,8};
    //res = sol.largestDivisibleSubset(input);

    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
 
    return 0;
}
