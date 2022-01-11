/*
1363. Largest Multiple of Three
Hard

Given an integer array of digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order.

Since the answer may not fit in an integer data type, return the answer as a string.

If there is no answer return an empty string.

Example 1:
Input: digits = [8,1,9]
Output: "981"

Example 2:
Input: digits = [8,6,7,1,0]
Output: "8760"

Example 3:
Input: digits = [1]
Output: ""

Example 4:
Input: digits = [0,0,0,0,0,0]
Output: "0"

Constraints:
1 <= digits.length <= 10^4
0 <= digits[i] <= 9
The returning answer must not contain unnecessary leading zeros.
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
    string largestMultipleOfThree(vector<int>& digits) {
        vector<vector<int>> candidates(2);
        string result;

        for (int d: digits) {
            int res = d % 3;
            switch (res) {
                case 0:
                    result += ('0' + d);
                    break;
                default:
                    candidates[res - 1].push_back(d);
            }
        }

        for (auto& cand: candidates)
            sort(begin(cand), end(cand), greater<int>());

        int n = min(candidates[0].size(), candidates[1].size());
        int diff_size = abs((int) candidates[0].size() - (int) candidates[1].size());
        if (diff_size % 3 == 2 && n > 0)
            --n;

        for (int i = 0; i < n; ++i) {
            result += ('0' + candidates[0][i]);
            result += ('0' + candidates[1][i]);
        } 

        for (auto& cand: candidates) {
            for (size_t i = n; i + 2 < cand.size(); i+=3) {
                result += ('0' + cand[i]);
                result += ('0' + cand[i+1]);
                result += ('0' + cand[i+2]);
            }
        }
                
        sort(begin(result), end(result), greater<char>());

        if (!result.empty()) {
            size_t index = result.find_first_not_of("0");
            if (index != string::npos)
                result = result.substr(index);
            else
                result = "0";
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> digits;
    
    // Output: "981"
    digits = {8,1,9};

    // Output: "8760"
    //digits = {8,6,7,1,0};

    // Output: ""
    //digits = {1};

    // Output: "0"
    //digits = {0,0,0,0,0,0};

    // Output: "876210"
    //digits = {2,8,6,1,7,0};

    // Output: 111
    //digits = {1,1,1};

    // Output: 111
    //digits = {1,1,1,2};

    cout << sol.largestMultipleOfThree(digits) << endl;
    
    return 0;
}
