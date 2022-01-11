/*
952. Largest Component Size by Common Factor
Hard

Given a non-empty array of unique positive integers A, consider the following graph:

There are A.length nodes, labelled A[0] to A[A.length - 1];
There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

Example 1:
Input: [4,6,15,35]
Output: 4

Example 2:
Input: [20,50,9,63]
Output: 2

Example 3:
Input: [2,3,6,7,4,12,21,39]
Output: 8

Note:
1 <= A.length <= 20000
1 <= A[i] <= 100000
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

using namespace std;

class Solution {
public:
    vector<int> primes;
    vector<int> roots;
    vector<int> factors;
    vector<size_t> groups;
    size_t res;

    Solution (): roots(100001), factors(20001, -1), groups(100001)
    {

    }

    inline int get_root(int node) {
        while (true) {
            int next = roots[node];
            if (next == node)
                break;
            node = next;
        }

        return node;
    }

    inline void join_root(int node, int root) {
        while (node != root) {
            int& next = roots[node];
            if (next == root)
                break;
            node = next;
            next = root;
        }
    }

    void get_primes(int n) {
        vector<int> nums(n + 1, true);
        int sq = sqrt(n);
        for (int i = 2; i <= n; ++i) {
            if (nums[i]) {
                primes.push_back(i);
                if (i > sq)
                    continue;
                for (int j = i*i; j <= n; j += i)
                    nums[j] = false;
            }
        }
    }

    void get_factors(vector<int>& nums, int id) {
        int n = nums[id];
        int& root = factors[id];
        if (binary_search(begin(primes), end(primes), n)) {
            root = n;
            return;
        }

        int64_t limit = n / 2;

        for (int p: primes) {
            if (n % p == 0) {
                int64_t prod = p;
                while (n % prod == 0) {
                    limit = min(limit, n / prod);
                    prod *= p;
                }
                if (root < 0) {
                    root = p;
                    continue;
                }
                int rr = get_root(root);
                int rp = get_root(p);
                if (rp < rr)
                    join_root(root, rp);
                else if (rp > rr)
                    join_root(p, rr);
            }
            if (p >= limit)
                break;
        }
    }

    int largestComponentSize(vector<int>& A) {
        size_t sz = A.size();
        get_primes(100000);

        iota(begin(roots), end(roots), 0);
        for (size_t i = 0; i < sz; ++i) {
            if (A[i] == 1)
                continue;
            get_factors(A, i);
        }

        res = 1;
        for (size_t i = 0; i < sz; ++i) {
            if (A[i] == 1)
                continue;
            int root = get_root(factors[i]);
            res = max(res, ++groups[root]);
            if (res == sz)
                break;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: 4
    {
        Solution sol;
        nums = {4,6,15,35};
        cout << sol.largestComponentSize(nums) << endl;
    }

    // Output: 2
    {
        Solution sol;
        nums = {20,50,9,63};
        cout << sol.largestComponentSize(nums) << endl;
    }

    // Output: 8
    {
        Solution sol;
        nums = {2,3,6,7,4,12,21,39};
        cout << sol.largestComponentSize(nums) << endl;
    }

    // Output: 4
    {
        Solution sol;
        nums = {83,99,39,11,19,30,31};
        cout << sol.largestComponentSize(nums) << endl;
    }

    {
        Solution sol;
        nums = {1,2,3,4,5,6,7,8,9};
        cout << sol.largestComponentSize(nums) << endl;
    }

    return 0;
}
