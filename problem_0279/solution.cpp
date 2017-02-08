/*
279. Perfect Squares
Total Accepted: 38489 Total Submissions: 115494 Difficulty: Medium

Given a positive integer n, find the least number of perfect square numbers
(for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13,
return 2 because 13 = 4 + 9.  
 */

#include <algorithm>
#include <array>
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
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:
    int numSquares(int num) {
        vector<int> res(num+1);
        res[0] = 0;
        res[1] = 1;

        for (int n = 2; n <= num; ++n)
        {
            int temp = numeric_limits<int>::max();
            for (int i = 1; i*i <= n; ++i)
            {
                if (temp > res[n-i*i])
                    temp = res[n-i*i];
            }
            res[n] = temp + 1;
        }

        return res[num];
    }
};

int main()
{
    Solution sol;
    int num;
  
    cout << "Input: ";
    cin >> num;
    cout << "Result: " << sol.numSquares(num) << endl;

    return 0;
}

