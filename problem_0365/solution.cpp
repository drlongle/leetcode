/*
365. Water and Jug Problem
Difficulty: Medium

You are given two jugs with capacities x and y litres. There is an infinite
amount of water supply available. You need to determine whether it is possible
to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained
within one or both buckets by the end.

Operations allowed:
Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or
the first jug itself is empty.

Example 1: (From the famous "Die Hard" example)
Input: x = 3, y = 5, z = 4
Output: True

Example 2:
Input: x = 2, y = 6, z = 5
Output: False
*/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <set>
#include <unordered_set>

using namespace std;

/*
Key idea is that z litres is measurable using jugs of size x and y only if z is
a linear combination of x and y.

Reasoning for key idea : basically only options we have to solve the issue is
either pour water of amount x or y (which is positive multiplication constant
on x or y) or a choice of emptying x or y (which is negative multiplication
constant on x or y). Hence for z to be measurable by x and y, z has to be 
z = sx+ly (where s and l are integer constants)

So, in positive case where z = kx + ly where k and l are constants, z is measurable. 
Now, if g is gcd of x and y, then z = kag + lbg where a and b are constants 
So, z = (ka+lb)g -> which suggests z must be divisible by g in order for z to be
measurable by x and y. 
AND 
x + y must be equal or greater than z, otherwise we can fill up x and y both but
still they will sum up less than z. Hence, z won't be measurable if x + y < z

using that logic, we can say answer is:
return true if z % gcd(x, y) == 0 and x + y >= z
*/
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z)
            return false;
        if (x == z || y == z || x + y == z)
            return true;
        return z % gcd(x, y) == 0;
    }

    int gcd(int x, int y) {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }
};

int main(int argc, char** argv) {
    Solution sol;
    int x, y, z;
    bool expected;

    // Expected: true
    x = 3, y = 5, z = 4, expected = true;
    //cout << "x: " << x << ", y: " << y << ", z: " << z << " --> " << boolalpha
    //    << sol.canMeasureWater(x, y, z) << ", expected: " << expected << endl;

    x = 2, y = 6, z = 5, expected = false;
    //cout << "x: " << x << ", y: " << y << ", z: " << z << " --> " << boolalpha
    //    << sol.canMeasureWater(x, y, z) << ", expected: " << expected << endl;

    // Expected: true
    x = 34, y = 5, z = 6, expected = true;
    //cout << "x: " << x << ", y: " << y << ", z: " << z << " --> " << boolalpha
    //    << sol.canMeasureWater(x, y, z) << ", expected: " << expected << endl;

    // Expected: false
    x = 1, y = 1, z = 12, expected = false;
    //cout << "x: " << x << ", y: " << y << ", z: " << z << " --> " << boolalpha
    //    << sol.canMeasureWater(x, y, z) << ", expected: " << expected << endl;

    // Expected: true
    x = 13, y = 11, z = 1, expected = true;
    //cout << "x: " << x << ", y: " << y << ", z: " << z << " --> " << boolalpha
    //    << sol.canMeasureWater(x, y, z) << ", expected: " << expected << endl;

    // Expected: false
    x = 6, y = 9, z = 1, expected = false;
    //cout << "x: " << x << ", y: " << y << ", z: " << z << " --> " << boolalpha
    //    << sol.canMeasureWater(x, y, z) << ", expected: " << expected << endl;

    // Expected: true
    x = 13, y = 11, z = 3, expected = true;
    //cout << "x: " << x << ", y: " << y << ", z: " << z << " --> " << boolalpha
    //    << sol.canMeasureWater(x, y, z) << ", expected: " << expected << endl;

    // Expected: true
    x = 22003, y = 31237, z = 1, expected = true;
    cout << "x: " << x << ", y: " << y << ", z: " << z << " --> " << boolalpha
        << sol.canMeasureWater(x, y, z) << ", expected: " << expected << endl;

    x = 104579, y = 104593, z = 12444;
    cout << "x: " << x << ", y: " << y << ", z: " << z << " --> " << boolalpha
        << sol.canMeasureWater(x, y, z) << ", expected: " << expected << endl;

    return 0;
}
