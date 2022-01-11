/*
1051. Height Checker
Easy

Students are asked to stand in non-decreasing order of heights for an annual photo.

Return the minimum number of students that must move in order for all students to be standing in non-decreasing order of height.

Example 1:

Input: heights = [1,1,4,2,1,3]
Output: 3 

Constraints:

1 <= heights.length <= 100
1 <= heights[i] <= 100
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
    int heightChecker(vector<int>& heights) {
        vector<int> h(heights);
        sort(begin(h), end(h));
        int res = 0, sz = h.size();
        for (int i = 0; i < sz; ++i)
            if (h[i] != heights[i])
                ++res;
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> heights;

    // Output: 3
    heights = {1,1,4,2,1,3};

    cout << "Result: " << sol.heightChecker(heights) << endl;

    return 0;
}
