/*
215. Kth Largest Element in an Array
Total Accepted: 51275 Total Submissions: 155734 Difficulty: Medium

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 <= k <= array's length.
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
    int partition(vector<int>& nums, int begin, int end) {
        int r = begin + rand() % (end-begin+1);
        swap(nums[r], nums[end]);
        int pivot = nums[end], boundary = begin;
        for (int i = begin; i < end; i++)
        {
            if (nums[i] < pivot)
                swap(nums[boundary++], nums[i]);
        }
        swap(nums[boundary], nums[end]);

        return boundary;
    }

    int findKthLargest(vector<int>& nums, int begin, int end, int k) {
        assert(begin <= k && k <= end);
        int q = partition(nums, begin, end);
        if (q < k)
            return findKthLargest(nums, q+1, end, k);
        if (q == k)
            return nums[k];
        else
            return findKthLargest(nums, begin, q-1, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(std::time(0));
        return findKthLargest(nums, 0, nums.size()-1, nums.size()-k); 
    }
};

int main()
{
    Solution sol;
    vector<int> input;
    int k;

    input = {3,2,1,5,6,4};
    k = 2;
    cout << "result : " << sol.findKthLargest(input, k) << endl;

    return 0;
}

