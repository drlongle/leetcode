/*
153. Find Minimum in Rotated Sorted Array  
Total Accepted: 88868 Total Submissions: 245959 Difficulty: Medium

Suppose a sorted array is rotated at some pivot unknown to you beforehand
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.
You may assume no duplicate exists in the array. 
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
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

using namespace std;

class Solution {
public:
    int my_findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size()-1;
        int ans = nums[0];
        while (begin < end) {
            int mid = begin + ((end-begin)>>1);
            if (nums[mid] < ans)
                ans = nums[mid];
            if (nums[begin] > nums[mid] || nums[mid] < nums[end])
                end = mid-1;
            else
                begin = mid+1;
        }

        return min(ans,nums[begin]);
    }

    int findMin(const vector<int> &A) {
        int low = 0, high = (int)A.size() - 1;
        int len = A.size();
        while (low <= high) {
            if (A[low] <= A[high]) return A[low]; // Case 1
            int mid = (low + high) / 2;
            int next = (mid + 1) % len, prev = (mid + len - 1) % len;
            if (A[mid] <= A[next] && A[mid] <= A[prev]) // Case 2
                return A[mid];
            else if (A[mid] <= A[high]) high = mid + 1; // Case 3
            else if (A[mid] >= A[low]) low = mid + 1; // Case 4
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Answer: " << sol.findMin(nums) << endl;

    return 0;
}

