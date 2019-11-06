/*
1243. Array Transformation
Easy

Given an initial array arr, every day you produce a new array using the array of the previous day.
On the i-th day, you do the following operations on the array of day i-1 to produce the array of day i:
* If an element is smaller than both its left neighbor and its right neighbor, then this element is incremented.
* If an element is bigger than both its left neighbor and its right neighbor, then this element is decremented.
The first and last elements never change.
After some days, the array does not change. Return that final array.

Example 1:
Input: arr = [6,2,3,4]
Output: [6,3,3,4]
Explanation: 
On the first day, the array is changed from [6,2,3,4] to [6,3,3,4].
No more operations can be done to this array.

Example 2:
Input: arr = [1,6,3,4,3,5]
Output: [1,4,4,4,4,5]
Explanation: 
On the first day, the array is changed from [1,6,3,4,3,5] to [1,5,4,3,4,5].
On the second day, the array is changed from [1,5,4,3,4,5] to [1,4,4,4,4,5].
No more operations can be done to this array.

Constraints:
1 <= arr.length <= 100
1 <= arr[i] <= 100
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
    vector<int> transformArray(vector<int>& arr) {
        int sz = arr.size();
        vector<int> new_arr(begin(arr), end(arr));

        bool changed = true;
        while (changed) {
            swap(arr, new_arr);
            changed = false;
            int adjust = numeric_limits<int>::max();
            for (int i = 1; i < sz-1; ++i) {
                auto mm = minmax(arr[i-1], arr[i+1]);
                if (arr[i] > mm.second) {
                    adjust = min(adjust, (arr[i] - mm.second + 1)/2);
                    changed = true;
                } else if (arr[i] < mm.first) {
                    adjust = min(adjust, (mm.first - arr[i] + 1)/2);
                    changed = true;
                }
            }

            for (int i = 1; changed && i < sz-1; ++i) {
                auto mm = minmax(arr[i-1], arr[i+1]);
                if (arr[i] > mm.second) {
                    new_arr[i] = arr[i] - adjust;
                } else if (arr[i] < mm.first) {
                    new_arr[i] = arr[i] + adjust;
                } else {
                    new_arr[i] = arr[i];
                }

            }
        }
        
        return arr;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    // Output: {6,3,3,4]
    arr = {6,2,3,4};

    //Output: [1,4,4,4,4,5]
    arr = {1,6,3,4,3,5};

    auto res = sol.transformArray(arr);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    return 0;
}
