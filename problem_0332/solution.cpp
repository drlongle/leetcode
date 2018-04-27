/*
332. Reconstruct Itinerary

Difficulty:Medium
Total Accepted:48.1K
Total Submissions:160.7K

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
*/

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    bool explore(unordered_map<string, multimap<string, bool>>& flights,
        vector<string>& res, size_t count) {
        if (res.size() == count)
            return true;
        string& hop = res.back();
        for (auto& p: flights[hop]) {
            if (!p.second) {
                p.second = true;
                res.emplace_back(p.first);
                if (explore(flights, res, count))
                    return true;
                p.second = false;
                res.pop_back();
            }
        }

        return false;
    }

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        unordered_map<string, multimap<string, bool>> flights;
        for (const auto& ti: tickets)
            flights[ti.first].emplace(ti.second, false);
        res.emplace_back("JFK");
        explore(flights, res, tickets.size()+1);

        return res;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    vector<pair<string, string>> tickets;
    vector<string> res;

    // ["JFK", "MUC", "LHR", "SFO", "SJC"]
    tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};

    // ["JFK","ATL","JFK","SFO","ATL","SFO"]
    tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};

    // ["JFK","NRT","JFK","KUL"]
    tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};

    // ["JFK","ANU","EZE","AXA","TIA","ANU","JFK","TIA","ANU","TIA","JFK"]
    tickets = {{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}};

    res = sol.findItinerary(tickets);
    copy(res.begin(), res.end(), ostream_iterator<string>(cout, ", "));

    return 0;
}

