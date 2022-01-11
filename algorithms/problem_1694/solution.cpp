/*
1694. Reformat Phone Number
Easy

You are given a phone number as a string number. number consists of digits, spaces ' ', and/or dashes '-'.

You would like to reformat the phone number in a certain manner. Firstly, remove all spaces and dashes. Then, group the digits from left to right into blocks of length 3 until there are 4 or fewer digits. The final digits are then grouped as follows:

2 digits: A single block of length 2.
3 digits: A single block of length 3.
4 digits: Two blocks of length 2 each.
The blocks are then joined by dashes. Notice that the reformatting process should never produce any blocks of length 1 and produce at most two blocks of length 2.

Return the phone number after formatting.

Example 1:
Input: number = "1-23-45 6"
Output: "123-456"
Explanation: The digits are "123456".
Step 1: There are more than 4 digits, so group the next 3 digits. The 1st block is "123".
Step 2: There are 3 digits remaining, so put them in a single block of length 3. The 2nd block is "456".
Joining the blocks gives "123-456".

Example 2:
Input: number = "123 4-567"
Output: "123-45-67"
Explanation: The digits are "1234567".
Step 1: There are more than 4 digits, so group the next 3 digits. The 1st block is "123".
Step 2: There are 4 digits left, so split them into two blocks of length 2. The blocks are "45" and "67".
Joining the blocks gives "123-45-67".

Example 3:
Input: number = "123 4-5678"
Output: "123-456-78"
Explanation: The digits are "12345678".
Step 1: The 1st block is "123".
Step 2: The 2nd block is "456".
Step 3: There are 2 digits left, so put them in a single block of length 2. The 3rd block is "78".
Joining the blocks gives "123-456-78".

Example 4:
Input: number = "12"
Output: "12"

Example 5:
Input: number = "--17-5 229 35-39475 "
Output: "175-229-353-94-75"

Constraints:
2 <= number.length <= 100
number consists of digits and the characters '-' and ' '.
There are at least two digits in number.
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
