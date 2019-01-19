/*
396. Rotate Function
Difficulty: Medium

Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise,
we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 10^5.

Example:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
*/

#include <algorithm>
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
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    
    int rotateFunction(vector<int>& A, int k) {
        int res = 0;
        int n = A.size();
        for (int i = 0, mult = k; i < n - k; ++i, ++mult)
            res += A[i] * mult;
        for (int i = n - k, mult = 0; i < n; ++i, ++mult)
            res += A[i] * mult;
        return res;
    }
    
    int maxRotateFunction(vector<int>& A) {
        int res = rotateFunction(A, 0);
        for (int i = 1; i < A.size(); ++i)
            res = max(res, rotateFunction(A, i));

        return res;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<int> nums;
    nums = {4, 3, 2, 6};
    nums = {-2147483648,-2147483648};
    
    cout << "Result: " << sol.maxRotateFunction(nums) << endl;

    return 0;
}
