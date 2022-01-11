/*
957. Prison Cells After N Days
Medium

There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

Example 1:
Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: 
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:
Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0]

Note:
cells.length == 8
cells[i] is in {0, 1}
1 <= N <= 10^9
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {
        vector<int> fc, next_c(cells.size(), 0);
        for (int cycle = 0; N-- > 0; cells = next_c, ++cycle)
        {
            for (size_t i = 1; i < cells.size() - 1; ++i)
                next_c[i] = cells[i - 1] == cells[i + 1];
            if (cycle == 0)
                fc = next_c;
            else if (next_c == fc)
                N %= cycle;
        }

        return cells;
    }
};

int main()
{
    Solution sol;
    vector<int> cells;
    int N;

    // Output: [0,0,1,1,0,0,0,0]
    cells = {0, 1, 0, 1, 1, 0, 0, 1}, N = 7;
    cells = sol.prisonAfterNDays(cells, N);
    copy(begin(cells), end(cells), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: [0,0,1,1,1,1,1,0]
    cells = {1, 0, 0, 1, 0, 0, 1, 0}, N = 1000000000;
    copy(begin(cells), end(cells), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
