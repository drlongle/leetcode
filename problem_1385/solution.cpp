/*
1385. Find the Distance Value Between Two Arrays
Easy

Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.

The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

Example 1:
Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
Output: 2

Explanation:
For arr1[0]=4 we have:
|4-10|=6 > d=2
|4-9|=5 > d=2
|4-1|=3 > d=2
|4-8|=4 > d=2
For arr1[1]=5 we have:
|5-10|=5 > d=2
|5-9|=4 > d=2
|5-1|=4 > d=2
|5-8|=3 > d=2
For arr1[2]=8 we have:
|8-10|=2 <= d=2
|8-9|=1 <= d=2
|8-1|=7 > d=2
|8-8|=0 <= d=2

Example 2:
Input: arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
Output: 2

Example 3:
Input: arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
Output: 1

Constraints:
1 <= arr1.length, arr2.length <= 500
-10^3 <= arr1[i], arr2[j] <= 10^3
0 <= d <= 100
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
#include <memory>
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
    bool is_distance(vector<int>& arr, int val, int d) {
        for (int a: arr) {
            if (abs(val - a) <= d)
                return false;
        }
        return true;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for (int a: arr1)
            cnt += is_distance(arr2, a, d);
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> arr1, arr2;
    int d;

    // Output: 2
    arr1 = {4,5,8}, arr2 = {10,9,1,8}, d = 2;
    cout << sol.findTheDistanceValue(arr1, arr2, d) << endl;
    
    // Output: 2
    arr1 = {1,4,2,3}, arr2 = {-4,-3,6,10,20,30}, d = 3;
    cout << sol.findTheDistanceValue(arr1, arr2, d) << endl;

    // Output: 1
    arr1 = {2,1,100,3}, arr2 = {-5,-2,10,-3,7}, d = 6;
    cout << sol.findTheDistanceValue(arr1, arr2, d) << endl;

    return 0;
}
