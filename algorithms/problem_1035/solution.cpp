/*
1035. Uncrossed Lines
Medium

We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

A[i] == B[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.

Example 1:
Input: A = [1,4,2], B = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.

Example 2:
Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
Output: 3

Example 3:
Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
Output: 2

Note:
1 <= A.length <= 500
1 <= B.length <= 500
1 <= A[i], B[i] <= 2000
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

#define ll long long
#define ull unsigned long long


class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i] == B[j])
                    dp[i][j] = 1 + (i>0 && j> 0 ? dp[i-1][j-1] : 0);
                else {
                    dp[i][j] = max({(i>0) ? dp[i-1][j] : 0, (j>0) ? dp[i][j-1] : 0});
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
    vector<int> A, B;

    // Output: 2
    A = {1,4,2}, B = {1,2,4};
    cout << sol.maxUncrossedLines(A, B) << endl;

    // Output: 3
    A = {2,5,1,2,5}, B = {10,5,2,1,5,2};
    cout << sol.maxUncrossedLines(A, B) << endl;
    
    // Output: 2
    A = {1,3,7,1,7,5}, B = {1,9,2,5,1};
    cout << sol.maxUncrossedLines(A, B) << endl;
    
    return 0;
}
