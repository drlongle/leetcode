/*
278. First Bad Version  
Total Accepted: 40918 Total Submissions: 182659 Difficulty: Easy

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API. 
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
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<bool> versions;
bool isBadVersion(int index)
{
    return versions[index];
}

class Solution {
public:
    int firstBadVersion(int n) {
        int begin = 1;
        int mid, end = n;
        while (begin < end)
        {
            if (begin + 1 == end) {
                if (isBadVersion(begin))
                    return begin;
                else
                    return end;
            }
            mid = begin + ((end-begin) >> 1);
            if (isBadVersion(mid))
                end = mid;
            else
                begin = mid+1;
        }
        return begin;
    }
};

int main()
{
    Solution sol;

    return 0;
}

