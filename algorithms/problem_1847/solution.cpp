/*
1847. Closest Room
Hard

There is a hotel with n rooms. The rooms are represented by a 2D integer array rooms where rooms[i] = [roomIdi, sizei] denotes that there is a room with room number roomIdi and size equal to sizei. Each roomIdi is guaranteed to be unique.

You are also given k queries in a 2D array queries where queries[j] = [preferredj, minSizej]. The answer to the jth query is the room number id of a room such that:

The room has a size of at least minSizej, and
abs(id - preferredj) is minimized, where abs(x) is the absolute value of x.
If there is a tie in the absolute difference, then use the room with the smallest such id. If there is no such room, the answer is -1.

Return an array answer of length k where answer[j] contains the answer to the jth query.

Example 1:
Input: rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
Output: [3,-1,3]
Explanation: The answers to the queries are as follows:
Query = [3,1]: Room number 3 is the closest as abs(3 - 3) = 0, and its size of 2 is at least 1. The answer is 3.
Query = [3,3]: There are no rooms with a size of at least 3, so the answer is -1.
Query = [5,2]: Room number 3 is the closest as abs(3 - 5) = 2, and its size of 2 is at least 2. The answer is 3.

Example 2:
Input: rooms = [[1,4],[2,3],[3,5],[4,1],[5,2]], queries = [[2,3],[2,4],[2,5]]
Output: [2,1,3]
Explanation: The answers to the queries are as follows:
Query = [2,3]: Room number 2 is the closest as abs(2 - 2) = 0, and its size of 3 is at least 3. The answer is 2.
Query = [2,4]: Room numbers 1 and 3 both have sizes of at least 4. The answer is 1 since it is smaller.
Query = [2,5]: Room number 3 is the only room with a size of at least 5. The answer is 3.

Constraints:
n == rooms.length
1 <= n <= 10^5
k == queries.length
1 <= k <= 10^4
1 <= roomIdi, preferredj <= 10^7
1 <= sizei, minSizej <= 10^7
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
public:
    static constexpr int nr_segments = 100000;
    static constexpr int segsize = 100;
    int n, res, currdist, segnr;
    map<int, int> sorted_rooms;
    int localmax[nr_segments];

    void closestRoom(vector<int>& query, int segindex) {
        int room_id = query[0], room_size = query[1];
        int start_nr = segindex * segsize;
        int end_nr = start_nr + segsize;
        for (auto it = sorted_rooms.lower_bound(start_nr); it != sorted_rooms.end() && it->first <= end_nr; ++it)
        {
            int cand_size = it->second;
            if (cand_size < room_size)
                continue;
            int cand_id = it->first;
            int cand_dist = abs(cand_id - room_id);
            if (currdist > cand_dist || (currdist == cand_dist && cand_id < res)) {
                res = cand_id;
                currdist = cand_dist;
            }
        }
    }

    void closestRoom(vector<int>& query) {
        int room_id = query[0], room_size = query[1];
        int segment_id = room_id / segsize;
        if (room_size <= localmax[segment_id])
            closestRoom(query, segment_id);
        for (int i = 0, found_round = -1, j = segment_id - 1, k = segment_id + 1;
             j >= 0 || k < segnr; ++i, --j, ++k) {
            if (j >= 0 && room_size <= localmax[j])
                closestRoom(query, j);
            if (k < segnr && localmax[k] >= room_size)
                closestRoom(query, k);
            if (res >= 0) {
                if (found_round < 0)
                    found_round = i;
                else if (i > found_round)
                    return;
            }
        }
    }

    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        memset(localmax, 0, nr_segments * sizeof(int));
        for (auto& room: rooms)
        {
            int room_id = room[0], room_size = room[1];
            int segindex = room_id / segsize;
            localmax[segindex] = max(localmax[segindex], room_size);
            sorted_rooms[room_id] = room_size;
        }
        int max_room_id = sorted_rooms.rbegin()->first;
        segnr = max_room_id / segsize + 1;

        vector<int> r;
        for (auto& query: queries)
        {
            res = -1, currdist = INT_MAX;
            closestRoom(query);
            r.push_back(res);
        }

        return r;
    }
};


int main() {
    Solution sol;

    return 0;
}
