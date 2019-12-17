/*
1291. Sequential Digits
Medium

An integer has sequential digits if and only if each digit in the number is one more than the
previous digit. Return a sorted list of all the integers in the range [low, high] inclusive that
have sequential digits.

Example 1:
Input: low = 100, high = 300
Output: [123,234]

Example 2:
Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]

Constraints:
10 <= low <= high <= 10^9
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

    vector<int> getNums(int digits) {
        long long num = 0, offset = 0;
        for (int i = 1; i <= digits; ++i) {
            num = num*10 + i;
            offset = offset * 10 + 1;
        }

        vector<int> res(1, num);
        num += offset;
        while (num % 10 != 0) {
            res.emplace_back(num);
            num += offset;
        }
        return res;
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int i = log10(low); i <= ceil(log10(high)); ++i) {
            auto r = getNums(i);
            for (int a: r) {
                if (a >= low && a <= high)
                    res.emplace_back(a);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    int low, high;

    // Output: [123,234]
    low = 100, high = 300;

    // Output: [1234,2345,3456,4567,5678,6789,12345]
    low = 1000, high = 13000;

    low = 10, high = 1000000000;
    
    auto res = sol.sequentialDigits(low, high);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    return 0;
}
