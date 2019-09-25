/*
1198. Find Smallest Common Element in All Rows
Medium

Given a matrix mat where every row is sorted in increasing order, return the smallest
common element in all rows. If there is no common element, return -1.

Example 1:
Input: mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
Output: 5

Constraints:

1 <= mat.length, mat[i].length <= 500
1 <= mat[i][j] <= 10^4
mat[i] is sorted in increasing order.
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

struct Entry {
    Entry(int v, int i): val(v), index(i) {}
    int val;
    int index;

    bool operator<(const Entry& other) const {
        return val > other.val;
    }
};

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        priority_queue<Entry> pq;
        int sz = mat.size();
        vector<int> index(sz);
        for (int i = 0; i < sz; ++i) {
            if (mat[i].empty())
                return -1;
            pq.emplace(mat[i][0], i);
            index[i] = 0;
        }

        while (!pq.empty()) {
            auto& e = pq.top();
            int i;
            for (i = 0; i < sz; ++i) {
                if (mat[i][index[i]] != e.val)
                    break;
            }
            if (i == sz)
                return e.val;
            if (index[e.index] == static_cast<int>(mat[e.index].size()) - 1)
                return -1;
            i = ++index[e.index];
            pq.emplace(mat[e.index][i], e.index);
            pq.pop();
        }
        
        return -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix;
    matrix = {{1,2,3,4,5},{2,4,5,8,10},{3,5,7,9,11},{1,3,5,7,9}};

    cout << "Result: " << sol.smallestCommonElement(matrix) << endl;
    
    return 0;
}
