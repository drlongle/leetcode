/*
860. Lemonade Change
Easy

At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and
order one at a time (in the order specified by bills). Each customer will only buy one lemonade and
pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that
the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you
can provide every customer with the correct change, or false otherwise.

Example 1:
Input: bills = [5,5,5,10,20]
Output: true
Explanation:
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.

Example 2:
Input: bills = [5,5,10,10,20]
Output: false
Explanation:
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, we collect a $10 bill and give back a $5 bill.
For the last customer, we can not give the change of $15 back because we only have two $10 bills.
Since not every customer received the correct change, the answer is false.

Constraints:
1 <= bills.length <= 10^5
bills[i] is either 5, 10, or 20.
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

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> table;
        for (auto bill: bills) {
            int payback = bill - 5;
            if (payback > 0) {
                auto it = table.lower_bound(payback);
                while (payback > 0) {
                    if (it == table.end() || it->first > payback || it->second == 0) {
                        if (it == table.begin())
                            return false;
                        --it;
                    }
                    if (it->second > 0) {
                        --(it->second);
                        payback -= it->first;
                    }
                }
            }
            ++table[bill];
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<int> bills;

    bills = {5,5,5,10,20};
    std::cout << std::boolalpha << sol.lemonadeChange(bills) << std::endl;

    bills = {5,5,10,10,20};
    std::cout << std::boolalpha << sol.lemonadeChange(bills) << std::endl;
}
