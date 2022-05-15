/*
460. LFU Cache
Hard

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data
structure. int get(int key) Gets the value of the key if the key exists in the
cache. Otherwise, returns -1. void put(int key, int value) Update the value of
the key if present, or inserts the key if not already present. When the cache
reaches its capacity, it should invalidate and remove the least frequently used
key before inserting a new item. For this problem, when there is a tie (i.e.,
two or more keys with the same frequency), the least recently used key would be
invalidated. To determine the least frequently used key, a use counter is
maintained for each key in the cache. The key with the smallest use counter is
the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to
the put operation). The use counter for a key in the cache is incremented either
a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.



Example 1:
Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get",
"get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is
most recent) LFUCache lfu = new LFUCache(2); lfu.put(1, 1);   // cache=[1,_],
cnt(1)=1 lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1 lfu.get(1);      //
return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest,
invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3

Constraints:
0 <= capacity <= 10^4
0 <= key <= 10^5
0 <= value <= 10^9
At most 2 * 10^5 calls will be made to get and put.
*/

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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class LFUCache {
  public:
    struct Item {
        Item(int k, int v, int h, int u)
            : key(k), val(v), last_used(u), hits(h) {}
        int key;
        int val;
        int last_used;
        int hits;
        bool operator<(const Item &other) const {
            return hits < other.hits ||
                   (hits == other.hits && last_used < other.last_used);
        }
    };
    struct Ref {
        int last_used = 0;
        int hits = 0;
        multiset<Item>::iterator it;
    };

    LFUCache(int capacity) : maxsize(capacity) {}

    int get(int key) {
        auto &ref = lookup[key];
        if (ref.hits == 0)
            return -1;
        ref.hits++;
        ref.last_used = ts++;

        int val = (ref.it)->val;
        items.erase(ref.it);
        ref.it = items.emplace(key, val, ref.hits, ref.last_used);

        return val;
    }

    void put(int key, int value) {
        if (!maxsize)
            return;
        if (items.size() == maxsize) {
            auto it = items.begin();
            int k = it->key;
            const auto key_it = lookup.find(key);
            if (key_it == lookup.end() || key_it->second.hits == 0) {
                items.erase(it);
                lookup[k].it = items.end();
                lookup[k].hits = lookup[k].last_used = 0;
            }
        }
        auto &ref = lookup[key];
        if (ref.hits != 0)
            items.erase(ref.it);
        ref.hits++;
        ref.last_used = ts++;
        ref.it = items.emplace(key, value, ref.hits, ref.last_used);
    }

    unordered_map<int, Ref> lookup;
    multiset<Item> items;
    int ts = 0;
    size_t maxsize;
};

void test_1() {
    int val;
    LFUCache lfu = LFUCache(2);
    lfu.put(1, 1);    // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);    // cache=[2,1], cnt(2)=1, cnt(1)=1
    val = lfu.get(1); // return 1
    cout << val << ", expected: " << 1 << endl;
    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(
        3,
        3); // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
    // cache=[3,1], cnt(3)=1, cnt(1)=2
    val = lfu.get(2); // return -1 (not found)
    cout << val << ", expected: " << -1 << endl;
    val = lfu.get(3); // return 3
    cout << val << ", expected: " << 3 << endl;
    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4,
            4); // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
    // cache=[4,3], cnt(4)=1, cnt(3)=2
    val = lfu.get(1); // return -1 (not found)
    cout << val << ", expected: " << -1 << endl;
    val = lfu.get(3); // return 3
    cout << val << ", expected: " << 3 << endl;
    // cache=[3,4], cnt(4)=1, cnt(3)=3
    val = lfu.get(4); // return 4
    cout << val << ", expected: " << 4 << endl;
    // cache=[4,3], cnt(4)=2, cnt(3)=3
}

void test_2() {
    int val;
    LFUCache lfu = LFUCache(3);
    lfu.put(2, 2);
    lfu.put(1, 1);

    val = lfu.get(2);
    cout << val << ", expected: " << 2 << endl;

    val = lfu.get(1);
    cout << val << ", expected: " << 1 << endl;

    val = lfu.get(2);
    cout << val << ", expected: " << 2 << endl;
    lfu.put(3, 3);
    lfu.put(4, 4);

    val = lfu.get(3);
    cout << val << ", expected: " << -1 << endl;

    val = lfu.get(2);
    cout << val << ", expected: " << 2 << endl;

    val = lfu.get(1);
    cout << val << ", expected: " << 1 << endl;

    val = lfu.get(4);
    cout << val << ", expected: " << 4 << endl;
}

void test_3() {
    int val;
    LFUCache lfu = LFUCache(1);

    val = lfu.get(0);
    cout << val << ", expected: " << -1 << endl;
}

void test_4() {
    int val;
    LFUCache lfu = LFUCache(2);

    val = lfu.get(2);
    cout << val << ", expected: " << -1 << endl;
    lfu.put(2, 6);

    val = lfu.get(1);
    cout << val << ", expected: " << -1 << endl;
    lfu.put(1, 5);
    lfu.put(1, 2);
    val = lfu.get(1);
    cout << val << ", expected: " << 2 << endl;

    val = lfu.get(2);
    cout << val << ", expected: " << 6 << endl;
}

int main() {
    // test_1();
    // test_2();
    // test_3();
    test_4();
}
