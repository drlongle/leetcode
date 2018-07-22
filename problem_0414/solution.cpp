/*
 414. Third Maximum Number

    Total Accepted: 750
    Total Submissions: 2433
    Difficulty: Easy
    Contributors: Admin

Given an array of integers, return the 3rd Maximum Number in this array, if it doesn't exist, return the Maximum Number. The time complexity must be O(n) or less.

Example 1:
Input: [3, 2, 1]
Output: 1
Explanation: The third maximum is 1.

Example 2:
Input: [1, 2]
Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

Example 3:
Input: [2, 2, 3, 1]
Output: 1
Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> maxThree;
        for (auto& n: nums) {
            maxThree.emplace(n);
            if (maxThree.size() > 3)
                maxThree.erase(maxThree.begin());
        }
        if (maxThree.size() < 3)
            return *(maxThree.rbegin());
        else
            return *(maxThree.begin());
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    vector<int> nums;

    nums = {2, 2, 3, 1};
    nums = {3, 1};
    nums = {3, 1, 2};

    cout << "Result: " << sol.thirdMax(nums) << endl;

    return 0;
}

