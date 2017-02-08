/*
93. Restore IP Addresses

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",
return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
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
    void restore(const string& s, int begin, int end, int digit,
        string& currpath, vector<string>& result)
    {
        if (digit == 3) {
            if (end > begin && end - begin <= 3) {
                string sub = s.substr(begin, end-begin);
                if (stoi(sub) <= 255 && (s[begin] != '0' || (end-begin == 1)))
                {
                    currpath.append(".");
                    currpath.append(sub);
                    result.emplace_back(currpath);
                }
            }
        }
        else {
            for (int i = 0; i < 3 && begin + i < end ; ++i) {
                string sub = s.substr(begin, i+1);
                if (s[begin] == '0' && i) continue;
                int value = stoi(sub);
                if (value <= 255) {
                    string newpath = currpath;
                    if (digit > 0)
                        newpath.append(".");
                    newpath.append(sub);
                    restore(s, begin+i+1, end, digit+1, newpath, result);
                }
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string currpath;
        restore(s, 0, static_cast<int>(s.size()), 0, currpath, result);

        return result; 
    }
};

int main()
{
    Solution sol;
    string input;
    vector<string> result;

    input = "010010";
    result = sol.restoreIpAddresses(input) ;
    copy(result.begin(), result.end(), ostream_iterator<string>(cout, ","));

    return 0;
}
