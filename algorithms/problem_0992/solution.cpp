/*
992. Subarrays with K Different Integers
Difficulty: Hard

Given an array A of positive integers, call a (contiguous, not necessarily
distinct) subarray of A good if the number of different integers in that
subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.

Example 1:
Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1],
[1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].

Example 2:
Input: A = [1,2,1,3,4], K = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3],
[2,1,3], [1,3,4].
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
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

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int K) {
        map<int, int> counts;
        int res = 0, nsize = nums.size();
        for (int begin1 = 0, end = 0; begin1 < nsize; ++begin1, ++end) {
            bool full = false;
            for ( ; begin1 < nsize; ++begin1) {
                ++counts[nums[begin1]];
                if (counts.size() == K) {
                    full = true;
                    break;
                }
            }
            if (!full)
                break;
            int begin2;
            for (begin2 = begin1+1; begin2 < nsize; ++begin2) {
                if (counts.count(nums[begin2]) == 0)
                    break;
            }


            for ( ; end < nsize; ++end) {
                for (int i = begin1; i < begin2; ++i) {
                    ++counts[nums[i]];
                    if (i-end+2 > K && counts.size() >= K)
                        ++res;
                    --counts[nums[i]];
                }
                if (--counts[nums[end]] <= 0) {
                    counts.erase(nums[end]);
                    break;
                }
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<int> A;
    int K;
    
    // Expected: 7
    A = {1,2,1,2,3}, K = 2;
    
    // Expected: 3
    A = {1,2,1,3,4}, K = 3;
    
    // Expected: 2
    //A = {1,2}, K = 1;
    
    // Expected: 23
    A = {2,2,1,2,2,2,1,1}, K = 2;
    
    cout << "Result: " << sol.subarraysWithKDistinct(A, K) << endl;
    
    return 0;
}
