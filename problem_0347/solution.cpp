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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int n: nums)
            ++cnt[n];
        auto lambda = [&] (int i, int j) {
                          return cnt[i] < cnt[j];
                      };
        multiset<int, decltype(lambda)> numbers(lambda);
        for (auto& [key, val]: cnt) {
            if (numbers.size() >= k) {
                auto it = numbers.begin();
                if (val > cnt[*it]) {
                    numbers.erase(it);
                    numbers.insert(key);
                }
            } else
                numbers.insert(key);
        }
        vector<int> res(begin(numbers), end(numbers));
        
        return res;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums, res;
    int k;

    nums = {1,1,1,2,2,3}, k = 2;
    res = sol.topKFrequent(nums, k);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    nums = {1,2}, k = 2;
    res = sol.topKFrequent(nums, k);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    return 0;
}
