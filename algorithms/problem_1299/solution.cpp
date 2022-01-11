/*
1299. Replace Elements with Greatest Element on Right Side
Easy

Given an array arr, replace every element in that array with the greatest element
among the elements to its right, and replace the last element with -1.
After doing so, return the array. 

Example 1:
Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]

Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5
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
    vector<int> replaceElements(vector<int>& arr) {
        int max_value = arr.back();
        int sz = arr.size();
        vector<int> res(sz, -1);
        for (int i = sz-2; i >= 0; --i) {
            res[i] = max_value;
            max_value = max(max_value, arr[i]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
