/*
4. Median of Two Sorted Arrays

There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
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
    int find_nr_less_than_or_equal(vector<int>& nums, int k)
    {
        int size = static_cast<int>(nums.size());
        if (size == 0) return 0;

        int low = 0, high = size-1;
        while(low < high)
        {
            int mid = low + ((high-low) >> 1);
            if (nums[mid] <= k)
                low = mid+1;
            else
                high = mid-1;
        }
        return nums[low] > k ? low : low+1;
    }

    int findKthElementInSortedArrays(vector<int>& nums1, vector<int>& nums2,
        const int& k)
    {
        int size1 = static_cast<int>(nums1.size());
        int size2 = static_cast<int>(nums2.size());

        if (size1 == 0)
            return nums2[k];
        if (size2 == 0)
            return nums1[k];

        int x, low = 0, high = size1-1;
        for (int count = 0; count < 2; count++)
        {
            low = 0, high = nums1.size() -1;
            while (low < high)
            {
                int mid = low + ((high-low) >> 1);
                x = find_nr_less_than_or_equal(nums2, nums1[mid]);
                if (x+mid == k) {
                    low = mid;
                    break;
                }
                if (x > 0 && nums2[x-1] == nums1[mid] && x+mid == k+1)
                    return nums2[x-1];
                if (x+mid > k) high = mid-1;
                else low = mid+1;
            }

            x = find_nr_less_than_or_equal(nums2, nums1[low]);
            if (x+low == k)
                break;
            swap(nums1, nums2);
        }

        return nums1[low];
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int size1 = static_cast<int>(nums1.size());
        int size2 = static_cast<int>(nums2.size());
        int size = size1 + size2;
        int k = size >> 1;
        if (size & 0x1)
            return findKthElementInSortedArrays(nums1, nums2, k);
        int low = findKthElementInSortedArrays(nums1, nums2, k-1);
        int high = findKthElementInSortedArrays(nums1, nums2, k);
        double result = low + high;
        return result / 2;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1, nums2;
    nums1 = {1, 5, 9, 13, 17};
    nums2 = {2, 4, 11, 19, 21};

    double result = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Result: " << result << endl;

    return 0;
}

