/*
69. Sqrt(x)  
Total Accepted: 91585 Total Submissions: 363006 Difficulty: Medium

Implement int sqrt(int x).  Compute and return the square root of x.
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

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0)
            return 0;
        int begin = 0, end = x;
        long long mid = 0;
        while (begin <= end) {
            mid = begin + ((end-begin) >> 1);
            long long temp = mid*mid;
            if (temp == x)
                return mid;
            else if (temp > x)
                end = mid-1;
            else
                begin = mid+1;
        }

        return end;
    }
};

int main()
{
    Solution sol;
    int x;
    cout << "Input: ";
    cin >> x;
    cout << "Result: " << sol.mySqrt(x) << endl;

    return 0;
}

