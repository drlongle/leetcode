/*
384. Shuffle an Array
Difficulty: Medium

Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3]
must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int> nums): m_nums(nums), m_index(nums.size()) {
        iota(begin(m_index), end(m_index), 0);
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        iota(begin(m_index), end(m_index), 0);
        return m_nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(m_nums.size());
        for (size_t i = 0; i < m_nums.size(); ++i) {
            res[i] = m_nums[m_index[i]];
        }
        random_shuffle(begin(m_index), end(m_index));
        
        return res;
    }
    
    vector<int> m_nums, m_index;
};

int main(int argc, char** argv) {
    vector<int> input{1,2,3}, res;
    Solution sol(input);
    for (int i = 0; i <= 4; ++i) {
        res = sol.shuffle();
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
    return 0;
}
