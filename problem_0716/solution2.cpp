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
    list<int> nums;
    map<int, vector<list<int>::iterator>, greater<int>> lookup;

    void push(int x) {
        auto it = nums.insert(nums.end(), x);
        lookup[x].emplace_back(it);
    }

    int pop() {
        int n = nums.back();
        nums.pop_back();

        auto it = lookup.find(n);
        it->second.pop_back();
        if (it->second.empty())
            lookup.erase(it);

        return n;
    }

    int top() {
        return nums.back();
    }

    int peekMax() {
        return lookup.begin()->first;
    }

    int popMax() {
        auto it1 = lookup.begin();
        int n = it1->first;
        auto it2 = it1->second.back();
        nums.erase(it2);
        it1->second.pop_back();
        if (it1->second.empty())
            lookup.erase(it1);

        return n;
    }
};

int main() {
    return 0;
}
