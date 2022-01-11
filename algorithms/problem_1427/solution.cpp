/*
Perform String Shifts

You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.

Example 1:
Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"

Example 2:
Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:  
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"

Constraints:
1 <= s.length <= 100
s only contains lower case English letters.
1 <= shift.length <= 100
shift[i].length == 2
0 <= shift[i][0] <= 1
0 <= shift[i][1] <= 100
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
    string stringShift(string s, vector<vector<int>>& shift) {
        int sz = s.size();
        if (sz == 0)
            return s;
        int sh = 0;
        for (auto& t: shift) {
            sh = (sh + (t[0] == 0 ? -t[1] : t[1])) % sz;
            if (sh < 0)
                sh += sz;
        }
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s) + sh);
        reverse(begin(s)+sh, end(s));

        return s;
    }
};

int main() {
    Solution sol;
    string s;
    vector<vector<int>> shift;

    // Output: "cab"
    s = "abc", shift = {{0,1},{1,2}};
    cout << sol.stringShift(s, shift) << endl;
    
    // Output: "efgabcd"
    s = "abcdefg", shift = {{1,1},{1,1},{0,2},{1,3}};
    cout << sol.stringShift(s, shift) << endl;
    
    return 0;
}
