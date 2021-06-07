/*
604. Design Compressed String Iterator
Easy

Design and implement a data structure for a compressed string iterator. The given compressed string
will be in the form of each letter followed by a positive integer representing the number of this
letter existing in the original uncompressed string.

Implement the StringIterator class:
next() Returns the next character if the original string still has uncompressed characters, otherwise returns a white space.
hasNext() Returns true if there is any letter needs to be uncompressed in the original string, otherwise returns false.

Example 1:
Input
["StringIterator", "next", "next", "next", "next", "next", "next", "hasNext", "next", "hasNext"]
[["L1e2t1C1o1d1e1"], [], [], [], [], [], [], [], [], []]
Output
[null, "L", "e", "e", "t", "C", "o", true, "d", true]

Explanation
StringIterator stringIterator = new StringIterator("L1e2t1C1o1d1e1");
stringIterator.next(); // return "L"
stringIterator.next(); // return "e"
stringIterator.next(); // return "e"
stringIterator.next(); // return "t"
stringIterator.next(); // return "C"
stringIterator.next(); // return "o"
stringIterator.hasNext(); // return True
stringIterator.next(); // return "d"
stringIterator.hasNext(); // return True

Constraints:
1 <= compressedString.length <= 1000
compressedString consists of lower-case an upper-case English letters and digits.
The number of a single character repetitions in compressedString is in the range [1, 10^9]
At most 100 calls will be made to next and hasNext.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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

class StringIterator {
public:
    StringIterator(string compressedString): s(compressedString), c(s[0]), index(0), cnt(0) {
        fetch();
    }

    void fetch() {
        c = s[index++];
        while (index < s.size () && !isalpha(s[index]))
            cnt = cnt * 10 + s[index++] - '0';
    }

    char next() {
        if (!hasNext())
            return ' ';
        if (!cnt)
            fetch();
        --cnt;
        return c;
    }

    bool hasNext() {
        return index < s.size () || cnt;
    }

    string s;
    char c;
    size_t index;
    int cnt = 0;
};

int main() {
    return 0;
}
