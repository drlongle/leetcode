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

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1, sz = s.size();
        unordered_map<char, int> cnt;
        for (int i = 0; i < sz; ++i) {
            auto ch = s[i];
            auto [it, inserted] = cnt.emplace(ch, i);
            if (it != cnt.end()) {
                res = max(res, i - it->second - 1);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s;

    s = "aa";
    cout << sol.maxLengthBetweenEqualCharacters(s) << endl;

    s = "abca";
    cout << sol.maxLengthBetweenEqualCharacters(s) << endl;

    s = "cabbac";
    cout << sol.maxLengthBetweenEqualCharacters(s) << endl;

    s = "mgntdygtxrvxjnwksqhxuxtrv";
    cout << sol.maxLengthBetweenEqualCharacters(s) << endl;

    return 0;
}
