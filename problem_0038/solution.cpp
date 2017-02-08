/*
38. Count and Say

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence. Note: The sequence of integers will be represented as a string. 
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
    string countAndSay(int n)
    {
        string curr = "1";
        for (int i = 1; i < n; ++i)
        {
            ostringstream oss;
            int ssize = static_cast<int>(curr.size());
            char ch = curr[0];
            int count = 1;
            for (int j = 1; j < ssize; ++j)
            {
                if (curr[j] != ch)
                {
                    char temp = '0' + count;
                    oss << temp;
                    oss << ch;
                    ch = curr[j];
                    count = 1;
                }
                else
                    ++count;
            }
            char temp = '0' + count;
            oss << temp;
            oss << ch;
            curr = oss.str();
            oss.clear();
        }
        return curr;
    }
};

int main()
{
    Solution sol;
    int input = 10;
    cout << "Result: " << sol.countAndSay(input) << endl;

    return 0;
}
