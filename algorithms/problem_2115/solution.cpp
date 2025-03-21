/*
2115. Find All Possible Recipes from Given Supplies
Medium

You have information about n different recipes. You are given a string array
recipes and a 2D string array ingredients. The ith recipe has the name
recipes[i], and you can create it if you have all the needed ingredients from
ingredients[i]. A recipe can also be an ingredient for other recipes, i.e.,
ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that
you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer
in any order.

Note that two recipes may contain each other in their ingredients.

Example 1:
Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies =
["yeast","flour","corn"] Output: ["bread"] Explanation: We can create "bread"
since we have the ingredients "yeast" and "flour".

Example 2:
Input: recipes = ["bread","sandwich"], ingredients =
[["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the
ingredient "bread".

Example 3:
Input: recipes = ["bread","sandwich","burger"], ingredients =
[["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies =
["yeast","flour","meat"] Output: ["bread","sandwich","burger"] Explanation: We
can create "bread" since we have the ingredients "yeast" and "flour". We can
create "sandwich" since we have the ingredient "meat" and can create the
ingredient "bread". We can create "burger" since we have the ingredient "meat"
and can create the ingredients "bread" and "sandwich".

Constraints:
n == recipes.length == ingredients.length
1 <= n <= 100
1 <= ingredients[i].length, supplies.length <= 100
1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English
letters. All the values of recipes and supplies combined are unique. Each
ingredients[i] does not contain any duplicate values.
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
    vector<string> findAllRecipes(vector<string> &recipes,
                                  vector<vector<string>> &ingredients,
                                  vector<string> &supplies) {

        set<string> supps(supplies.begin(), supplies.end());
        map<string, int> missing;
        map<string, set<string>> depends;
        for (int i = 0, sz = recipes.size(); i < sz; ++i) {
            std::vector<string> diff;
            for (auto &ing : ingredients[i]) {
                if (supps.count(ing) == 0)
                    diff.emplace_back(ing);
            }

            auto &r = recipes[i];

            for (auto &s : diff)
                depends[s].insert(r);

            missing[r] = diff.size();
        }

        vector<string> res;
        queue<string> q;

        for (auto &[k, v] : missing) {
            if (v == 0) {
                q.emplace(k);
            }
        }

        while (!q.empty()) {
            auto &s = q.front();
            res.emplace_back(s);
            for (auto &d : depends[s]) {
                --missing[d];
                if (missing[d] == 0)
                    q.emplace(d);
            }
            q.pop();
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> recipes;
    vector<vector<string>> ingredients;
    vector<string> result, supplies;

    // Output: ["bread"]
    recipes = {"bread"}, ingredients = {{"yeast", "flour"}},
    supplies = {"yeast", "flour", "corn"};
    result = sol.findAllRecipes(recipes, ingredients, supplies);
    copy(begin(result), end(result), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // Output: ["bread","sandwich"]
    recipes = {"bread", "sandwich"},
    ingredients = {{"yeast", "flour"}, {"bread", "meat"}},
    supplies = {"yeast", "flour", "meat"};
    result = sol.findAllRecipes(recipes, ingredients, supplies);
    copy(begin(result), end(result), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // Output: ["bread","sandwich","burger"]
    recipes = {"bread", "sandwich", "burger"},
    ingredients = {{"yeast", "flour"},
                   {"bread", "meat"},
                   {"sandwich", "meat", "bread"}},
    supplies = {"yeast", "flour", "meat"};
    result = sol.findAllRecipes(recipes, ingredients, supplies);
    copy(begin(result), end(result), ostream_iterator<string>(cout, ", "));
    cout << endl;

    return 0;
}
