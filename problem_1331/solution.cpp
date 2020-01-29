/*
1331. Rank Transform of an Array
Easy

Given an array of integers arr, replace each element with its rank.
The rank represents how large the element is. The rank has the following rules:
Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.

Example 1:
Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.

Example 2:
Input: arr = [100,100,100]
Output: [1,1,1]
Explanation: Same elements share the same rank.

Example 3:
Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]

Constraints:
0 <= arr.length <= 105
-109 <= arr[i] <= 109
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
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> rank;
        for (auto a: arr)
            ++rank[a];
        int curr = 1;
        for (auto it = rank.begin(); it != rank.end(); ++it, ++curr) {
            it->second = curr;
        }
        
        for (auto& a: arr)
            a = rank[a];

        return arr;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    // Output: {4,1,2,3}
    arr = {40,10,20,30};

    // Output: {1,1,1}
    //arr = {100,100,100};

    // Output: {5,3,4,2,8,6,7,1,3}
    arr = {37,12,28,9,100,56,80,5,12};

    auto res = sol.arrayRankTransform(arr);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
        
    return 0;
}
