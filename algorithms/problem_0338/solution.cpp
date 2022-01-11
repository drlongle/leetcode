/*
338. Counting Bits
Total Accepted: 28682 Total Submissions: 50355 Difficulty: Medium

Given a non negative integer number num. For every numbers i in the range
0 <= i <= num calculate the number of 1's in their binary representation and
return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:
    - It is very easy to come up with a solution with run time O(n*sizeof(integer)).
    But can you do it in linear time O(n) /possibly in a single pass?
    - Space complexity should be O(n).
    - Can you do it like a boss? Do it without using any builtin function like
    __builtin_popcount in c++ or in any other language.

Hint:

    You should make use of what you have produced already.
    Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try
    to generate new range from previous.
    Or does the odd/even status of the number help you in calculating the number of 1s?
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
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for (int n = 1; n <= num; ++n)
        {
            int j = 31;
            while ((n & (1 << j)) == false)
                --j;
            res[n] = 1 + res[n ^ (1 << j)];
        }
        
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> res;
    int num;

    cout << "Input: ";
    cin >> num;
    res = sol.countBits(num);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ","));
    cout << endl;

    return 0;
}

