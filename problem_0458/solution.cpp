/*
458. Poor Pigs
Hard

There are 1000 buckets, one and only one of them is poisonous, while the rest are filled with water.
They all look identical. If a pig drinks the poison it will die within 15 minutes. What is the minimum
amount of pigs you need to figure out which bucket is poisonous within one hour?

Answer this question, and write an algorithm for the general case.

General case:

If there are n buckets and a pig drinking poison will die within m minutes, how many pigs (x) you need
to figure out the poisonous bucket within p minutes? There is exactly one bucket with poison.

Note:

A pig can be allowed to drink simultaneously on as many buckets as one would like, and the feeding takes no time.
After a pig has instantly finished drinking buckets, there has to be a cool down time of m minutes. During this
time, only observation is allowed and no feedings at all. Any given bucket can be sampled an infinite number
of times (by an unlimited number of pigs).
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
Say there are k drinking rounds. Fix a bucket b. For each pig i, assign it to drink from b in the round
b[i] where b[i] ∈ { 0, 1, 2, ... k }; and b[i] = 0 means that pig i never drinks from bucket b.

Suppose we have x pigs. Again for bucket b, consider its set S[b] of assignments for all x pigs;
that is, S[b] = { b[1], b[2], ..., b[x] }.

For each bucket b, this set has cardinality |S[b]| = (k + 1)^x.

Now if the S[b] sets are unique across all n buckets, then the poison bucket is the unique bucket for
which all assigned pigs die. (Or if no pigs die, the unique bucket for which S[b] = { 0, 0, ..., 0 }.)
So we must choose x large enough for the S[b] to be unique across all n buckets; that is, we must
have |S[b]| = (k + 1)^x ≥ n, which is true iff x ≥ log(n) / log(k + 1).
*/

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
    }
};

int main() {
    Solution sol;
    int buckets, minutesToDie, minutesToTest;

    // Output: 2
    // pigs: [1,2], [2,3]
    buckets = 3, minutesToDie = 1, minutesToTest = 1;
    cout << sol.poorPigs(buckets, minutesToDie, minutesToTest) << endl;

    // pigs: [1,2], [1,4]
    // 1 -> 2 pigs die
    // 2: first pig dies
    // 3: no pig dies
    // 4: second pig dies
    // Output: 2
    buckets = 4, minutesToDie = 1, minutesToTest = 1;
    cout << sol.poorPigs(buckets, minutesToDie, minutesToTest) << endl;

    // Output: 3
    buckets = 5, minutesToDie = 1, minutesToTest = 1;
    cout << sol.poorPigs(buckets, minutesToDie, minutesToTest) << endl;

    // Output: 3
    buckets = 8, minutesToDie = 1, minutesToTest = 1;
    cout << sol.poorPigs(buckets, minutesToDie, minutesToTest) << endl;

    // Output: 4
    buckets = 9, minutesToDie = 1, minutesToTest = 1;
    cout << sol.poorPigs(buckets, minutesToDie, minutesToTest) << endl;

    // Output: 4
    buckets = 10, minutesToDie = 1, minutesToTest = 1;
    cout << sol.poorPigs(buckets, minutesToDie, minutesToTest) << endl;

    // Output: 3
    buckets = 10, minutesToDie = 1, minutesToTest = 2;
    cout << sol.poorPigs(buckets, minutesToDie, minutesToTest) << endl;

    // Output: 5
    buckets = 1000, minutesToDie = 15, minutesToTest = 60;
    cout << sol.poorPigs(buckets, minutesToDie, minutesToTest) << endl;

    // Output: 4
    buckets = 1000, minutesToDie = 15, minutesToTest = 90;
    cout << sol.poorPigs(buckets, minutesToDie, minutesToTest) << endl;

    return 0;
}
