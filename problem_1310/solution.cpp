/*
1310. XOR Queries of a Subarray
Medium

Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], for each query i compute the XOR of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). Return an array containing the result for the given queries.

Example 1:
Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8

Example 2:
Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]

Constraints:
1 <= arr.length <= 3 * 10^4
1 <= arr[i] <= 10^9
1 <= queries.length <= 3 * 10^4
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] < arr.length
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

// https://www.geeksforgeeks.org/segment-tree-xor-given-range/

class SegmentTree {
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();

        // Height of segment tree 
        int x = (int)(ceil(log2(n))); 
  
        // Maximum size of segment tree 
        int max_size = 2*(int)pow(2, x) - 1;
  
        // Allocate memory 
        t.resize(max_size, 0);
        
        build(arr, 0, n-1, 0);
    }

    // A recursive function that constructs
    // Segment Tree for array[ss..se]. si is 
    // index of current node in segment tree st 
    int build(vector<int>& arr, int ss, int se, int si) {
        if (ss == se) {
            t[si] = arr[ss];
        } else {
            int mid = (ss + se) / 2;
            t[si] = build(arr, ss, mid, si*2+1) ^ build(arr, mid+1, se, si*2+2);
        }
        return t[si];
    }

    /* A recursive function to get the Xor of 
       values in given range of the array. The 
       following are parameters for this function. 
       st --> Pointer to segment tree 
       si --> Index of current node in the segment tree. 
       Initially 0 is passed as root is always at index 0. 
       ss & se --> Starting and ending indexes of the segment represented by current  
       node, i.e., st[si] 
       qs & qe --> Starting and ending indexes of query range */
    int getXorUtil(int ss, int se, int qs, int qe, int si) 
    { 
        // If segment of this node is a part of given 
        // range, then return the Xor of the segment
        if (qs <= ss && qe >= se)
            return t[si];
  
        // If segment of this node is outside 
        // the given range 
        if (se < qs || ss > qe) 
            return 0;
  
        // If a part of this segment overlaps  
        // with the given range 
        int mid = (ss + se) / 2;
        return getXorUtil(ss, mid, qs, qe, 2*si+1) ^ getXorUtil(mid+1, se, qs, qe, 2*si+2); 
    }
    
    int query(vector<int>& query) {
        return getXorUtil(0, n-1, query[0], query[1], 0); 
    }
    
private:
    vector<int> t;
    int n;
};

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        SegmentTree tree(arr);
        for (auto& q: queries)
            res.emplace_back(tree.query(q));
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> queries;
    vector<int> arr;
    
    // Output: {2,7,14,8} 
    arr = {1,3,4,8}, queries = {{0,1},{1,2},{0,3},{3,3}};

    // Output: {8,0,4,4}
    //arr = {4,8,2,10}, queries = {{2,3},{1,3},{0,0},{0,3}};

    auto res = sol.xorQueries(arr, queries);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    return 0;
}
