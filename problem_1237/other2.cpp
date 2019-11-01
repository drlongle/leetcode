/*

Since f(x,y) returns a positive integer for any given positive (x,y), we just need to loop over [1, z]. Here's an easy proof:

f(1, 1) >= 1 (a positive integer is always at least 1), then
f(1, 2) > f(1, 1)  =>   f(1, 2) >= 2, then
f(1, 3) > f(1, 2)  =>   f(1, 3) >= 3, then
.....
f(1, z) >= z. 
Similarly, we have 
f(z, 1) >= z.
So for any number a > z , we have 
f(a, b) > f(z, b) >= f(z, 1) >= z, 
similarly, if b > z, we'll also have f(a, b) > z.
So if 
f(x, y) = z, 
we always have
x <= z and y <= z.
Then we use the two pointer methods to get an O(z) solution:

*/

class Solution {
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        int y = 1000;
        for (int x = 1; x <= 1000; ++x) {
            while (y > 1 && customfunction.f(x,y) > z) y--;
            if (customfunction.f(x,y) == z)
                res.push_back({x, y});
        }
        return res;
    }
};
