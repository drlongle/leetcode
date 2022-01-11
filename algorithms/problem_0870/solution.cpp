/*
870. Advantage Shuffle
Medium

Given two arrays A and B of equal size, the advantage of A with respect to B is the number of
indices i for which A[i] > B[i].

Return any permutation of A that maximizes its advantage with respect to B.

Example 1:
Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]

Example 2:
Input: A = [12,24,8,32], B = [13,25,32,11]
Output: [24,32,8,12]

Note:
1 <= A.length = B.length <= 10000
0 <= A[i] <= 10^9
0 <= B[i] <= 10^9
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
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> nums(A.begin(), A.end());
        int n = A.size();
        vector<int> ind(n), res(n);
        iota(ind.begin(), ind.end(), 0);
        auto lambda = [&B] (int i, int j) {return B[i] < B[j];};
        sort(begin(ind), end(ind), lambda);

        for (int i = 0; i < n; ++i) {
            int b = B[ind[i]];
            auto it = nums.upper_bound(b);
            if (it == nums.end())
                it = nums.begin();
            res[ind[i]] = *it;
            nums.erase(it);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> A, B;

    // Output: {2,11,7,15}
    A = {2,7,11,15}, B = {1,10,4,11};
    A = sol.advantageCount(A, B);
    copy(begin(A), end(A), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {24,32,8,12}
    A = {12,24,8,32}, B = {13,25,32,11};
    A = sol.advantageCount(A, B);
    copy(begin(A), end(A), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
