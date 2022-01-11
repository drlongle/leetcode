/*
1183. Maximum Number of Ones
Hard

Consider a matrix M with dimensions width * height, such that every cell has value 0 or 1, and any square sub-matrix of M of size sideLength * sideLength has at most maxOnes ones.

Return the maximum possible number of ones that the matrix M can have.

Example 1:
Input: width = 3, height = 3, sideLength = 2, maxOnes = 1
Output: 4
Explanation:
In a 3*3 matrix, no 2*2 sub-matrix can have more than 1 one.
The best solution that has 4 ones is:
[1,0,1]
[0,0,0]
[1,0,1]

Example 2:
Input: width = 3, height = 3, sideLength = 2, maxOnes = 2
Output: 6
Explanation:
[1,0,1]
[1,0,1]
[1,0,1]
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
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        vector<vector<int>> counts(sideLength, vector<int>(sideLength, 0));
        for (int i = 0; i < width; ++i)
            for (int j = 0; j < height; ++j) {
                ++counts[i % sideLength][j % sideLength];
            }
        priority_queue<int> pq;
        for (int i = 0; i < sideLength; ++i)
            for (int j = 0; j < sideLength; ++j) {
                pq.emplace(counts[i][j]);
            }

        int result = 0;
        for (int i = 0; i < maxOnes; ++i) {
            result += pq.top();
            pq.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;
    int width, height, sideLength, maxOnes;

    // Output: 4
    width = 3, height = 3, sideLength = 2, maxOnes = 1;

    // Output: 6
    width = 3, height = 3, sideLength = 2, maxOnes = 2;

    // Output = 10
    width = 4, height = 4, sideLength = 3, maxOnes = 4;

    // 31 / 105 test cases passed.
    // Expected: 42
    width = 10, height = 10, sideLength = 4, maxOnes = 5;
    
    cout << "Result: " << sol.maximumNumberOfOnes(width, height, sideLength, maxOnes) << endl;
    
    return 0;
}
