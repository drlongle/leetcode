/*
The idea is simple, we maintain a vector, whose prefix sum corresponds to number of passengers on each plane.
If plane i until plane j are all increased by k, we modify the vector by adding i by k, and reducing j + 1 by k.
*/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> changes(n + 1, 0);
        for (vector<int> b : bookings) {
            changes[b[0] - 1] += b[2];
            changes[b[1]] -= b[2];
        }
        for (int i = 1; i <= n; ++i) {
            changes[i] += changes[i - 1];
        }
        changes.pop_back();
        return changes;
    }
};

