/*
321. Create Maximum Number

    Total Accepted: 11477
    Total Submissions: 49881
    Difficulty: Hard

Given two arrays of length m and n with digits 0-9 representing two numbers.
Create the maximum number of length k <= m + n from digits of the two. The
relative order of the digits from the same array must be preserved. Return an
array of the k digits. You should try to optimize your time and space
complexity.

Example 1:

nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:

nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:

nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9] 
*/

#include <algorithm>
#include <array>
#include <bitset>
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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    vector<vector<vector<string>>> cache;
    string maxNumber(vector<int>& nums1, vector<int>& nums2, int m, int n, int k)
    {
        string res;
        if (k == 0)
            return res;
        if (m < nums1.size() && n < nums2.size()) {
            res = cache[m][n][k];
            if (res.size() > 0)
                return res;
        }
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (n == size2 || (m < size1 && nums1[m] > nums2[n])) {
            res.push_back('0' + nums1[m]);
            res += maxNumber(nums1, nums2, m+1, n, k-1);
        } else if (m == size1 || (n < size2 && nums1[m] < nums2[n])) {
            res.push_back('0' + nums2[n]);
            res += maxNumber(nums1, nums2, m, n+1, k-1);
        } else if (m < size1 && n < size2 && nums1[m] == nums2[n]) {
            res.push_back('0' + nums1[m]);
            string r1 = maxNumber(nums1, nums2, m+1, n, k-1);
            string r2 = maxNumber(nums1, nums2, m, n+1, k-1);
            res += max(r1, r2);
        }
        if (size1 - m + size2 - n > k) {
            string r = max(maxNumber(nums1, nums2, m+1, n, k),
                maxNumber(nums1, nums2, m, n+1, k));
            if (r > res)
                res = r;
        }
        if (m < nums1.size() && n < nums2.size())
            cache[m][n][k] = res;
        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        cache = vector<vector<vector<string>>>(nums1.size(),
            vector<vector<string>>(nums2.size(), vector<string>(k+1, string())));
        string r = maxNumber(nums1, nums2, 0, 0, k);
        //cout << "Output: " << r << endl;
        vector<int> res;
        for (const auto& c: r)
            res.emplace_back(c - '0');

        return res;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    vector<int> nums1, nums2, res;
    int k;

    // Expected: [9, 8, 6, 5, 3]
    nums1 = {3, 4, 6, 5};
    nums2 = {9, 1, 2, 5, 8, 3};
    k = 5;

    // Expected: [6, 7, 6, 0, 4]
    //nums1 = {6, 7};
    //nums2 = {6, 0, 4};
    //k = 5;

    // Expected: [9, 8, 9] 
    //nums1 = {3, 9};
    //nums2 = {8, 9};
    //k = 3;

    nums1 = {8,0,4,4,1,7,3,6,5,9,3,6,6,0,2,5,1,7,7,7,8,7,1,4,4,5,4,8,7,6,2,2,9,4,7,5,6,2,2,8,4,6,0,4,7,8,9,1,7,0};
    nums2 = {6,9,8,1,1,5,7,3,1,3,3,4,9,2,8,0,6,9,3,3,7,8,3,4,2,4,7,4,5,7,7,2,5,6,3,6,7,0,3,5,3,2,8,1,6,6,1,0,8,4};
    k = 50;

    res = sol.maxNumber(nums1, nums2, k);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));

    return 0;
}

