/*
1151. Minimum Swaps to Group All 1's Together
Medium

Given a binary array data, return the minimum number of swaps required to group all
1’s present in the array together in any place in the array.

Example 1:
Input: [1,0,1,0,1]
Output: 1
Explanation: 
There are 3 ways to group all 1's together:
[1,1,1,0,0] using 1 swap.
[0,1,1,1,0] using 2 swaps.
[0,0,1,1,1] using 1 swap.
The minimum is 1.

Example 2:
Input: [0,0,0,1,0]
Output: 0
Explanation: 
Since there is only one 1 in the array, no swaps needed.

Example 3:
Input: [1,0,1,0,1,0,0,1,1,0,1]
Output: 3
Explanation: 
One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int nr_ones = count(begin(data), end(data), 1);
        int index = 0;
        int swaps = count(begin(data) + index, begin(data) + index + nr_ones, 0);
        int res = swaps;
        for (index = 1; index + nr_ones <= static_cast<int>(data.size()); ++index) {
            if (data[index-1] == 0)
                --swaps;
            if (data[index + nr_ones - 1] == 0)
                ++swaps;
            res = min(res, swaps);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> data;

    // Expected: 1
    data = {1,0,1,0,1};
    
    // Expected: 0
    //data = {0,0,0,1,0};
    
    // Expected: 3
    //data = {1,0,1,0,1,0,0,1,1,0,1};

    cout << "Result: " << sol.minSwaps(data) << endl;
    
    return 0;
}

