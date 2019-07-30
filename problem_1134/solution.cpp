/*
1134. Armstrong Number
Difficulty: Easy

The k-digit number N is an Armstrong number if and only if the k-th power
of each digit sums to N. Given a positive integer N, return true
if and only if it is an Armstrong number.

Example 1:
Input: 153
Output: true
Explanation: 
153 is a 3-digit number, and 153 = 1^3 + 5^3 + 3^3.

Example 2:
Input: 123
Output: false
Explanation: 
123 is a 3-digit number, and 123 != 1^3 + 2^3 + 3^3 = 36.
*/

#include <algorithm>
#include <cassert>
#include <cmath>
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
    bool isArmstrong(int N) {
        int digits = 1 + floor(log10(N));
        int sum = 0;
        int x = N;
        while (x != 0) {
            int t = x % 10;
            sum += pow(t, digits);
            x /= 10;
        }

        return sum == N;
    }
};

int main()
{
    Solution sol;
    int N;

    N = 153;
    N = 123;
    cout << "Result: " << sol.isArmstrong(N) << endl;
    
    return 0;
}

