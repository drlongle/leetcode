/*
219. Contains Duplicate II

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k. 
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <string.h>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> lookup;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int n = nums[i];
            if (lookup.find(n) == lookup.end())
                lookup[n] = i;
            else {
                if (i - lookup[n] <= k)
                    return true;
                else lookup[n] = i;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> input;
    int k;
    input = {1,2,1};
    k = 0;
    cout << "Result: " << sol.containsNearbyDuplicate(input, k);

    return 0;
}
