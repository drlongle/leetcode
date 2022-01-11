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

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        for(size_t i = 0; i < people.size(); ++i) {
            for (size_t j = 0; j < people[i].size(); ++j) {
                skill_map[people[i][j]].emplace(i);
            }
        }
        nr_req_skills = req_skills.size();
        find(req_skills, people, 0);
        vector<int> team;
        copy(begin(res), end(res), back_inserter(team));

        return team;
    }

    void find(vector<string>& req_skills, vector<vector<string>>& people, size_t skill_index) {
        if (skill_index == nr_req_skills) {
            if (team.size() < res.size() || res.empty())
                res = team;
        } else {
            if (!res.empty() && res.size() <= team.size())
                return;
            for (auto& person_id: skill_map[req_skills[skill_index]]) {
                auto t = team.emplace(person_id);
                find(req_skills, people, skill_index + 1);
                if (t.second)
                    team.erase(t.first);
            }
        }
    }

    map<string, unordered_set<int>> skill_map;
    unordered_set<int> team, res;
    size_t nr_req_skills;
};

int main() {
    Solution sol;
    vector<vector<string>> people;
    vector<string> req_skills;
    vector<int> res;

    req_skills = {"java","nodejs","reactjs"}, people = {{"java"},{"nodejs"},{"nodejs","reactjs"}};

    req_skills = {"algorithms","math","java","reactjs","csharp","aws"};
    people = {{"algorithms","math","java"},{"algorithms","math","reactjs"},{"java","csharp","aws"},{"reactjs","csharp"},{"csharp","math"},{"aws","java"}};

    req_skills = {"mli","krvswogyyanvwhd","jzuhxeqqvkuac","gmwyepsq","nfgilvs","zyqubsiify","pbmmtjcruigt"};
    people = {{"pbmmtjcruigt"},{"jzuhxeqqvkuac","zyqubsiify","pbmmtjcruigt"},{"krvswogyyanvwhd"},{},{"mli","krvswogyyanvwhd","pbmmtjcruigt"},{},{"mli","pbmmtjcruigt"},{},{"mli","pbmmtjcruigt"},{"pbmmtjcruigt"},{"krvswogyyanvwhd","gmwyepsq","nfgilvs"},{"mli"},{"krvswogyyanvwhd","jzuhxeqqvkuac","gmwyepsq"},{"jzuhxeqqvkuac","pbmmtjcruigt"},{},{},{},{"zyqubsiify"},{"krvswogyyanvwhd","pbmmtjcruigt"},{"krvswogyyanvwhd","jzuhxeqqvkuac","nfgilvs"},{},{"krvswogyyanvwhd"},{"zyqubsiify"},{"mli","krvswogyyanvwhd","jzuhxeqqvkuac"},{"pbmmtjcruigt"},{"pbmmtjcruigt"},{"zyqubsiify"},{"mli","nfgilvs"},{"mli","jzuhxeqqvkuac","zyqubsiify"},{"mli","pbmmtjcruigt"},{"mli"},{"mli","jzuhxeqqvkuac"},{"mli","jzuhxeqqvkuac","pbmmtjcruigt"},{"jzuhxeqqvkuac"},{"mli"},{"mli"},{"mli"},{},{"krvswogyyanvwhd","pbmmtjcruigt"},{},{"jzuhxeqqvkuac"},{},{"mli"},{"jzuhxeqqvkuac"},{"jzuhxeqqvkuac","zyqubsiify","pbmmtjcruigt"},{"mli","zyqubsiify"},{"mli"},{"mli","zyqubsiify"},{"krvswogyyanvwhd"},{},{"jzuhxeqqvkuac"},{},{"zyqubsiify"},{},{"krvswogyyanvwhd","gmwyepsq","zyqubsiify"},{"krvswogyyanvwhd","zyqubsiify"},{"krvswogyyanvwhd","pbmmtjcruigt"},{"mli"},{"mli","zyqubsiify"},{}};

    res = sol.smallestSufficientTeam(req_skills, people);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
}
