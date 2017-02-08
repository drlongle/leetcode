/*
350. Intersection of Two Arrays II
Total Accepted: 11144 Total Submissions: 26840 Difficulty: Easy

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
    Each element in the result should appear as many times as it shows in both arrays. The result can be in any order.

Follow up:
    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int index1 = 0, size1 = nums1.size();
        int index2 = 0, size2 = nums2.size();
        while (index1 < size1 && index2 < size2)
        {
            if (nums1[index1] < nums2[index2])
                ++index1;
            else if (nums1[index1] > nums2[index2])
                ++index2;
            else
            {
                res.emplace_back(nums1[index1]);
                ++index1, ++index2;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1, nums2, res;
    nums1 = {1, 2, 2, 1};
    nums2 = {2, 2};
    res = sol.intersect(nums1,nums2);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ","));

    return 0;
}

