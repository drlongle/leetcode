/*
1306. Jump Game III
Medium

Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 

Example 2:
Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3

Example 3:
Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
 
Constraints:
1 <= arr.length <= 5 * 10^4
0 <= arr[i] < arr.length
0 <= start < arr.length
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
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        unordered_set<int> v;
        q.emplace(start);
        v.emplace(start);
        int sz = arr.size();
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (arr[i] == 0)
                return true;
            for (int sign: {1, -1}) {
                int n = i + sign*arr[i];
                if (n >= 0 && n < sz && v.insert(n).second)
                    q.emplace(n);
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int start;

    // True
    arr = {4,2,3,0,3,1,2}, start = 5;

    // True
    //arr = {4,2,3,0,3,1,2}, start = 0;

    // False
    //arr = {3,0,2,1,2}, start = 2;
    
    cout << "Result: " << sol.canReach(arr, start) << endl;
         
    return 0;
}
