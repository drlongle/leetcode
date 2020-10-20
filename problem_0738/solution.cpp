/*
738. Monotone Increasing Digits
Medium

Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Example 1:
Input: N = 10
Output: 9

Example 2:
Input: N = 1234
Output: 1234

Example 3:
Input: N = 332
Output: 299
Note: N is an integer in the range [0, 10^9].
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

using namespace std;

class Solution {
public:
    int get_index(string& s) {
        int index = 1, sz = s.size();
        for (; index < sz; ++index) {
            if (s[index] < s[index-1])
                return index;
        }

        return sz;
    }

    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int min_index = get_index(s);
        int index, sz = s.size();
        if (min_index == sz)
            return N;
        for (index = min_index -1; index >= 0 && s[index] == s[min_index]; --index) {

        }
        if (index < 0)
            return N;
        for (; index > 0 && s[index] == s[index-1]; --index) {

        }
        --s[index];
        for (int j = index-1; j >= 0; --j) {
            if (s[j] > s[j+1])
                --s[j];
            else
                break;
        }
        for (int i = index+1; i < sz; ++i)
            s[i] = '9';

        return stoi(s);
    }
};

int main() {
    Solution sol;
    int N;

    // Output: 9
    N = 10;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    // Output: 1234
    N = 1234;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    // Output: 299
    N = 332;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    // Output: 1
    N = 1;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    // Output: 0
    N = 0;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    // Output: 119
    N = 120;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    // Output: 99
    N = 101;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    // Output: 99
    N = 102;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    // Output: 19
    N = 20;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    // Output: 119
    N = 121;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    // Output: 129
    N = 132;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    // Output: 8999
    N = 9876;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    // Output: 8999
    N = 9582;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    // Output: 2499
    N = 2516;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    // Output: 111
    N = 111;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    // Output: 22222
    N = 22222;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    N = 8888;
    cout << N << " -> " << sol.monotoneIncreasingDigits(N) << endl;

    return 0;
}
