/*
985. Sum of Even Numbers After Queries
Difficulty: Easy

We have an array A of integers, and an array queries of queries.
For the i-th query val = queries[i][0], index = queries[i][1], we add val to
A[index].  Then, the answer to the i-th query is the sum of the even values of A.

(Here, the given index = queries[i][1] is a 0-based index, and each query
permanently modifies the array A.)

Return the answer to all queries.  Your answer array should have answer[i] as
the answer to the i-th query.

Example 1:

Input: A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
Output: [8,6,2,4]
Explanation: 
At the beginning, the array is [1,2,3,4].
After adding 1 to A[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
After adding -3 to A[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
After adding -4 to A[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
After adding 2 to A[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.
 
Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
1 <= queries.length <= 10000
-10000 <= queries[i][0] <= 10000
0 <= queries[i][1] < A.length
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
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for (auto& n: nums) {
            if ((n & 1) == 0) {
                sum += n;
            }
        }
        
        vector<int> res;
        for (auto& q: queries) {
            int index = q[1];
            int val = q[0];
            int prev = nums[index];
            if ((prev & 1) == 0)
                sum -= prev;
            int curr = prev + val;
            if ((curr & 1) == 0)
                sum += curr;
            nums[index] = curr;
            res.emplace_back(sum);
        }
        
        return res;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<int> nums, res;
    vector<vector<int>> queries;
    
    nums = {1,2,3,4};
    queries = {{1,0},{-3,1},{-4,0},{2,3}};
        
    //nums = {8,-10,10,-7,4,-2};
    //queries = {{6,4},{-7,0},{-3,5},{6,1},{-8,1},{-10,2}};
    
    res = sol.sumEvenAfterQueries(nums, queries);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    
    return 0;
}
