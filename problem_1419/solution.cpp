/*
1419. Minimum Number of Frogs Croaking
Medium

Given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple “croak” are mixed. Return the minimum number of different frogs to finish all the croak in the given string.

A valid "croak" means a frog is printing 5 letters ‘c’, ’r’, ’o’, ’a’, ’k’ sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of valid "croak" return -1.


Example 1:
Input: croakOfFrogs = "croakcroak"
Output: 1 
Explanation: One frog yelling "croak" twice.

Example 2:
Input: croakOfFrogs = "crcoakroak"
Output: 2 
Explanation: The minimum number of frogs is two. 
The first frog could yell "crcoakroak".
The second frog could yell later "crcoakroak".

Example 3:
Input: croakOfFrogs = "croakcrook"
Output: -1
Explanation: The given string is an invalid combination of "croak" from different frogs.

Example 4:
Input: croakOfFrogs = "croakcroa"
Output: -1

Constraints:
1 <= croakOfFrogs.length <= 10^5
All characters in the string are: 'c', 'r', 'o', 'a' or 'k'.
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
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> lookup = {{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
        vector<int> stages(5, 0);
        for (char ch: croakOfFrogs) {
            int i = lookup[ch];
            if (i == 0) {
                if (stages[4] > 0)
                    --stages[4];
            } else {
                if (--stages[i-1] < 0)
                    return -1;
            }
            ++stages[i];
        }

        for (int i = 0; i < 4; ++i)
            if (stages[i] > 0)
                return -1;
        return stages[4];
    }
};

int main() {
    Solution sol;
    string croakOfFrogs;

    // Output: 1
    croakOfFrogs = "croakcroak";
    cout << sol.minNumberOfFrogs(croakOfFrogs) << endl;

    // Output: 2
    croakOfFrogs = "crcoakroak";
    cout << sol.minNumberOfFrogs(croakOfFrogs) << endl;
    
    // Output: -1
    croakOfFrogs = "croakcrook";
    cout << sol.minNumberOfFrogs(croakOfFrogs) << endl;
    
    // Output: -1
    croakOfFrogs = "croakcroa";
    cout << sol.minNumberOfFrogs(croakOfFrogs) << endl;
    
    return 0;
}
