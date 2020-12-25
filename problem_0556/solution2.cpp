
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> nums;
        while (n) {
            nums.push_back(n % 10);
            n /= 10;
        }
        if (nums.empty())
            return 0;
        reverse(begin(nums), end(nums));
        if (!next_permutation(begin(nums), end(nums)))
            return -1;
        long long res = 0;
        for (int i = 0, sz = nums.size(); i < sz && res <= numeric_limits<int>::max(); ++i)
            res = res*10 + nums[i];
        return res <= numeric_limits<int>::max() ? res : -1;
    }
};

int main() {
    Solution sol;
    int n;

    n = 12;
    cout << sol.nextGreaterElement(n) << endl;

    n = 21;
    cout << sol.nextGreaterElement(n) << endl;

    return 0;
}
