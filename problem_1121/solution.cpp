/*
1121. Divide Array Into Increasing Sequences
User Accepted: 411
User Tried: 566
Total Accepted: 450
Total Submissions: 1116
Difficulty: Hard
Given a non-decreasing array of positive integers nums and an integer K, find out if this
array can be divided into one or more disjoint increasing subsequences of length at least K.

Example 1:
Input: nums = [1,2,2,3,3,4,4], K = 3
Output: true
Explanation: 
The array can be divided into the two subsequences [1,2,3,4] and [2,3,4] with lengths at least 3 each.

Example 2:
Input: nums = [5,6,6,7,8], K = 3
Output: false
Explanation: 
There is no way to divide the array using the conditions required.

Note:
1 <= nums.length <= 10^5
1 <= K <= nums.length
1 <= nums[i] <= 10^5
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <condition_variable>
#include <cmath>
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

using vector_p = vector<int>*;

struct Compare {
    bool operator() (const vector_p& vp1, const vector_p& vp2) const {
        return vp1->size() < vp2->size() || (vp1->size() == vp2->size() && !vp1->empty() &&
                                             vp1->back() > vp2->back());
    }
};

class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        multiset<vector_p, Compare> subseqs;

        for (const auto& num: nums) {

            decltype(subseqs)::iterator it;
            bool inserted = false;
            for (it = subseqs.begin(); it != subseqs.end(); ++it) {
                if ((*it)->empty() || (*it)->back() < num) {
                    (*it)->emplace_back(num);
                    auto qp = *it;
                    subseqs.erase(it);
                    subseqs.emplace(qp);
                    inserted = true;
                    break;
                }
            }

            if (inserted)
                continue;

            vector_p qp = new vector<int>();
            qp->emplace_back(num);
            subseqs.emplace(qp);
        }

        bool res = true;
        for (auto& subseq: subseqs) {
            if (subseq->size() < K) {
                res = false;
            }

            delete subseq;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int K;

    // Expected: true
    nums = {1,2,2,3,3,4,4}, K = 3;

    // Expected: false
    //nums = {5,6,6,7,8}, K = 3;

    // Expected: true
    nums = {1,1,2,3,4,4}, K = 3;

    cout << "Result: " << sol.canDivideIntoSubsequences(nums, K) << endl;

    return 0;
}

