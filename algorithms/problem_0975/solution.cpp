/*
975. Odd Even Jump
Difficulty: Hard

You are given an integer array A.  From some starting index, you can make a
series of jumps.  The (1st, 3rd, 5th, ...) jumps in the series are called odd 
numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the series are called
even numbered jumps.

You may from index i jump forward to index j (with i < j) in the following way:

During odd numbered jumps (ie. jumps 1, 3, 5, ...), you jump to the index j
such that A[i] <= A[j] and A[j] is the smallest possible value. If there are
multiple such indexes j, you can only jump to the smallest such index j.
During even numbered jumps (ie. jumps 2, 4, 6, ...), you jump to the index j
such that A[i] >= A[j] and A[j] is the largest possible value.  If there are
multiple such indexes j, you can only jump to the smallest such index j.
(It may be the case that for some index i, there are no legal jumps.)
A starting index is good if, starting from that index, you can reach the end
of the array (index A.length - 1) by jumping some number of times
(possibly 0 or more than once.)

Return the number of good starting indexes.

Example 1:
Input: [10,13,12,14,15]
Output: 2
Explanation: 
From starting index i = 0, we can jump to i = 2 (since A[2] is the smallest
among A[1], A[2], A[3], A[4] that is greater or equal to A[0]), then we can't
jump any more.
From starting index i = 1 and i = 2, we can jump to i = 3, then we can't jump any more.
From starting index i = 3, we can jump to i = 4, so we've reached the end.
From starting index i = 4, we've reached the end already.
In total, there are 2 different starting indexes (i = 3, i = 4) where we can
reach the end with some number of jumps.

Example 2:
Input: [2,3,1,1,4]
Output: 3
Explanation: 
From starting index i = 0, we make jumps to i = 1, i = 2, i = 3:

During our 1st jump (odd numbered), we first jump to i = 1 because A[1] is the
smallest value in (A[1], A[2], A[3], A[4]) that is greater than or equal to A[0].

During our 2nd jump (even numbered), we jump from i = 1 to i = 2 because A[2]
is the largest value in (A[2], A[3], A[4]) that is less than or equal to A[1].
A[3] is also the largest value, but 2 is a smaller index, so we can only jump
to i = 2 and not i = 3.

During our 3rd jump (odd numbered), we jump from i = 2 to i = 3 because A[3]
is the smallest value in (A[3], A[4]) that is greater than or equal to A[2].

We can't jump from i = 3 to i = 4, so the starting index i = 0 is not good.

In a similar manner, we can deduce that:
From starting index i = 1, we jump to i = 4, so we reach the end.
From starting index i = 2, we jump to i = 3, and then we can't jump anymore.
From starting index i = 3, we jump to i = 4, so we reach the end.
From starting index i = 4, we are already at the end.
In total, there are 3 different starting indexes (i = 1, i = 3, i = 4) where
we can reach the end with some number of jumps.

Example 3:
Input: [5,1,3,4,2]
Output: 3
Explanation: 
We can reach the end from starting indexes 1, 2, and 4.
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

class Solution {
public:
    bool jump(int i, bool odd, vector<int>& nums) {
        int nsize = nums.size();
        if (i == nsize-1) return true;
        auto it1 = cache.find(i);
        if (it1 != cache.cend()) {
            auto it2 = it1->second.find(odd);
            if (it2 != it1->second.cend())
                return it2->second;
        }
        
        bool res = false;
        if (odd) {
            auto it = look_up.find(i);
            if (it != look_up.cend())
                res = jump(it->second, false, nums);
        } else {
            auto it = look_down.find(i);
            if (it != look_down.cend())
                res = jump(it->second, true, nums);
        }
        cache[i][odd] = res;
        
        return res;
    }

    int oddEvenJumps(vector<int>& nums) {
        int res = 0;
        int nsize = nums.size();
        
        map<int, int> up;
        map<int, int, greater<int>> down;
        for (int i = nsize-1; i >= 0; --i) {
            int n = nums[i];
            auto it1 = up.lower_bound(n);
            if (it1 != up.cend())
                look_up[i] = it1->second;
            auto it2 = down.lower_bound(n);
            if (it2 != down.cend())
                look_down[i] = it2->second;
            up[n] = i;
            down[n] = i;
        }
        
        for (int i = 0; i < nsize; ++i) {
            res += jump(i, true, nums);
        }
        return res;
    }
    
    map<int, int> look_up;
    map<int, int> look_down;
    map<int, map<int, bool>> cache;
};

int main(int argc, char** argv) {
    Solution sol;
    vector<int> nums;

    // Expected: 2
    nums = {10,13,12,14,15};
    
    // Expected: 3
    nums = {2,3,1,1,4};
    
    // Expected: 3
    nums = {5,1,3,4,2};
    
    cout << "Result: " << sol.oddEvenJumps(nums) << endl;
    
    /*
    map<int, string, greater<int>> candidates{{1, "a"}, {2, "b"}, {4, "d"}, {5, "e"}};
    for (auto& c: candidates)
        cout << c.first << " - " << c.second << endl;
    auto it = candidates.lower_bound(3);
    cout << "lower bound: " << it->first << " - " << it->second << endl;
    */
    
    return 0;
}
