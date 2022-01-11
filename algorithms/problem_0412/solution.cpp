/*
412. Fizz Buzz
Easy

Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the
multiples of five output “Buzz”. For numbers which are multiples of both three and five
output “FizzBuzz”.

Example: n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
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
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; ++i) {
            bool div3 = (i % 3) == 0;
            bool div5 = (i % 5) == 0;
            if (div3 && div5)
                res.emplace_back("FizzBuzz");
            else if (div3)
                res.emplace_back("Fizz");
            else if (div5)
                res.emplace_back("Buzz");
            else
                res.emplace_back(to_string(i));
        }

        return res;
    }
};

int main()
{
    Solution sol;
    int n;

    n = 15;
    auto res = sol.fizzBuzz(n);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    
    return 0;
}

