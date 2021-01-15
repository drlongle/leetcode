/*

*/

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
    unordered_map<string, unordered_set<string>> graph;
    unordered_set<string> visited;
    void DFS(const string& email, set<string>& emails) {
        if (!emails.emplace(email).second)
            return;
        visited.emplace(email);
        for (auto& nei: graph[email])
            DFS(nei, emails);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (auto& account: accounts) {
            for (int i = 1, n = account.size(); i < n; ++i) {
                graph[account[1]].emplace(account[i]);
                graph[account[i]].emplace(account[1]);
            }
        }

        vector<vector<string>> res;
        for (auto& account: accounts) {
            set<string> emails;
            for (int i = 1, n = account.size(); i < n; ++i) {
                if (visited.count(account[i]) == 0)
                    DFS(account[i], emails);
            }
            if (emails.size()) {
                res.emplace_back(vector<string>{account[0]});
                auto& r = res.back();
                for (auto& email: emails)
                    r.emplace_back(email);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> accounts;

    accounts = {
            {"John", "johnsmith@mail.com", "john00@mail.com"},
            {"John", "johnnybravo@mail.com"},
            {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
            {"Mary", "mary@mail.com"}};
    accounts = sol.accountsMerge(accounts);
    for (auto& account: accounts) {
        copy(begin(account), end(account), ostream_iterator<string>(cout, ", "));
        cout << endl;
    }


    return 0;
}
