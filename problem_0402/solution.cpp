/*
402. Remove K Digits
Difficulty: Medium

Given a non-negative integer num represented as a string, remove k digits from
the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219
which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"

Explanation: Remove the leading 1 and the number is 200. Note that the output
must not contain leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing
which is 0.
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
Main idea: delete the first digit where the next digit is smaller than it,
or the last digit if digits are in non-decending order.
*/
class Solution {
public:

    string removeKdigits(string num, int k) {
        if (num.size() == k)
            return "0";
        if (!k)
            return num;

        auto pos = num.find('0');
        if (pos != string::npos && pos <= k) {
            k -= pos;
            pos = num.find_first_not_of('0', pos);
            if (pos == string::npos)
                return "0";
            return removeKdigits(num.substr(pos), k);
        }

        string new_num;
        int i = 0, len = num.size();
        for (i = 0; i < len && k; ++i) {
            while (k && new_num.size() && new_num.back() > num[i]) {
                --k;
                new_num.pop_back();
            }
            if (!k)
                break;
            else
                new_num.push_back(num[i]);
        }
        if (i < len)
            new_num += num.substr(i);
        
        if (!k)
            return new_num;
        
        new_num.pop_back();

        return removeKdigits(new_num, k-1);
    }
};

int main(int argc, char** argv) {
    Solution sol;
    string num;
    int k;
    
    // Expected: "1219"
    num = "1432219", k = 3;
    
    // Expected: "200"
    //num = "10200", k = 1;
    
    // Expected: "0"
    //num = "10", k = 2;
    
    // Expected: "119"
    //num = "1919", k = 1;
    
    //num = "10";
    //k = 1;        
    
    num = "222222222222222222222210";
    k = 12;
    
    cout << "Result: " << sol.removeKdigits(num, k) << endl;
    
    return 0;
}
