#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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

class MaxStack {
public:
    stack<int> nums, max_nums;

    void push(int x) {
        nums.push(x);
        max_nums.push(max(x, (max_nums.size() ? max_nums.top() : INT_MIN)));
    }

    int pop() {
        int n = nums.top();
        max_nums.pop();
        nums.pop();
        return n;
    }

    int top() {
        return nums.top();
    }

    int peekMax() {
        return max_nums.top();
    }

    int popMax() {
        stack<int> temp;
        while (nums.top() < max_nums.top()) {
            temp.push(nums.top());
            nums.pop();
            max_nums.pop();
        }
        int n = nums.top();
        nums.pop();
        max_nums.pop();
        while (temp.size()) {
            int t = temp.top();
            temp.pop();
            push(t);
        }
        return n;
    }
};

int main() {
    return 0;
}
