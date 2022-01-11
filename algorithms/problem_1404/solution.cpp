/*
1404. Number of Steps to Reduce a Number in Binary Representation to One
Medium

Given a number s in their binary representation. Return the number of steps to reduce it to 1 under the following rules:
* If the current number is even, you have to divide it by 2.
* If the current number is odd, you have to add 1 to it.

It's guaranteed that you can always reach to one for all testcases.

Example 1:
Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1.  

Example 2:
Input: s = "10"
Output: 1
Explanation: "10" corressponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.  

Example 3:
Input: s = "1"
Output: 0

Constraints:
1 <= s.length <= 500
s consists of characters '0' or '1'
s[0] == '1'
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
    string increment(string& s) {
        int carry = 1;
        for (int index = s.size() - 1; carry && index >= 0; --index) {
            if (++s[index] == '2')
                s[index] = '0';
            else
                carry = 0;
        }
        if (carry)
            s.insert(0, 1, '1');

        return s;
    }
    
    int numSteps(string s) {
        int cnt = 0;
        while (s != "1") {
            if (s.back() == '0')
                s = s.substr(0, s.size()-1);
            else {
                s = increment(s);
            }
            ++cnt;
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: 6
    s = "1101";
    cout << sol.numSteps(s) << endl;
    
    // Output: 1
    s = "10";
    cout << sol.numSteps(s) << endl;

    s = "1";
    cout << sol.numSteps(s) << endl;
    
    return 0;
}
