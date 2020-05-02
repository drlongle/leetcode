/*
1432. Max Difference You Can Get From Changing an Integer
Medium

You are given an integer num. You will apply the following steps exactly two times:

Pick a digit x (0 <= x <= 9).
Pick another digit y (0 <= y <= 9). The digit y can be equal to x.
Replace all the occurrences of x in the decimal representation of num by y.
The new integer cannot have any leading zeros, also the new integer cannot be 0.
Let a and b be the results of applying the operations to num the first and second times, respectively.

Return the max difference between a and b.

Example 1:
Input: num = 555
Output: 888
Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
The second time pick x = 5 and y = 1 and store the new integer in b.
We have now a = 999 and b = 111 and max difference = 888

Example 2:
Input: num = 9
Output: 8
Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
The second time pick x = 9 and y = 1 and store the new integer in b.
We have now a = 9 and b = 1 and max difference = 8

Example 3:
Input: num = 123456
Output: 820000

Example 4:
Input: num = 10000
Output: 80000

Example 5:
Input: num = 9288
Output: 8700

Constraints:
1 <= num <= 10^8
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int maxDiff(int num) {
        string sa = to_string(num);
        string sb(sa);
        int sz = sa.size();
        for (int i = 0; i < sz; ++i) {
            char ch = sa[i];
            if (ch != '9') {
                replace(sa.begin(), sa.end(), ch, '9');
                break;
            }
        }
        int a = stoi(sa);

        bool lead_one = (sb[0] == '1');
        for (int i = 0; i < sz; ++i) {
            char ch = sb[i];
            if (i == 0 && ch != '1') {
                replace(sb.begin(), sb.end(), ch, '1');
                break;
            }
            if (i > 0 && ch != '0' && (!lead_one || ch != '1')) {
                replace(sb.begin(), sb.end(), ch, '0');
                break;
            }
        }
        int b = stoi(sb);
        
        return a - b;
    }
};

int main() {
    Solution sol;
    int num;

    // Output: 888
    num = 555;
    cout << sol.maxDiff(num) << endl;
  
    // Output: 8
    num = 9;
    cout << sol.maxDiff(num) << endl;

    // Output: 820000
    num = 123456;
    cout << sol.maxDiff(num) << endl;
  
    // Output: 80000
    num = 10000;
    cout << sol.maxDiff(num) << endl;
  
    // Output: 8700
    num = 9288;
    cout << sol.maxDiff(num) << endl;

    // Expected: 
    num = 1101057;
    cout << sol.maxDiff(num) << endl;
    
    return 0;
}
