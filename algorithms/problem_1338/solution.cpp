/*
1338. Reduce Array Size to The Half
Medium

Given an array arr.  You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed. 

Example 1:
Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has size greater than half of the size of the old array.

Example 2:
Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.

Example 3:
Input: arr = [1,9]
Output: 1

Example 4:
Input: arr = [1000,1000,3,7]
Output: 1

Example 5:
Input: arr = [1,2,3,4,5,6,7,8,9,10]
Output: 5

Constraints:

1 <= arr.length <= 10^5
arr.length is even.
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
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> cnt;
        multiset<int, greater<int>> szs;
        int threshold = arr.size() / 2;
        for (int a: arr)
            ++cnt[a];
        for (auto& p: cnt)
            szs.emplace(p.second);
        int res = 0, acc = 0;
        auto it = szs.begin();
        while (acc < threshold) {
            acc += *(it++);
            ++res;
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    // Output: 2
    arr = {3,3,3,3,5,5,5,2,2,7};

    // Output: 1
    //arr = {7,7,7,7,7,7};

    // Output: 1
    //arr = {1,9};

    // Output: 1
    //arr = {1000,1000,3,7};

    //Output: 5
    //arr = {1,2,3,4,5,6,7,8,9,10};

    //Output: 14
    arr = {2,28,92,30,100,52,28,48,91,27,66,19,11,53,91,95,74,51,65,65,96,81,21,55,98,3,2,89,99,57,78,34,50,2,57,76,23,90,89,36,53,22,73,59,95,45};
    
    cout << "Result: " << sol.minSetSize(arr) << endl;
    
    
    return 0;
}
