/*
718. Maximum Length of Repeated Subarray
Medium

Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].

Note:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
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
    struct Node {
        map<int, Node> nodes;
    };
    
    int findLength(vector<int>& A, vector<int>& B) {
        int sza = A.size();
        for (int i = 0; i < sza; ++i) {
            Node* n = &root;
            for (int j = i; j < sza; ++j) {
                n = &(n->nodes[A[j]]);
            }
        }

        int szb = B.size();
        int res = 0;
        for (int i = 0; i < szb; ++i) {
            
            Node* n = &root;
            int r = 0;
            for (int j = i; j < szb; ++j, ++r) {
                auto it = n->nodes.find(B[j]);
                if (it == n->nodes.end())
                    break;
                n = &(it->second);
            }
            res = max(res, r);
            if (res == min(sza, szb - i))
                break;
        }
        return res;
    }

    Node root;
};

int main() {
    Solution sol;
    vector<int> A, B;
    
    A = {1,2,3,2,1};
    B = {3,2,1,4,7};

    cout << "Result: " << sol.findLength(A, B) << endl;
    
    return 0;
}
