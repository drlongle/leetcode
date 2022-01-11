/*
996. Number of Squareful Arrays
Difficulty: Hard

Given an array A of non-negative integers, the array is squareful if
for every pair of adjacent elements, their sum is a perfect square.
Return the number of permutations of A that are squareful. Two permutations
A1 and A2 differ if and only if there is some index i such that A1[i] != A2[i].

Example 1:

Input: [1,17,8]
Output: 2
Explanation:
[1,8,17] and [17,8,1] are the valid permutations.

Example 2:
Input: [2,2,2]
Output: 1

Note:
1 <= A.length <= 12
0 <= A[i] <= 1e^9
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
    bool isSquare(int num) {
        int q = sqrt(num);
        return q*q == num;
    }

    vector<int> used;

    int countSquarePerms(vector<int>& nums, int level, int last) {
        if (level == nums.size())
            return 1;

        int count = 0;
        set<int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i] && seen.count(nums[i]) == 0 && (level == 0 || isSquare(nums[i]+last))) {
                used[i] = 1;
                seen.emplace(nums[i]);
                count += countSquarePerms(nums, level+1, nums[i]);
                used[i] = 0;
            }
        }
        return count;
    }

    int numSquarefulPerms(vector<int>& A) {
        used.resize(A.size());
        fill(begin(used), end(used), 0);

        return countSquarePerms(A, 0, 0);
    }
};

int main() {
    Solution sol;
    vector<int> A;

    // Expected: 1
    A = {2,2,2};

    // Expected: 2
    A = {1,17,8};

    cout << "Result: " << sol.numSquarefulPerms(A) << endl;

    return 0;
}
