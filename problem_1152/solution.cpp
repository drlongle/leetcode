/*
1152. Analyze User Website Visit Pattern
Medium

You are given three arrays username, timestamp and website of the same length N where the ith
tuple means that the user with name username[i] visited the website website[i] at time
timestamp[i].

A 3-sequence is a list of not necessarily different websites of length 3 sorted in ascending
order by the time of their visits.

Find the 3-sequence visited at least once by the largest number of users. If there is more than
one solution, return the lexicographically minimum solution.

A 3-sequence X is lexicographically smaller than a 3-sequence Y if X[0] < Y[0] or X[0] == Y[0] and
(X[1] < Y[1] or X[1] == Y[1] and X[2] < Y[2]). 

It is guaranteed that there is at least one user who visited at least 3 websites. No user visits
two websites at the same time.

Example
Input:
username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"],
timestamp = [1,2,3,4,5,6,7,8,9,10],
website = ["home","about","career","home","cart","maps","home","home","about","career"]
Output: ["home","about","career"]
Explanation: 
The tuples in this example are:
["joe", 1, "home"]
["joe", 2, "about"]
["joe", 3, "career"]
["james", 4, "home"]
["james", 5, "cart"]
["james", 6, "maps"]
["james", 7, "home"]
["mary", 8, "home"]
["mary", 9, "about"]
["mary", 10, "career"]
The 3-sequence ("home", "about", "career") was visited at least once by 2 users.
The 3-sequence ("home", "cart", "maps") was visited at least once by 1 user.
The 3-sequence ("home", "cart", "home") was visited at least once by 1 user.
The 3-sequence ("home", "maps", "home") was visited at least once by 1 user.
The 3-sequence ("cart", "maps", "home") was visited at least once by 1 user.
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

auto compare = [] (const pair<int, string>& p1, const pair<int, string>& p2) {
    return p1.first < p2.first;
};

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<pair<int, string>>> visits;
        map<vector<string>, set<string>> seqs;
        
        for (int i = 0, size = username.size(); i < size; ++i) {
            auto& visit = visits[username[i]];
            visit.emplace_back(timestamp[i], website[i]);
        }
        
        vector<string> res;
        int max_count = 0;
        for (auto& p: visits) {
            auto& visit = p.second;
            sort(begin(visit), end(visit), compare);
            int vsize = visit.size();
            vector<string> seq;
            for (int i = 0; i < vsize; ++i) {
                seq.emplace_back(visit[i].second);
                for (int j = i+1; j < vsize; ++j) {
                    seq.emplace_back(visit[j].second);
                    for (int k = j+1; k < vsize; ++k) {
                        seq.emplace_back(visit[k].second);
                        seqs[seq].emplace(p.first);
                        int temp = seqs[seq].size();
                        if (temp > max_count || (temp == max_count && seq < res)) {
                            res = seq;
                            max_count = temp;
                        }
                        seq.pop_back();
                    }
                    seq.pop_back();
                }
                seq.pop_back();
            }
        }


        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> username, website, res;
    vector<int> timestamp;
    
    // Expected: ["home","about","career"]
    username = {"joe","joe","joe","james","james","james","james","mary","mary","mary"};
    timestamp = {1,2,3,4,5,6,7,8,9,10};
    website = {"home","about","career","home","cart","maps","home","home","about","career"};

    // Expected: ["a","b","a"]
    //username = {"u1","u1","u1","u2","u2","u2"};
    //timestamp = {1,2,3,4,5,6};
    //website = {"a","b","c","a","b","a"};

    // 35 / 61 test cases passed.
    // Expected: ["hibympufi","hibympufi","yljmntrclw"]
    //username = {"h","eiy","cq","h","cq","txldsscx","cq","txldsscx","h","cq","cq"};
    //timestamp = {527896567,334462937,517687281,134127993,859112386,159548699,51100299,444082139,926837079,317455832,411747930};
    //website = {"hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","yljmntrclw","hibympufi","yljmntrclw"};
    
    res = sol.mostVisitedPattern(username, timestamp, website);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    
    return 0;
}

