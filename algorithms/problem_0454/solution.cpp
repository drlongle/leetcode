/*

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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> table;
        for (int c: C) {
            for (int d: D)
                ++table[-c-d];
        }
        int cnt = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = A[i] + B[j];
                cnt += table[t];
            }
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> A, B, C, D;

    A = { 1, 2};
    B = {-2,-1};
    C = {-1, 2};
    D = { 0, 2};
    cout << sol.fourSumCount(A, B, C, D) << endl;

    return 0;
}
