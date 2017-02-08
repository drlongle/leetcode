/*
119. Pascal's Triangle II
Total Accepted: 78799 Total Submissions: 239896 Difficulty: Easy

Given an index k, return the kth row of the Pascal's triangle.
For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space? 
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
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if (rowIndex < 0)
            return res;
        
        for (int i = 0; i <= rowIndex; ++i)
        {
            int prev = 1; 
            for (int j = 1; j < i; ++j)
            {
                int temp = res[j];
                res[j] += prev;
                prev = temp;
            }
            res.emplace_back(1);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    int rowIndex;
    vector<int> res;
    cout << "Input: ";
    cin >> rowIndex;
    res = sol.getRow(rowIndex);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ","));
    cout << endl;

    return 0;
}

