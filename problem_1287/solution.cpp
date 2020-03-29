/*
1287. Element Appearing More Than 25% In Sorted Array
Easy

Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time.

Return that integer.

 
Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6

Constraints:
1 <= arr.length <= 10^4
0 <= arr[i] <= 10^5
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
    int findSpecialInteger(vector<int>& arr) {
        auto res = pair<int, int>(numeric_limits<int>::max(), 0);
        int expected_len = ceil(static_cast<double>(arr.size()) / 4);
        for (int n: arr) {
            if (n == res.first) {
                ++res.second;
                if (res.second > expected_len)
                    return res.first;
            } else if (res.second > 0)
                --res.second;
            else {
                res.first = n;
                res.second = 1;
            }
        }
        return res.first;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    arr = {1,2,2,6,6,6,6,7,10};

    arr = {1,1,2,2,3,3,3,3};
    
    cout << "Result: " << sol.findSpecialInteger(arr) << endl;
    
    return 0;
}
