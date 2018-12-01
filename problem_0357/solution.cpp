/*
357. Count Numbers with Unique Digits

Given a non-negative integer n, count all numbers with unique digits, x,
where 0 ≤ x < 10^n.

Example:

Input: 2
Output: 91 
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
             excluding 11,22,33,44,55,66,77,88,99.
*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    
    int unique(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 9;
        if (n > 10)
            return 0;
        int result = 81;
        for (int i = 3; i <= n; ++i)
            result *= (11 - i);
        return result;
    }
    int countNumbersWithUniqueDigits(int n) {
        int result = 0;
        for (int i = 0; i <= n; ++i)
            result += unique(i);
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    int n;
    
    // 91
    n = 2;
    
    // 739
    n = 3;
    
    cout << n << " --> " << sol.countNumbersWithUniqueDigits(n) << endl;
    
    return 0;
}

