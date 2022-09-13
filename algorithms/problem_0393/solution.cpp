/*
393. UTF-8 Validation
Difficulty: Medium

A character in UTF8 can be from 1 to 4 bytes long, subjected to the following
rules:

For 1-byte character, the first bit is a 0, followed by its unicode code.
For n-bytes character, the first n-bits are all one's, the n+1 bit is 0,
followed by n-1 bytes with most significant 2 bits being 10. This is how the
UTF-8 encoding would work:

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
Given an array of integers representing the data, return whether it is a valid
utf-8 encoding.

Note:
The input is an array of integers. Only the least significant 8 bits of each
integer is used to store the data. This means each integer represents only 1
byte of data.

Example 1:

data = [197, 130, 1], which represents the octet sequence: 11000101 10000010
00000001.

Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte
character. Example 2:

data = [235, 140, 4], which represented the octet sequence: 11101011 10001100
00000100.

Return false.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes
character. The next byte is a continuation byte which starts with 10 and that's
correct. But the second continuation byte does not start with 10, so it is
invalid.
*/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    int msb_ones(int x) {
        int res = 0, c = 1 << 7;
        while (x & c) {
            c >>= 1;
            ++res;
        }

        return res;
    }
    bool validUtf8(vector<int> &data) {
        int curr = 0, len = data.size();
        while (curr < len) {
            int x = data[curr] & 0xFF;
            int ones = msb_ones(x);
            if (!ones) {
                ++curr;
                continue;
            }
            if (ones == 1 || ones > 4)
                return false;
            if (++curr == len)
                return false;
            for (int i = 0; i < ones - 1; ++i, ++curr) {
                x = data[curr] & 0xFF;
                if (x >> 6 != 0b10)
                    return false;
            }
        }

        return true;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<int> data;

    // Expected: true
    data = {197, 130, 1};
    cout << boolalpha << sol.validUtf8(data) << endl;

    // Expected: fale
    data = {235, 140, 4};
    cout << boolalpha << sol.validUtf8(data) << endl;

    // Expected: false
    data = {237};
    cout << boolalpha << sol.validUtf8(data) << endl;

    // 39 / 49 test cases passed.
    // Expected: true
    data = {115, 100, 102, 231, 154, 132, 13, 10};
    cout << boolalpha << sol.validUtf8(data) << endl;

    return 0;
}
