/*
1147. Longest Chunked Palindrome Decomposition
Hard

Return the largest possible k such that there exists a_1, a_2, ..., a_k such that:
Each a_i is a non-empty string;
Their concatenation a_1 + a_2 + ... + a_k is equal to text;
For all 1 <= i <= k,  a_i = a_{k+1 - i}.

Example 1:
Input: text = "ghiabcdefhelloadamhelloabcdefghi"
Output: 7
Explanation: We can split the string on "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)".

Example 2:
Input: text = "merchant"
Output: 1
Explanation: We can split the string on "(merchant)".

Example 3:
Input: text = "antaprezatepzapreanta"
Output: 11
Explanation: We can split the string on "(a)(nt)(a)(pre)(za)(tpe)(za)(pre)(a)(nt)(a)".

Example 4:
Input: text = "aaa"
Output: 3
Explanation: We can split the string on "(a)(a)(a)".
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <condition_variable>
#include <cmath>
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

    bool compare(const string& text, int begin1, int begin2, int len) {
        for (int i = 0; i < len; ++i) {
            if (text[begin1+i] != text[begin2+i])
                return false;
        }
        return true;
    }

    int rfind(const string& text, char ch, int pos) {
        while (pos >= 0) {
            if (text[pos] == ch)
                return pos;
            --pos;
        }
        return -1;
    }

    int decomp(const string& text, int begin, int end) {
        if (begin > end)
            return 0;
        if (begin == end)
            return 1;
        auto pos = end;
        char ch = text[begin];
        int res = 1;
        while (true) {
            pos = rfind(text, ch, pos);
            if (pos == begin)
                return 1;
            int len = end - pos + 1;
            if (compare(text, begin, pos, len))
                return 2 + decomp(text, begin + len, end - len);
            --pos;
        }

        return res;
    }

    int longestDecomposition(string text) {
        return decomp(text, 0, text.size() - 1);
    }
};

int main() {
    Solution sol;
    string text;

    // Output: 7
    text = "ghiabcdefhelloadamhelloabcdefghi";

    // Output: 1
    text = "merchant";

    // Output: 11
    text = "antaprezatepzapreanta";

    // Output: 3
    text = "aaa";

    text = "elvtoelvto";

    cout << "Result: " << sol.longestDecomposition(text) << endl;

    return 0;
}

