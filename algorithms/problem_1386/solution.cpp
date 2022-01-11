/*
1386. Cinema Seat Allocation
Medium

A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10 as shown in the figure above.

Given the array reservedSeats containing the numbers of seats already reserved, for example, reservedSeats[i]=[3,8] means the seat located in row 3 and labelled with 8 is already reserved. 

Return the maximum number of four-person families you can allocate on the cinema seats. A four-person family occupies fours seats in one row, that are next to each other. Seats across an aisle (such as [3,3] and [3,4]) are not considered to be next to each other, however, It is permissible for the four-person family to be separated by an aisle, but in that case, exactly two people have to sit on each side of the aisle.

Example 1:
Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows the optimal allocation for four families, where seats mark with blue are already reserved and contiguous seats mark with orange are for one family. 

Example 2:
Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
Output: 2

Example 3:
Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
Output: 4

Constraints:
1 <= n <= 10^9
1 <= reservedSeats.length <= min(10*n, 10^4)
reservedSeats[i].length == 2
1 <= reservedSeats[i][0] <= n
1 <= reservedSeats[i][1] <= 10
All reservedSeats[i] are distinct.
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
#include <memory>
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
    int not_taken(bitset<16> reserved, vector<int>& seats) {
        for (int seat: seats) {
            if (reserved.test(seat))
                return false;
        }
        return true;
    }
    
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int res = 0;
        sort(begin(reservedSeats), end(reservedSeats));
        int i = 0, last_row = 0, sz = reservedSeats.size();
        auto left = vector<int>{2, 3};
        auto right = vector<int>{8, 9};
        auto middle = vector<int>{4, 5, 6, 7};
        auto middle_left = vector<int>{4, 5};
        auto middle_right = vector<int>{6, 7};
        while (i < sz) {
            bitset<16> taken;
            int row = reservedSeats[i][0];
            taken.set(reservedSeats[i][1]);
            res += 2* (row - last_row - 1);
            ++i;
            while (i < sz && reservedSeats[i][0] == row) {
                taken.set(reservedSeats[i][1]);
                ++i;
            }

            auto lres = not_taken(taken, left);
            auto mres = not_taken(taken, middle);
            auto rres = not_taken(taken, right);
            if (lres && mres && rres) {
                res += 2;
            } else if (mres) {
                ++res;
            } else if (lres && not_taken(taken, middle_left))
                ++res;
            else if (rres && not_taken(taken, middle_right))
                ++res;
            last_row = row;
        }

        res += max(0, 2 * (n - last_row));
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> reservedSeats;
    int n;

    // Output: 4
    n = 3, reservedSeats = {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}};
    //cout << sol.maxNumberOfFamilies(n, reservedSeats) << endl;
    
    // Output: 2
    n = 2, reservedSeats = {{2,1},{1,8},{2,6}};
    //cout << sol.maxNumberOfFamilies(n, reservedSeats) << endl;
    
    // Output: 4
    n = 4, reservedSeats = {{4,3},{1,4},{4,6},{1,7}};
    cout << sol.maxNumberOfFamilies(n, reservedSeats) << endl;

    return 0;
}
