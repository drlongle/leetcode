/*
1566. Detect Pattern of Length M Repeated K or More Times
Easy

Given an array of positive integers arr, find a pattern of length m that is repeated k or more times.

A pattern is a subarray (consecutive sub-sequence) that consists of one or more values, repeated multiple times
consecutively without overlapping. A pattern is defined by its length and the number of repetitions.

Return true if there exists a pattern of length m that is repeated k or more times, otherwise return false.

Example 1:
Input: arr = [1,2,4,4,4,4], m = 1, k = 3
Output: true
Explanation: The pattern (4) of length 1 is repeated 4 consecutive times. Notice that pattern can be repeated k or more times but not less.

Example 2:
Input: arr = [1,2,1,2,1,1,1,3], m = 2, k = 2
Output: true
Explanation: The pattern (1,2) of length 2 is repeated 2 consecutive times. Another valid pattern (2,1) is also repeated 2 times.

Example 3:
Input: arr = [1,2,1,2,1,3], m = 2, k = 3
Output: false
Explanation: The pattern (1,2) is of length 2 but is repeated only 2 times. There is no pattern of length 2 that is repeated 3 or more times.

Example 4:
Input: arr = [1,2,3,1,2], m = 2, k = 2
Output: false
Explanation: Notice that the pattern (1,2) exists twice but not consecutively, so it doesn't count.

Example 5:
Input: arr = [2,2,2,2], m = 2, k = 3
Output: false
Explanation: The only pattern of length 2 is (2,2) however it's repeated only twice. Notice that we do not count overlapping repetitions.

Constraints:
2 <= arr.length <= 100
1 <= arr[i] <= 100
1 <= m <= 100
2 <= k <= 100
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
    bool containsPattern(vector<int>& arr, int m, int k) {
        ostringstream oss;
        for (int n: arr) {
            char ch = '0' + n;
            oss << ch;
        }

        unordered_map<string, vector<int>> lookup;
        string s = oss.str();
        int sz = s.size();
        for (int i = 0; i + m * k - 1 < sz; ++i) {
            string_view sv1(s.c_str() + i, m);
            bool match = true;
            for (int j = 1; match && j <= k - 1; ++j) {
                string_view sv2(s.c_str() + i + j * m, m);
                match = (sv1 == sv2);
            }
            if (match)
                return true;
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int m, k;

    // Output: true
    arr = {1,2,4,4,4,4}, m = 1, k = 3;
    cout << boolalpha << sol.containsPattern(arr, m, k) << endl;

    // Output: true
    arr = {1,2,1,2,1,1,1,3}, m = 2, k = 2;
    cout << boolalpha << sol.containsPattern(arr, m, k) << endl;

    // Output: false
    arr = {1,2,1,2,1,3}, m = 2, k = 3;
    cout << boolalpha << sol.containsPattern(arr, m, k) << endl;

    // Output: false
    arr = {1,2,3,1,2}, m = 2, k = 2;
    cout << boolalpha << sol.containsPattern(arr, m, k) << endl;

    // Output: false
    arr = {2,2,2,2}, m = 2, k = 3;
    cout << boolalpha << sol.containsPattern(arr, m, k) << endl;

    return 0;
}
