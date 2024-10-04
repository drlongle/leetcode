/*
2491. Divide Players Into Teams of Equal Skill
Medium

You are given a positive integer array skill of even length n where skill[i]
denotes the skill of the ith player. Divide the players into n / 2 teams of size
2 such that the total skill of each team is equal.

The chemistry of a team is equal to the product of the skills of the players on
that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no
way to divide the players into teams such that the total skill of each team is
equal.

Example 1:
Input: skill = [3,2,5,1,3,4]
Output: 22
Explanation:
Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each
team has a total skill of 6. The sum of the chemistry of all the teams is: 1 * 5
+ 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.

Example 2:
Input: skill = [3,4]
Output: 12
Explanation:
The two players form a team with a total skill of 7.
The chemistry of the team is 3 * 4 = 12.

Example 3:
Input: skill = [1,1,2,3]
Output: -1
Explanation:
There is no way to divide the players into teams such that the total skill of
each team is equal.

Constraints:
2 <= skill.length <= 10^5
skill.length is even.
1 <= skill[i] <= 1000
*/

#include <algorithm>
#include <atomic>
#include <bit>
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
    long long dividePlayers(vector<int> &skill) {
        int sz = skill.size();
        long long sum = 0;
        unordered_map<int, int> lookup;
        for (auto s : skill) {
            ++lookup[s];
            sum += s;
        }
        long long res = 0;
        long long k = sum * 2 / sz;
        for (int i = 0, pairs = 0; i < sz && pairs < sz / 2; ++i) {
            auto s = skill[i];
            if (lookup[s] == 0)
                continue;
            int key = k - s;
            if (lookup[key] == 0)
                return -1;
            --lookup[s];
            --lookup[key];
            res += 1ll * s * key;
            ++pairs;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> skill;

    skill = {3, 2, 5, 1, 3, 4};
    cout << sol.dividePlayers(skill) << endl;

    skill = {3, 4};
    cout << sol.dividePlayers(skill) << endl;

    skill = {1, 1, 2, 3};
    cout << sol.dividePlayers(skill) << endl;

    skill = {5, 3, 7, 1};
    cout << sol.dividePlayers(skill) << endl;

    skill = {11, 11, 20, 6, 15, 11, 15, 15, 19, 7};
    cout << sol.dividePlayers(skill) << endl;

    return 0;
}
