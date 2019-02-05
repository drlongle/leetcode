/*
Problem 982. Triples with Bitwise AND Equal To Zero
Difficulty: Hard

Given an array of integers A, find the number of triples of indices (i, j, k)
such that:

0 <= i < A.length
0 <= j < A.length
0 <= k < A.length
A[i] & A[j] & A[k] == 0, where & represents the bitwise-AND operator.

Example
Input: [2,1,3]
Output: 12
Explanation: We could choose the following i, j, k triples:
(i=0, j=0, k=1) : 2 & 2 & 1
(i=0, j=1, k=0) : 2 & 1 & 2
(i=0, j=1, k=1) : 2 & 1 & 1
(i=0, j=1, k=2) : 2 & 1 & 3
(i=0, j=2, k=1) : 2 & 3 & 1
(i=1, j=0, k=0) : 1 & 2 & 2
(i=1, j=0, k=1) : 1 & 2 & 1
(i=1, j=0, k=2) : 1 & 2 & 3
(i=1, j=1, k=0) : 1 & 1 & 2
(i=1, j=2, k=0) : 1 & 3 & 2
(i=2, j=0, k=1) : 3 & 2 & 1
(i=2, j=1, k=0) : 3 & 1 & 2

Note:

1 <= A.length <= 1000
0 <= A[i] < 2^16
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
class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size(), ans = 0;
        vector<int> f(1 << 16, -1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int x = A[i] & A[j];
                if (f[x] == -1) {
                    f[x] = 0;
                    for (int k = 0; k < n; k++)
                        if ((x & A[k]) == 0)
                            f[x]++;
                }
                ans += f[x];
            }

        return ans;
    }
};

};

int main(int argc, char** argv) {
    Solution sol;
    vector<int> nums;
    
    // Expected: 12
    nums = {2,1,3};
    
    // Expected: 27
    //nums = {0,0,0};
    
    cout << "Result: " << sol.countTriplets(nums) << endl;
    
    return 0;
}
