/*
443. String Compression

Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

Follow up:
Could you solve it using only O(1) extra space?
 
Example 1:

Input:
["a","a","b","b","c","c","c"]
Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".

Example 2:
Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]
Explanation:
Nothing is replaced.
 

Example 3:
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int compress(vector<char>& chars)
    {
        int sz = chars.size();
        if (sz <= 1)
            return sz;
        char curr = chars[0];
        int count = 1;
        int len = 0;
        int head = 0;

        auto update = [&]() {
            if (count == 1) {
                ++len;
                chars[head++] = curr;
            } else {
                string count_str = to_string(count);
                chars[head++] = curr;
                copy(begin(count_str), end(count_str), begin(chars) + head);
                head += count_str.size();
                len += 1 + count_str.size();
            }
        };

        for (int i = 1; i < sz; ++i) {
            if (chars[i] == curr)
                ++count;
            else {
                update();
                curr = chars[i];
                count = 1;
            }
        }

        update();

        return len;
    }
};

int main()
{
    Solution sol;
    vector<char> chars;

    chars = {'a'};

    // Expected: 6
    chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    // Expected: 4
    chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};

    int res = sol.compress(chars);
    copy(begin(chars), end(chars), ostream_iterator<char>(cout, ", "));
    cout << endl << "Length: " << res << endl;

    return 0;
}
