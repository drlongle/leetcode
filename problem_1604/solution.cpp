/*
1604. Alert Using Same Key-Card Three or More Times in a One Hour Period
Medium

Leetcode company workers use key-cards to unlock office doors. Each time a worker uses their key-card, the security system saves the worker's name and the time when it was used. The system emits an alert if any worker uses the key-card three or more times in a one-hour period.

You are given a list of strings keyName and keyTime where [keyName[i], keyTime[i]] corresponds to a person's name and the time when their key-card was used in a single day.

Access times are given in the 24-hour time format "HH:MM", such as "23:51" and "09:49".

Return a list of unique worker names who received an alert for frequent keycard use. Sort the names in ascending order alphabetically.

Notice that "10:00" - "11:00" is considered to be within a one-hour period, while "23:51" - "00:10" is not considered to be within a one-hour period.

Example 1:
Input: keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"], keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
Output: ["daniel"]
Explanation: "daniel" used the keycard 3 times in a one-hour period ("10:00","10:40", "11:00").

Example 2:
Input: keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
Output: ["bob"]
Explanation: "bob" used the keycard 3 times in a one-hour period ("21:00","21:20", "21:30").

Example 3:
Input: keyName = ["john","john","john"], keyTime = ["23:58","23:59","00:01"]
Output: []

Example 4:
Input: keyName = ["leslie","leslie","leslie","clare","clare","clare","clare"], keyTime = ["13:00","13:20","14:00","18:00","18:51","19:30","19:49"]
Output: ["clare","leslie"]

Constraints:
1 <= keyName.length, keyTime.length <= 105
keyName.length == keyTime.length
keyTime are in the format "HH:MM".
[keyName[i], keyTime[i]] is unique.
1 <= keyName[i].length <= 10
keyName[i] contains only lowercase English letters.
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

using namespace std;

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<string>> cnt;
        int sz = keyName.size();
        for (int i = 0; i < sz; ++i) {
            cnt[keyName[i]].emplace_back(keyTime[i]);
        }

        vector<string> res;
        for (auto& [name, times]: cnt) {
            sort(times.begin(), times.end());
            int n = times.size();
            for (int i = 2; i < n; ++i) {
                int t2 = stoi(times[i].substr(0, 2));
                int t0 = stoi(times[i-2].substr(0, 2));
                if ((t2 == t0) || (t2 == t0 + 1 && times[i].substr(3, 2) <= times[i-2].substr(3, 2))) {
                    res.emplace_back(name);
                    break;
                }
            }
        }
        sort(begin(res), end(res));

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> keyName, keyTime, res;

    // Output: {"daniel"}
    keyName = {"daniel","daniel","daniel","luis","luis","luis","luis"}, keyTime = {"10:00","10:40","11:00","09:00","11:00","13:00","15:00"};
    res = sol.alertNames(keyName, keyTime);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // Output: {"bob"}
    keyName = {"alice","alice","alice","bob","bob","bob","bob"}, keyTime = {"12:01","12:00","18:00","21:00","21:20","21:30","23:00"};
    res = sol.alertNames(keyName, keyTime);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // Output: {}
    keyName = {"john","john","john"}, keyTime = {"23:58","23:59","00:01"};
    res = sol.alertNames(keyName, keyTime);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // Output: {"clare","leslie"}
    keyName = {"leslie","leslie","leslie","clare","clare","clare","clare"}, keyTime = {"13:00","13:20","14:00","18:00","18:51","19:30","19:49"};
    res = sol.alertNames(keyName, keyTime);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;
    
    return 0;
}
