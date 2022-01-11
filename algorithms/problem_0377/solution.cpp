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
    vector<int> dp;

    int compute(vector<int>& nums, int target) {
        int& res = dp[target];
        if (res >= 0)
            return res;
        res = 0;
        for (int num: nums) {
            int diff = target - num;
            if (diff >= 0)
                res += compute(nums, diff);
        }
        return res;
    }

    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1, -1);
        dp[0] = 1;
        return compute(nums, target);
    }
};

int main() {
    Solution sol;

    return 0;
}
