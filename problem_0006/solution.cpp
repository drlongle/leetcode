/*
6. ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 

 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> myStrings = vector<string>(numRows);
        bool goDown = true;
        int index = 0;
        for (int i = 0; i < static_cast<int>(s.size()); ++i)
        {
            myStrings[index].push_back(s[i]);

            if (goDown) ++index;
            else --index;

            if (goDown) {
                if (index == numRows) {
                    index = max<int>(0, numRows - 2);
                    goDown = false;
                }
            } else {
                if (index < 0) {
                    index = min<int>(1, numRows - 1);
                    goDown = true;
                }
            }
        }

        ostringstream oss;
        for (int i = 0; i < static_cast<int>(myStrings.size()); ++i)
            oss << myStrings[i];
        return oss.str();
    }
};

int main()
{
    Solution solution;
    string s = "PAYPALISHIRING";
    int numRows = 1;
    cout << solution.convert(s, numRows);
}

