/*
1526. Minimum Number of Increments on Subarrays to Form a Target Array
Hard

Given an array of positive integers target and an array initial of same size with all zeros.

Return the minimum number of operations to form a target array from initial if you are allowed to do the following operation:
Choose any subarray from initial and increment each value by one.

The answer is guaranteed to fit within the range of a 32-bit signed integer.

Example 1:
Input: target = [1,2,3,2,1]
Output: 3
Explanation: We need at least 3 operations to form the target array from the initial array.
[0,0,0,0,0] increment 1 from index 0 to 4 (inclusive).
[1,1,1,1,1] increment 1 from index 1 to 3 (inclusive).
[1,2,2,2,1] increment 1 at index 2.
[1,2,3,2,1] target array is formed.

Example 2:
Input: target = [3,1,1,2]
Output: 4
Explanation: (initial)[0,0,0,0] -> [1,1,1,1] -> [1,1,1,2] -> [2,1,1,2] -> [3,1,1,2] (target).

Example 3:
Input: target = [3,1,5,4,2]
Output: 7
Explanation: (initial)[0,0,0,0,0] -> [1,1,1,1,1] -> [2,1,1,1,1] -> [3,1,1,1,1] 
                                  -> [3,1,2,2,2] -> [3,1,3,3,2] -> [3,1,4,4,2] -> [3,1,5,4,2] (target).
Example 4:
Input: target = [1,1,1,1]
Output: 1

Constraints:
1 <= target.length <= 10^5
1 <= target[i] <= 10^5
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

class Solution {
public:
    int raise(int level, vector<int>& target, int begin, int end) {
        if (begin > end)
            return 0;
        int index = get_index(target, begin, end);
        int res = target[index] - level;
        return res + raise(target[index], target, begin, index-1) + raise(target[index], target, index+1, end);
    }

    static const int index_size = 1001;
    static const int segment_size = 100;

    int get_index(vector<int>& target, int begin, int end) {
        int res = -1;
        for (int i = begin / segment_size; i <= end / segment_size; ++i) {
            int seg_begin = i * segment_size, seg_end = seg_begin + segment_size -1;
            if (begin <= seg_begin && seg_end <= end) {
                if (res < 0 || target[min_index[i]] < target[res])
                    res = min_index[i];
            } else {
                for (int j = max(begin, seg_begin); j <= min(end, seg_end); ++j) {
                    if (res < 0 || target[j] < target[res])
                        res = j;
                }
            }
        }
        return res;
    }

    void init(vector<int>& target) {
        int sz = target.size();
        int isz = sz / segment_size + 1;
        min_index.resize(index_size, 0);
        for (int i = 0; i < isz; ++i) {
            int ind = -1;
            for (int j = i * segment_size; j < min(sz, (i+1)*segment_size); ++j) {
                if (ind < 0 || target[j] < target[ind])
                    ind = j;
            }
            min_index[i] = ind;
        }
    }

    int minNumberOperations(vector<int>& target) {
        init(target);
        return raise(0, target, 0, target.size() - 1);
    }

    vector<int> min_index;
};

int main() {
    Solution sol;
    vector<int> target;

    // Output: 3
    target = {1,2,3,2,1};
    cout << sol.minNumberOperations(target) << endl;

    // Output: 4
    target = {3,1,1,2};
    cout << sol.minNumberOperations(target) << endl;

    // Output: 7
    target = {3,1,5,4,2};
    cout << sol.minNumberOperations(target) << endl;

    // Output: 1
    target = {1,1,1,1};
    cout << sol.minNumberOperations(target) << endl;

    return 0;
}
