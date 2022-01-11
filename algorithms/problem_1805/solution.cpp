/*
1805. Number of Different Integers in a String
Easy

You are given a string word that consists of digits and lowercase English letters.

You will replace every non-digit character with a space. For example, "a123bc34d8ef34" will
become " 123  34 8  34". Notice that you are left with some integers that are separated by at
least one space: "123", "34", "8", and "34".

Return the number of different integers after performing the replacement operations on word.

Two integers are considered different if their decimal representations without any leading zeros are different.

Example 1:
Input: word = "a123bc34d8ef34"
Output: 3
Explanation: The three different integers are "123", "34", and "8". Notice that "34" is only counted once.

Example 2:
Input: word = "leet1234code234"
Output: 2

Example 3:
Input: word = "a1b01c001"
Output: 1
Explanation: The three integers "1", "01", and "001" all represent the same integer because
the leading zeros are ignored when comparing their decimal values.

Constraints:
1 <= word.length <= 1000
word consists of digits and lowercase English letters.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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
    int numDifferentIntegers(string word) {
        int start = -1;
        unordered_set<string> cnt;
        for (int i = 0, sz = word.size(); i < sz; ++i) {
            if (isdigit(word[i])) {
                if (start < 0 || (i == start+1 && word[start] == '0'))
                    start = i;
            } else {
                if (start >= 0)
                    cnt.emplace(word.substr(start, i-start));
                start = -1;
            }
        }
        if (start >= 0)
            cnt.emplace(word.substr(start));

        return cnt.size();
    }
};

int main() {
    Solution sol;
    string word;

    word = "4";
    cout << word << " -> " << sol.numDifferentIntegers(word) << endl;

    word = "a123bc34d8ef34";
    cout << word << " -> " << sol.numDifferentIntegers(word) << endl;

    // Output: 2
    word = "leet1234code234";
    cout << word << " -> " << sol.numDifferentIntegers(word) << endl;

    word = "a1b01c001";
    cout << word << " -> " << sol.numDifferentIntegers(word) << endl;

    return 0;
}
