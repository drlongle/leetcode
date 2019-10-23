/*
1231. Divide Chocolate
Hard

You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given
by the array sweetness. You want to share the chocolate with your K friends so you start cutting
the chocolate bar into K+1 pieces using K cuts, each piece consists of some consecutive chunks.
Being generous, you will eat the piece with the minimum total sweetness and give the other pieces
to your friends. Find the maximum total sweetness of the piece you can get by cutting the chocolate
bar optimally.

Example 1:
Input: sweetness = [1,2,3,4,5,6,7,8,9], K = 5
Output: 6
Explanation: You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]

Example 2:
Input: sweetness = [5,6,7,8,9,1,2,3,4], K = 8
Output: 1
Explanation: There is only one way to cut the bar into 9 pieces.

Example 3:
Input: sweetness = [1,2,2,1,2,2,1,2,2], K = 2
Output: 5
Explanation: You can divide the chocolate to [1,2,2], [1,2,2], [1,2,2]
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        vector<int> prefix;
        partial_sum(begin(sweetness), end(sweetness), back_inserter(prefix));
        int n = sweetness.size();
        vector<vector<int>> dp(K+2, vector<int>(n, 0));
        for (int k = 1; k <= K+1; ++k) {
            for (int i = k-1; i < n; ++i) {
                if (k == 1)
                    dp[k][i] = prefix[i];
                else {
                    dp[k][i] = min(dp[k-1][k-2], prefix[i] - prefix[k-2]);
                    int left = k-2, right = i-1;
                    while (left <= right) {
                        int j = (left + right) / 2;
                        int temp = min(dp[k-1][j], prefix[i] - prefix[j]);
                        if (dp[k][i] < temp)
                            dp[k][i] = temp;
                        if (dp[k-1][j] < prefix[i] - prefix[j])
                            left = j+1;
                        else
                            right = j-1;
                    }
                }
            }
        }
        
        return dp[K+1][n-1];
    }
};

int main() {
    Solution sol;
    vector<int> sweetness;
    int K;

    // Output: 6
    sweetness = {1,2,3,4,5,6,7,8,9}, K = 5;

    // Output: 1
    //sweetness = {5,6,7,8,9,1,2,3,4}, K = 8;

    // Output: 5
    //sweetness = {1,2,2,1,2,2,1,2,2}, K = 2;

    cout << "Result: " << sol.maximizeSweetness(sweetness, K) << endl;
    
    return 0;
}
