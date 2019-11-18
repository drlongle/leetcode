/*
1257. Smallest Common Region
Medium

You are given some lists of regions where the first region of each list includes all other
regions n that list. Naturally, if a region X contains another region Y then X is bigger than Y.
Given two regions region1, region2, find out the smallest region that contains both of them.

If you are given regions r1, r2 and r3 such that r1 includes r3, it is guaranteed there is no r2
such that r2 includes r3. It's guaranteed the smallest region exists. Note: This means that each
region only has a parent region.

Example 1:
Input:
regions = [["Earth","North America","South America"],
["North America","United States","Canada"],
["United States","New York","Boston"],
["Canada","Ontario","Quebec"],
["South America","Brazil"]],
region1 = "Quebec",
region2 = "New York"
Output: "North America"
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:

    vector<string> get_path(const string& region) {
        vector<string> res;
        string r = region;
        while (true) {
            res.emplace_back(r);
            auto it = graph.find(r);
            if (it == end(graph))
                break;
            r = it->second;
        }
        return res;
    }
    
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        string res;

        for (auto& list: regions) {
            int sz = list.size();
            string& parent = list[0];
            for (int i = 1; i < sz; ++i)
                graph[list[i]] = parent;
        }

        auto path1 = get_path(region1);
        auto path2 = get_path(region2);
        int i1 = path1.size()-1, i2 = path2.size()-1;
        while (i1 >= 0 && i2 >= 0) {
            if (path1[i1] != path2[i2])
                break;
            --i1, --i2;
        }
        return path1[i1+1];
    }
    
    map<string, string> graph;
};

int main() {
    Solution sol;
    vector<vector<string>> regions;
    string region1, region2;
    
    // Output: "North America"
    regions = {{"Earth","North America","South America"},
               {"North America","United States","Canada"},
               {"United States","New York","Boston"},
               {"Canada","Ontario","Quebec"},
               {"South America","Brazil"}};
    region1 = "Quebec";
    region2 = "New York";

    cout << "Result: " << sol.findSmallestRegion(regions, region1, region2) << endl;
    
    return 0;
}
