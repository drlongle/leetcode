/*
434. Number of Segments in a String
Easy

Count the number of segments in a string, where a segment is defined to be a contiguous
sequence of non-space characters. Please note that the string does not contain any
non-printable characters.

Example:
Input: "Hello, my name is John"
Output: 5
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
    int countSegments(string s) {
        int count = 0, len = s.size();
        for (int i = 0; i < len; ++i) {
            if (s[i] != ' ' && (i == 0 || s[i-1] == ' '))
                ++count;
        }
        return count;
    }
};

int main() {
    Solution sol;
    string s;

    s = "Hello, my name is John";
    cout << "Result: " << sol.countSegments(s) << endl;
    
    return 0;
}
