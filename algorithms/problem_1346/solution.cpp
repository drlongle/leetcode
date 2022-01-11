/*
1346. Check If N and Its Double Exist
Easy

Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).

More formally check if there exists two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]

Example 1:
Input: arr = [10,2,5,3]
Output: true
Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.

Example 2:
Input: arr = [7,1,14,11]
Output: true
Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.

Example 3:
Input: arr = [3,1,7,11]
Output: false
Explanation: In this case does not exist N and M, such that N = 2 * M.

Constraints:
2 <= arr.length <= 500
-10^3 <= arr[i] <= 10^3
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
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> nums;
        int zero = 0;
        for (int a: arr) {
            if (a)
                nums.emplace(a);
            else
                ++zero;
        }
        if (zero > 1)
            return true;
        for (auto& num: nums) {
            if (nums.count(2*num))
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    // False
    arr = {-2,0,10,-19,4,6,-8};

    // True
    //arr = {0,0};

    cout << sol.checkIfExist(arr) << endl;
        
    return 0;
}
