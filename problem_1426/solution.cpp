/*
Counting Elements

Given an integer array arr, count element x such that x + 1 is also in arr.
If there're duplicates in arr, count them seperately.

Example 1:
Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.

Example 2:
Input: arr = [1,1,3,3,5,5,7,7]
Output: 0
Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.

Example 3:
Input: arr = [1,3,2,3,5,0]
Output: 3
Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.

Example 4:
Input: arr = [1,1,2,2]
Output: 2
Explanation: Two 1s are counted cause 2 is in arr.

Constraints:
1 <= arr.length <= 1000
0 <= arr[i] <= 1000
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
    int countElements(vector<int>& arr) {
        unordered_map<int, int> cnt;

        for (int a: arr) {
            ++cnt[a];
        }

        int res = 0;
        for (auto& [key, value]: cnt) {
            auto it = cnt.find(key+1);
            if (it != cnt.end())
                res += value;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    // Output: 2
    arr = {1,2,3};
    cout << sol.countElements(arr) << endl;

    // Output: 0
    arr = {1,1,3,3,5,5,7,7};
    cout << sol.countElements(arr) << endl;
    
    // Output: 3
    arr = {1,3,2,3,5,0};
    cout << sol.countElements(arr) << endl;
    
    // Output: 2
    arr = {1,1,2,2};
    cout << sol.countElements(arr) << endl;

    // Output: 2
    arr = {1,1,2};
    cout << sol.countElements(arr) << endl;
    
    return 0;
}
