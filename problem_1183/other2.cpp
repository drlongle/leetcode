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
        if (width < height) {
            swap(width, height);
        }

        const auto& R = height / sideLength, &r = height % sideLength;
        const auto& C = width / sideLength, &c = width % sideLength;
        assert(R <= C);
        vector<pair<int, int>> area_counts = {{r * c, (R + 1) * (C + 1)},
                                              {r * (sideLength - c), (R + 1) * C},
                                              {(sideLength - r) * c, R * (C + 1)},
                                              {(sideLength - r) * (sideLength - c), R * C}};
        int result = 0;
        for (const auto& [area, count] : area_counts) {
            result += count * min(maxOnes, area);
            maxOnes -= min(maxOnes, area);
            if (!maxOnes) {
                break;
            }
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
