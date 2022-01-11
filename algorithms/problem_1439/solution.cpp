/*
1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows
Hard

You are given an m * n matrix, mat, and an integer k, which has its rows sorted in non-decreasing order.
You are allowed to choose exactly 1 element from each row to form an array. Return the Kth smallest array sum among all possible arrays.

Example 1:
Input: mat = [[1,3,11],[2,4,6]], k = 5
Output: 7
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.  

Example 2:
Input: mat = [[1,3,11],[2,4,6]], k = 9
Output: 17

Example 3:
Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
Output: 9
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. Where the 7th sum is 9.  

Example 4:
Input: mat = [[1,1,10],[2,2,9]], k = 7
Output: 12

Constraints:
m == mat.length
n == mat.length[i]
1 <= m, n <= 40
1 <= k <= min(200, n ^ m)
1 <= mat[i][j] <= 5000
mat[i] is a non decreasing array.
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
    int kthSmallest(vector<vector<int>>& mat, int k) {
        set< pair<int, vector<int> > > s;
        pair<int,vector<int>> vec;
        for(int i=0;i<mat.size();i++){
            vec.second.push_back(0);
            vec.first+=mat[i][0];
        }
        s.insert(vec);
        if(k==1){
            return vec.first;
        }
        while(k>1){
            auto itr = s.begin();
            pair<int, vector<int> > a = (*itr);
            s.erase(itr);
            for(int i=0;i<mat.size();i++){
                if(a.second[i]+1 < mat[i].size()){
                    a.first +=  mat[i][a.second[i]+1] - mat[i][a.second[i]];
                    a.second[i]++;
                    s.insert(a);
                    a.second[i]--;
                    a.first += mat[i][a.second[i]] - mat[i][a.second[i]+1];
                    
                }
            }
            k--;
        }
        auto temp = s.begin();
        int ans= (*temp).first;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat;
    int k;

    // {1,2}, {1,4}, {3,2}, {3,4}, {1,6}. Where the 5th sum is 7.
    // Output: 7
    mat = {{1,3,11},{2,4,6}}, k = 5;
    //cout << sol.kthSmallest(mat, k) << endl;
    
    // Output: 17
    mat = {{1,3,11},{2,4,6}}, k = 9;
    cout << sol.kthSmallest(mat, k) << endl;

    // Explanation: Choosing one element from each row, the first k smallest sum are:
    // {1,1,2}, {1,1,3}, {1,4,2}, {1,4,3}, {1,1,6}, {1,5,2}, {1,5,3}. Where the 7th sum is 9.  
    // Output: 9
    mat = {{1,10,10},{1,4,5},{2,3,6}}, k = 7;
    cout << sol.kthSmallest(mat, k) << endl;

    // Output: 12
    mat = {{1,1,10},{2,2,9}}, k = 7;
    cout << sol.kthSmallest(mat, k) << endl;
    
    return 0;
}
