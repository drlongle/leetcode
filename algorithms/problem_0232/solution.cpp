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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class MyQueue {
  public:
    stack<int> s, t;

    void push(int x) {
        while (!t.empty()) {
            s.push(t.top());
            t.pop();
        }
        s.push(x);
    }

    int pop() {
        while (!s.empty()) {
            t.push(s.top());
            s.pop();
        }
        int res = t.top();
        t.pop();
        return res;
    }

    int peek() {
        while (!s.empty()) {
            t.push(s.top());
            s.pop();
        }
        return t.top();
    }

    bool empty() { return s.empty() && t.empty(); }
};

void test() {
    MyQueue *obj = new MyQueue();
    obj->push(12);
    obj->peek();
    obj->pop();
    obj->empty();
}

int main() {
    test();
    return 0;
}
