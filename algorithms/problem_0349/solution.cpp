/*
349. Intersection of Two Arrays
Total Accepted: 16563 Total Submissions: 36951 Difficulty: Easy

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
    Each element in the result must be unique.
    The result can be in any order.
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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
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
                if (res.empty() || res.back() != nums1[index1])
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
    res = sol.intersection(nums1,nums2);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ","));

    return 0;
}

