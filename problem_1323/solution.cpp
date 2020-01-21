/*
1323. Maximum 69 Number
Easy

Given a positive integer num consisting only of digits 6 and 9.
Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

Example 1:
Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666. 
The maximum number is 9969.

Example 2:
Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.

Example 3:
Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.

Constraints:
1 <= num <= 10^4
num's digits are 6 or 9.
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
    int maximum69Number (int num) {
        auto str = to_string(num);
        auto index = str.find('6', 0);
        if (index != string::npos)
            str[index] = '9';
        return stoi(str);
    }
};

int main() {
    Solution sol;
    int num;

    // Output: 9969
    num = 9669;

    // Output: 9999
    num = 9996;

    // Output: 9999
    num = 9999;

    // OutputÖ 969
    //num = 669;
    
    cout << "Result: " << sol.maximum69Number(num) << endl;
    return 0;
}
