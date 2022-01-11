/*
1125. Smallest Sufficient Team
Hard

In a project, you have a list of required skills req_skills, and a list of people.
The i-th person people[i] contains a list of skills that person has.

Consider a sufficient team: a set of people such that for every required skill in
req_skills, there is at least one person in the team who has that skill. We can
represent these teams by the index of each person: for example, team = [0, 1, 3]
represents the people with skills people[0], people[1], and people[3].

Return any sufficient team of the smallest possible size, represented by the index of each person.

You may return the answer in any order.  It is guaranteed an answer exists. 

Example 1:
Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]

Example 2:
Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <condition_variable>
#include <cmath>
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
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        size_t n = req_skills.size();

        // This cannot be unordered_map. This is because if insertion causes rehashing,
        // all iterators are invalidated.
        map<int, vector<int>> res;
        res[0] = {};

        unordered_map<string, int> skill_map;
        for (size_t i = 0; i < n; ++i)
            skill_map[req_skills[i]] = i;

        for (size_t i = 0; i < people.size(); ++i) {
            int cur_skill = 0;
            for (size_t j = 0; j < people[i].size(); ++j) {
                cur_skill |= (1 << skill_map[people[i][j]]);
            }

            for (auto it = res.begin(); it != res.end(); ++it) {
                int comb = it->first | cur_skill;
                if (res.count(comb) == 0 || res[comb].size() > res[it->first].size() + 1) {
                    res[comb] = it->second;
                    res[comb].emplace_back(i);
                }
            }
        }

        return res[(1 << n) - 1];
    }
};

int main() {
    Solution sol;
    vector<vector<string>> people;
    vector<string> req_skills;
    vector<int> res;

    req_skills = {"java","nodejs","reactjs"}, people = {{"java"},{"nodejs"},{"nodejs","reactjs"}};

    req_skills = {"algorithms","math","java","reactjs","csharp","aws"};
    people = {{"algorithms","math","java"},{"algorithms","math","reactjs"},{"java","csharp","aws"},{"reactjs","csharp"},{"csharp","math"},{"aws","java"}};

    res = sol.smallestSufficientTeam(req_skills, people);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));

    return 0;
}

