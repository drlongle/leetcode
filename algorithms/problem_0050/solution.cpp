/*
 * 50. Pow(x, n)
 * 
 * Implement pow(x, n).
 */


#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
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
#include <vector>

using namespace std;

class Solution {
public:
    double myPow(double x, int n)
    {
        long long m = n;
        return myPow(x, m);
    }

    double myPow(double x, long long n)
    {
        if (!n || x == 1.0)
            return 1;
        if (n == 1) return x;
        if (n < 0) {
            if (x == 0)
                return NAN;
            else
                return 1.0 / myPow(x, -n);
        }
        double result = x;
        long long pow = 1;
        while (pow*2 <= n)
        {
            result = result * result;
            if (result == 0)
                return 0.0;
            pow <<= 1;
        }
        return result*myPow(x, n-pow);
    }
};

int main()
{
    Solution sol;
    double x = 0.5;
    int n = 3;
    cout << "Result: " << sol.myPow(x,n) << endl;

    return 0;
}

