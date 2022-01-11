/*
444. Sequence Reconstruction
Medium

Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs.
The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction
means building a shortest common supersequence of the sequences in seqs (i.e., a shortest
sequence so that all sequences in seqs are subsequences of it). Determine whether there is
only one sequence that can be reconstructed from seqs and it is the org sequence.

Example 1:
Input: org = [1,2,3], seqs = [[1,2],[1,3]]
Output: false
Explanation: [1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is
also a valid sequence that can be reconstructed.

Example 2:
Input: org = [1,2,3], seqs = [[1,2]]
Output: false
Explanation: The reconstructed sequence can only be [1,2].

Example 3:
Input: org = [1,2,3], seqs = [[1,2],[1,3],[2,3]]
Output: true
Explanation: The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3]Example 4:

Example 4:
Input: org = [4,1,5,2,6,3], seqs = [[5,2,6,3],[4,1,5,2]]
Output: true

Constraints:
1 <= n <= 10^4
org is a permutation of {1,2,...,n}.
1 <= segs[i].length <= 10^5
seqs[i][j] fits in a 32-bit signed integer.
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

/*
 * Unique reconstruction means that all numbers have a unique position (order) in a sorted array.
 * Use topology sorting to find the order of the numbers and the reconstruct the sequence.
 */

class Solution {
public:

    vector<unordered_set<int>> nodes;
    vector<int> state, depth;

    int get_depth(int i) {
        if (state[i] == 1)
            return -1;
        if (state[i] == 2)
            return depth[i];
        state[i] = 1;
        for (int j: nodes[i]) {
            int d = get_depth(j);
            if (d < 0)
                return -1;
            depth[i] = max(depth[i], 1 + d);
        }
        state[i] = 2;

        return depth[i];
    }

    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int sz = seqs.size(), n = org.size();
        nodes.resize(n+1);
        state.resize(n+1, 0), depth.resize(n+1, 0);
        unordered_set<int> uniq;
        for (int i = 0; i < sz; ++i) {
            if (seqs[i][0] <= 0 || seqs[i][0] > n)
                return false;
            uniq.emplace(seqs[i][0]);
            for (size_t j = 1, ssz = seqs[i].size(); j < ssz; ++j) {
                nodes[seqs[i][j-1]].emplace(seqs[i][j]);
                if (seqs[i][j] <= 0 || seqs[i][j] > n)
                    return false;
                uniq.emplace(seqs[i][j]);
            }
        }

        int max_depth = 0;
        for (int i = 1; i <= n; ++i) {
            int d = get_depth(i);
            if (d < 0)
                return false;
            max_depth = max(d, max_depth);
        }
        if (max_depth != n-1)
            return false;

        vector<int> reconstructed(uniq.begin(), uniq.end());
        auto lambda = [&] (int i, int j) {return depth[i] > depth[j];};
        sort(begin(reconstructed), end(reconstructed), lambda);

        return reconstructed == org;
    }
};

int main() {
    vector<vector<int>> seqs;
    vector<int> org;

    // Output: false
    {
        Solution sol;
        org = {1,2,3}, seqs = {{1,2},{1,3}};
        cout << boolalpha << sol.sequenceReconstruction(org,seqs) << endl;
    }

    // Output: false
    {
        Solution sol;
        org = {1,2,3}, seqs = {{1,2}};
        cout << boolalpha << sol.sequenceReconstruction(org,seqs) << endl;
    }

    // Output: true
    {
        Solution sol;
        org = {1,2,3}, seqs = {{1,2},{1,3},{2,3}};
        cout << boolalpha << sol.sequenceReconstruction(org,seqs) << endl;
    }

    // Output: true
    {
        Solution sol;
        org = {4,1,5,2,6,3}, seqs = {{5,2,6,3},{4,1,5,2}};
        cout << boolalpha << sol.sequenceReconstruction(org,seqs) << endl;
    }

    // Output: false
    {
        Solution sol;
        org = {5,4,8,9,1,6,3,2,7,10}, seqs = {{8,9,1},{6,3,2,7,10},{5,4}};
        cout << boolalpha << sol.sequenceReconstruction(org,seqs) << endl;
    }

    // Output: false
    {
        Solution sol;
        org = {1}, seqs = {{1,1}};
        cout << boolalpha << sol.sequenceReconstruction(org,seqs) << endl;
    }

    // Output: true
    {
        Solution sol;
        org = {1,2,3,4,5}, seqs = {{1,2,3,4,5}};
        cout << boolalpha << sol.sequenceReconstruction(org,seqs) << endl;
    }

    // Output: true
    {
        Solution sol;
        org = {1,8,9,5,2,7,6,10,4,3}, seqs = {{1,8,9},{5,2,7},{9,5},{7,6},{6,10,4,3}};
        cout << boolalpha << sol.sequenceReconstruction(org,seqs) << endl;
    }

    // Output: false
    {
        Solution sol;
        org = {1,3,2,4}, seqs = {{1,2},{1,3},{2,4},{3,4}};
        cout << boolalpha << sol.sequenceReconstruction(org,seqs) << endl;
    }

    // Output: true
    {
        Solution sol;
        org = {1,4,2,3}, seqs = {{1,2},{1,3},{2,3},{4,2},{1,4}};
        cout << boolalpha << sol.sequenceReconstruction(org,seqs) << endl;
    }

    // Output: true
    {
        Solution sol;
        org = {10,5,4,6,8,9,7,2,3,1};
        seqs = {{5},{7,2,3,1},{4,6,8,9,7,2,3},{2,3,1},{1},{3,1},{8},{10,5,4,6,8,9,7,2,3},{9},{6,8,9,7,2,3,1}};
        cout << boolalpha << sol.sequenceReconstruction(org,seqs) << endl;
    }

    // Output: false
    {
        Solution sol;
        org = {1,2,3,4}, seqs = {{1,2,4},{2,3,4},{3,2}};
        cout << boolalpha << sol.sequenceReconstruction(org,seqs) << endl;
    }

    // Output: false
    {
        Solution sol;
        org = {5,2,4,3,1}, seqs = {{1},{2,4},{3},{5},{4}};
        cout << boolalpha << sol.sequenceReconstruction(org,seqs) << endl;
    }

    // Output: false
    {
        Solution sol;
        org = {1,2}, seqs = {{1},{2}};
        cout << boolalpha << sol.sequenceReconstruction(org,seqs) << endl;
    }

    // Output: false
    {
        Solution sol;
        org = {1}, seqs = {};
        cout << boolalpha << sol.sequenceReconstruction(org,seqs) << endl;
    }

    {
        Solution sol;
        org = {5,3,2,4,1}, seqs = {{5,3,2,4},{4,1},{1},{3},{2,4},{1000000000}};
        cout << boolalpha << sol.sequenceReconstruction(org,seqs) << endl;
    }

    return 0;
}
