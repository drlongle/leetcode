/*
1089. Duplicate Zeros
Difficulty: Easy

Given a fixed length array arr of integers, duplicate each occurrence of
zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.

Example 1:
Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

Example 2:
Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int ssize = arr.size();
        vector<int> temp;
        temp.resize(ssize);
        for (int slow = 0, fast = 0; fast < ssize; ++slow, ++fast) {
            temp[fast] = arr[slow];
            if (arr[slow] == 0 && fast < ssize-1)
                temp[++fast] = 0;
        }
        copy(begin(temp), end(temp), begin(arr));

        return;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    // Expected: [1,0,0,2,3,0,0,4]
    arr = {1,0,2,3,0,4,5,0};

    arr = {0,0,0,0,0,0,0};

    //11 / 30 test cases passed.
    // Expected: [0,0,1,7,6,0,0,2]
    //arr = {0,1,7,6,0,2,0,7};


    sol.duplicateZeros(arr);

    copy(begin(arr), end(arr), ostream_iterator<int>(cout, ","));
    cout << endl;

    return 0;
}

