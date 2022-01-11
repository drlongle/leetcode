/*
66. Plus One
Total Accepted: 104471 Total Submissions: 305540 Difficulty: Easy

Given a non-negative number represented as an array of digits, plus one to the number. The digits are stored such that the most significant digit is at the head of the list.

https://leetcode.com/problems/plus-one/
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int index = digits.size() -1;
        while (index >= 0 && carry)
        {
            ++digits[index];
            if (digits[index] >= 10)
                digits[index] -= 10;
            else
                carry = 0;
            --index;
        }
        if (index < 0 && carry)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main()
{
    Solution sol;
    vector<int> input, result;
    input = {1,2,3};
    result = sol.plusOne(input);
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, ","));

    return 0;
}

