/*
1337. The K Weakest Rows in a Matrix
Easy

Given a m * n matrix mat of ones (representing soldiers) and zeros (representing civilians), return the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.

A row i is weaker than row j, if the number of soldiers in row i is less than the number of soldiers in row j, or they have the same number of soldiers but i is less than j. Soldiers are always stand in the frontier of a row, that is, always ones may appear first and then zeros.

Example 1:

Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 2 
row 1 -> 4 
row 2 -> 1 
row 3 -> 2 
row 4 -> 5 
Rows ordered from the weakest to the strongest are [2,0,3,1,4]
Example 2:

Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 1 
row 1 -> 4 
row 2 -> 1 
row 3 -> 1 
Rows ordered from the weakest to the strongest are [0,2,3,1]

Constraints:

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.
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
    struct Row {
        Row(int s, int i): soldiers(s), index(i) {}
        bool operator<(const Row& other) const {
            return (soldiers < other.soldiers) || (soldiers == other.soldiers && index < other.index);
        }
        int soldiers, index;
    };
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        int m = mat.size();
        int n = mat[0].size();
        priority_queue<Row, vector<Row>> pq;
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n && mat[i][j]; ++j)
                ++cnt;
            pq.emplace(cnt, i);
            if ((int) pq.size() > k)
                pq.pop();
            
        }

        while ((int) pq.size() > 0) {
            res.emplace_back(pq.top().index);
            pq.pop();
        }
        reverse(begin(res), end(res));
                    
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat;
    int k;

    // Output: {2,0,3}
    mat = 
        {{1,1,0,0,0},
         {1,1,1,1,0},
         {1,0,0,0,0},
         {1,1,0,0,0},
         {1,1,1,1,1}};
    k = 3;

    // Output: {0,2}
    /*
    mat = 
        {{1,0,0,0},
         {1,1,1,1},
         {1,0,0,0},
         {1,0,0,0}};
    k = 2;
    */
    
    auto res = sol.kWeakestRows(mat, k);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    return 0;
}
