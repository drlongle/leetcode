/*
1481. Least Number of Unique Integers after K Removals
Medium

Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

Example 1:
Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.

Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.

Constraints:
1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length
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
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        struct Num {
            Num(int n, int c): num(n), cnt(c) {}
            int num, cnt;
            bool operator<(const Num& other) const {return cnt < other.cnt;}
        };
        map<int, int> cnt;
        for (int a: arr) {
            ++cnt[a];
        }
        multiset<Num> nums;
        for (auto& [n, c]: cnt) {
            nums.emplace(n, c);
        }
        while (k > 0 && nums.size()) {
            auto it = nums.begin();
            Num num = *it;
            nums.erase(it);
            int sub = min(num.cnt, k);
            k -=sub;
            num.cnt -= sub;
            if (num.cnt > 0)
                nums.emplace(num);
        }
        return nums.size();
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int k;

    // Output: 1
    arr = {5,5,4}, k = 1;
    cout << sol.findLeastNumOfUniqueInts(arr, k) << endl;
    
    // Output: 2
    arr = {4,3,1,1,3,3,2}, k = 3;
    cout << sol.findLeastNumOfUniqueInts(arr, k) << endl;

    return 0;
}
