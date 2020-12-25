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
    string reformatNumber(string number) {
        ostringstream oss;
        for (char ch: number)
            if (isdigit(ch)) {
                oss << ch;
            }
        string s = oss.str();
        int n = s.size();
        oss.str("");
        int i = 0;
        for (; n - i > 4; i += 3) {
            oss << s.substr(i, 3);
            oss << "-";
        }
        if (n -i == 4) {
            oss << s.substr(i, 2);
            oss << "-";
            oss << s.substr(i + 2);
        } else
            oss << s.substr(i);

        return oss.str();
    }
};

int main() {
    Solution sol;

    string s;
    s = "1-23-45 6";
    cout << sol.reformatNumber(s) << endl;

    s = "123 4-567";
    cout << sol.reformatNumber(s) << endl;

    return 0;
}
