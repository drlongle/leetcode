/*
857. Minimum Cost to Hire K Workers
Hard

There are N workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].

Now we want to hire exactly K workers to form a paid group.  When hiring a group of K workers, we must pay them according to the following rules:

Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
Every worker in the paid group must be paid at least their minimum wage expectation.
Return the least amount of money needed to form a paid group satisfying the above conditions.

Example 1:
Input: quality = [10,20,5], wage = [70,50,30], K = 2
Output: 105.00000
Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.

Example 2:
Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
Output: 30.66667
Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately. 

Note:
1 <= K <= N <= 10000, where N = quality.length = wage.length
1 <= quality[i] <= 10000
1 <= wage[i] <= 10000
Answers within 10^-5 of the correct answer will be considered correct.
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
#include <memory>
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
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        auto wage_comp = [&] (int id1, int id2) {return (double) wage[id1] / quality[id1] < (double) wage[id2] / quality[id2];};
        auto qual_comp = [&] (int id1, int id2) {return quality[id1] > quality[id2];};
        multiset<int, decltype(qual_comp)> workers(qual_comp);
        multiset<int, decltype(std::not_fn(wage_comp))> wages(std::not_fn(wage_comp));
        
        vector<int> ids(quality.size());
        iota(begin(ids), end(ids), 0);
        sort(begin(ids), end(ids), wage_comp);
        double res = numeric_limits<double>::max(), last_res = -1.0, new_res;
        int max_id = -1, last_max_id = -1;
        for (auto id: ids) {
            workers.emplace(id);
            wages.emplace(id);
            if (max_id < 0)
                max_id = id;
            else {
                if ((double) wage[id] / quality[id] > (double) wage[max_id] / quality[max_id])
                    max_id = id;
            }

            if (static_cast<int>(workers.size()) >= K) {
                int removed_id = -1;
                if (static_cast<int>(workers.size()) > K) {
                    auto it = workers.begin();
                    removed_id = *it;
                    workers.erase(it);
                    wages.erase(removed_id);
                    max_id = *(wages.begin());
                }
                if (last_res < 0) {
                    new_res = accumulate(begin(workers), end(workers), 0.0,
                                         [&] (double sum, int wid) {return sum + static_cast<double>(wage[max_id]) * quality[wid] / quality[max_id];});
                } else {
                    if (removed_id >= 0)
                        last_res -= static_cast<double>(wage[last_max_id]) * quality[removed_id] / quality[last_max_id];
                    if (last_max_id != max_id) {
                        last_res /= (double) wage[last_max_id] / quality[last_max_id];
                        last_res *= (double) wage[max_id] / quality[max_id];
                    }
                    new_res = last_res + static_cast<double>(wage[max_id]) * quality[id] / quality[max_id];
                }
                last_max_id = max_id;
                res = min(res, new_res);
                last_res = new_res;
            }
        }
        

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> quality, wage;
    int K;

    // Output: 105.00000
    quality = {10,20,5}, wage = {70,50,30}, K = 2;
    cout << sol.mincostToHireWorkers(quality, wage, K) << endl;
    
    // Output: 30.66667
    quality = {3,1,10,10,1}, wage = {4,8,2,2,7}, K = 3;
    cout << sol.mincostToHireWorkers(quality, wage, K) << endl;

    // Expected: 3.0
    quality = {5,4,1,3}, wage = {4,3,14,9}, K = 1;
    cout << sol.mincostToHireWorkers(quality, wage, K) << endl;
    
    // Expected: 399.53846
    quality = {14,56,59,89,39,26,86,76,3,36};
    wage = {90,217,301,202,294,445,473,245,415,487};
    K = 2;
    cout << sol.mincostToHireWorkers(quality, wage, K) << endl;

    // Expected: 25.2
    quality = {4,5}, wage = {8,14}, K = 2;
    cout << sol.mincostToHireWorkers(quality, wage, K) << endl;

    // Expected: 42.0
    quality = {5,5,5,1}, wage = {14,5,7,5}, K = 3;
    cout << sol.mincostToHireWorkers(quality, wage, K) << endl;

    // Expected: 348.0
    quality = {39,79,78,16,6,36,97,79,27,14,31,4,36,2,61,30,74,35,65,31};
    wage = {213,456,71,53,110,376,403,273,358,457,47,427,123,316,140,60,213,48,269,132};
    K = 4;
    cout << sol.mincostToHireWorkers(quality, wage, K) << endl;
    
    return 0;
}
