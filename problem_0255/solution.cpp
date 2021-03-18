/*
255. Verify Preorder Sequence in Binary Search Tree
Medium

Given an array of unique integers preorder, return true if it is the correct preorder
traversal sequence of a binary search tree.

Example 1:
Input: preorder = [5,2,1,3,6]
Output: true

Example 2:
Input: preorder = [5,2,6,1,3]
Output: false

Constraints:
1 <= preorder.length <= 10^4
1 <= preorder[i] <= 10^4
All the elements of preorder are unique.

Follow up: Could you do it using only constant space complexity?
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    bool verify(vector <int>& v, int s, int e) {
        if (s >= e) return true;
        int i = s+1, val = v[s];
        while (i < e && v[i] < val)
            ++i;
        for (int j=i;j<e;++j){
            if(v[j]<val)
                return false;
        }
        return verify(v, s+1,i) && verify(v, i,e);
    }

    bool verifyPreorder(vector<int>& v) {
        return verify(v,0, v.size ());
    }
};

int main() {
    Solution sol;

    return 0;
}
