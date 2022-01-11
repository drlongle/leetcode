/*
158. Read N Characters Given Read4 II - Call multiple times
Hard

Given a file and assume that you can only read the file using a given method read4, implement a
method read to read n characters. Your method read may be called multiple times.

Method read4:

The API read4 reads 4 consecutive characters from the file, then writes those
characters into the buffer array buf4.

The return value is the number of actual characters read.

Note that read4() has its own file pointer, much like FILE *fp in C.

Definition of read4:

    Parameter:  char[] buf4
    Returns:    int

Note: buf4[] is destination not source, the results from read4 will be copied to buf4[]
Below is a high level example of how read4 works:

File file("abcde"); // File is "abcde", initially file pointer (fp) points to 'a'
char[] buf4 = new char[4]; // Create buffer with enough space to store characters
read4(buf4); // read4 returns 4. Now buf4 = "abcd", fp points to 'e'
read4(buf4); // read4 returns 1. Now buf4 = "e", fp points to end of file
read4(buf4); // read4 returns 0. Now buf4 = "", fp points to end of file

Method read:

By using the read4 method, implement the method read that reads n characters from the file
and store it in the buffer array buf. Consider that you cannot manipulate the file directly.

The return value is the number of actual characters read.

Definition of read:
    Parameters:	char[] buf, int n
    Returns:	int
Note: buf[] is destination not source, you will need to write the results to buf[]

Example 1:
File file("abc");
Solution sol;
// Assume buf is allocated and guaranteed to have enough space for storing all characters from the file.
sol.read(buf, 1); // After calling your read method, buf should contain "a". We read a total of 1 character from the file, so return 1.
sol.read(buf, 2); // Now buf should contain "bc". We read a total of 2 characters from the file, so return 2.
sol.read(buf, 1); // We have reached the end of file, no more characters can be read. So return 0.

Example 2:
File file("abc");
Solution sol;
sol.read(buf, 4); // After calling your read method, buf should contain "abc". We read a total of 3 characters from the file, so return 3.
sol.read(buf, 1); // We have reached the end of file, no more characters can be read. So return 0.

Note:

Consider that you cannot manipulate the file directly, the file is only accessible for read4 but not for read.
The read function may be called multiple times.
Please remember to RESET your class variables declared in Solution, as static/class variables are persisted across multiple test cases. Please see here for more details.
You may assume the destination buffer array, buf, is guaranteed to have enough space for storing n characters.
It is guaranteed that in a given test case the same buffer buf is called by read.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

int read4(char *buf4)
{
    return 0;
}

class Solution {
public:
    Solution(): m_cache(0)
    {}
    int m_cache;
    char m_buf[4];

    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int res = 0;

        auto lambda = [&] () {
            int copy = min(n, m_cache);
            if (copy > 0) {
                memcpy(buf + res, m_buf, copy);
                res += copy;
                n -= copy;
                if (m_cache > copy) {
                    memmove(m_buf, m_buf + copy, m_cache - copy);
                }
                m_cache -= copy;
            }
        };

        lambda();

        while (n >= 4) {
            int t = read4(buf + res);
            res += t;
            n -= t;
            if (t < 4)
                return res;
        }

        if (n > 0) {
            m_cache = read4(m_buf);
            lambda();
        }

        return res;
    }
};

int main() {
    return 0;
}
