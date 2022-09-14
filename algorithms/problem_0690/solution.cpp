/*
690. Employee Importance
Medium

You have a data structure of employee information, including the employee's
unique ID, importance value, and direct subordinates' IDs.

You are given an array of employees employees where:

employees[i].id is the ID of the ith employee.
employees[i].importance is the importance value of the ith employee.
employees[i].subordinates is a list of the IDs of the direct subordinates of the
ith employee. Given an integer id that represents an employee's ID, return the
total importance value of this employee and all their direct and indirect
subordinates.

Example 1:
Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
Output: 11
Explanation: Employee 1 has an importance value of 5 and has two direct
subordinates: employee 2 and employee 3. They both have an importance value
of 3. Thus, the total importance value of employee 1 is 5 + 3 + 3 = 11.

Example 2:
Input: employees = [[1,2,[5]],[5,-3,[]]], id = 5
Output: -3
Explanation: Employee 5 has an importance value of -3 and has no direct
subordinates. Thus, the total importance value of employee 5 is -3.

Constraints:
1 <= employees.length <= 2000
1 <= employees[i].id <= 2000
All employees[i].id are unique.
-100 <= employees[i].importance <= 100
One employee has at most one direct leader and may have several subordinates.
The IDs in employees[i].subordinates are valid IDs.
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

#include "common/FenwickTree.h"
#include "common/ListNode.h"
#include "common/Node.h"
#include "common/SegmentTree.h"
#include "common/TreeNode.h"
#include "common/UnionFind.h"
#include "common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Employee {
  public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
  public:
    unordered_map<int, int> lookup;
    int getImportance(vector<Employee *> employees, int id) {
        for (int i = 0, sz = employees.size(); i < sz; ++i) {
            lookup[employees[i]->id] = i;
        }

        return get(employees, id);
    }

    int get(vector<Employee *> employees, int id) {
        auto index = lookup[id];
        auto emp = employees[index];
        auto res{emp->importance};
        for (auto i : emp->subordinates) {
            res += get(employees, i);
        }
        return res;
    }
};

int main() {}
