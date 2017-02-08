/*
80. Remove Duplicates from Sorted Array II  
Total Accepted: 74456 Total Submissions: 226873 Difficulty: Medium

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?
For example,
Given sorted array nums = [1,1,1,2,2,3],
Your function should return length = 5, with the first five elements of nums
being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pfast = 0, plow = 0, nsize = nums.size();
        for ( ; pfast < nsize; ++pfast) {
            if (plow < 2 || nums[pfast] != nums[plow-1] ||
                nums[pfast] != nums[plow-2])
                nums[plow++] = nums[pfast];
        }
        return plow;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int result;
    nums = {1,1,1,2,2,3};
    result = sol.removeDuplicates(nums);
    cout << "Result: " << result << endl;
    copy(nums.begin(), nums.begin()+result, ostream_iterator<int>(cout, ", "));

    return 0;
}

