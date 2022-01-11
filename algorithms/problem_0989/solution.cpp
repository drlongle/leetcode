/*
989. Add to Array-Form of Integer
Difficulty: Easy

For a non-negative integer X, the array-form of X is an array of its digits in
left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of
the integer X+K.
 
Example 1:
Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234

Example 2:
Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455

Example 3:
Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021

Example 4:
Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000
 

Note
1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
If A.length > 1, then A[0] != 0
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
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> B, res;
        
        while (K) {
            B.push_back(K % 10);
            K /= 10;
        }
        if (B.empty())
            B.push_back(0);
        reverse(begin(A), end(A));

        for (int carry = 0, i = 0; i < max(A.size(), B.size()) || carry; ++i) {
            int num = carry;
            if (i < A.size())
                num += A[i];
            if (i < B.size())
                num += B[i];
            carry = (num >= 10);
            res.push_back(num % 10);
        }

        reverse(begin(res), end(res));
        return res;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<int> A, res;
    int K;
    
    // Expected: [1,2,3,4]
    A = {1,2,0,0}, K = 34;

    // Expected t: [4,5,5]    
    A = {2,7,4}, K = 181;
    
    // Expected: [1,0,2,1]
    A = {2,1,5}, K = 806;
    
    res = sol.addToArrayForm(A, K);
    
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    
    return 0;
}
