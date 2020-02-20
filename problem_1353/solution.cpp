/*
Maximum Number of Events That Can Be Attended
Medium

Given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. Notice that you can only attend one event at any time d.

Return the maximum number of events you can attend.

Example 1:
Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.

Example 2:
Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4

Example 3:
Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
Output: 4

Example 4:
Input: events = [[1,100000]]
Output: 1

Example 5:
Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
Output: 7

Constraints:
1 <= events.length <= 10^5
events[i].length == 2
1 <= events[i][0] <= events[i][1] <= 10^5
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
    struct Point {
        Point(int v, int i, bool o): value(v), index(i), open(o) {}
        int value;
        int index;
        bool open;
    };

    void delete_index(multimap<int, int>& opens, int index) {
        for (auto it = opens.begin(); it != opens.end(); ++it) {
            if (it->second == index) {
                opens.erase(it);
                break;
            }
        }
    }
    
    int maxEvents(vector<vector<int>>& events) {
        vector<Point> points;
        int sz = events.size();
        for (int i = 0; i < sz; ++i) {
            points.emplace_back(events[i][0], i, true);
            points.emplace_back(events[i][1], i, false);
        }
        auto lambda = [&](auto& a, auto& b) {return a.value < b.value || (a.value == b.value && a.open && events[a.index][1] <= events[b.index][1]);};
        multimap<int, int> opens;
        unordered_set<int> counted;
        sort(begin(points), end(points), lambda);

        int index, curr = points[0].value;
        for (auto& point: points) {
            if (point.open) {
                int distance = point.value - curr + 1;
                while (opens.size() && distance > 0) {
                    index = opens.begin()->second;
                    if (curr <= events[index][1] &&
                        (curr < events[point.index][0] || events[index][1] < events[point.index][1])) {
                        counted.emplace(index);
                        opens.erase(opens.begin());
                        --distance;
                        ++curr;
                    } else
                        break;
                }
                curr = max(curr, events[point.index][0]);
                if (curr == events[point.index][0] && curr == events[point.index][1]) {
                    counted.emplace(point.index);
                    ++curr;
                } else
                    opens.insert({events[point.index][0], point.index});
            } else {
                index = point.index;
                if (events[index][1] >= curr) {
                    if (counted.count(index) == 0) {
                        counted.emplace(index);
                        delete_index(opens, index);
                        ++curr;
                    }
                } else {
                    delete_index(opens, index);
                }
            }
        }

        return counted.size();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> events;

    // Output: 3
    events = {{1,2},{2,3},{3,4}};

    // Output: 4
    //events = {{1,2},{2,3},{3,4},{1,2}};

    // Output: 4
    //events = {{1,4},{4,4},{2,2},{3,4},{1,1}};

    // Output: 1
    //events = {{1,100000}};

    // Output: 7
    //events = {{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7}};

    // Output: 5
    //events = {{1,2},{1,2},{3,3},{1,5},{1,5}};

    // Output: 5
    //events = {{1,5},{1,5},{1,5},{2,3},{2,3}};

    // Output: 2
    //events = {{1,10},{2,2},{2,2},{2,2},{2,2}};

    // Output: 4
    //events = {{1,3},{1,3},{1,3},{3,4}};

    // Output: 14
    //events = {{26,27},{24,26},{1,4},{1,2},{3,6},{2,6},{9,13},{6,6},{25,27},{22,25},{20,24},{8,8},{27,27},{30,32}};
    
    // Output: 18
    //events = {{27,27},{8,10},{9,11},{20,21},{25,29},{17,20},{12,12},{12,12},{10,14},{7,7},{6,10},{7,7},{4,8},{30,31},{23,25},{4,6},{17,17},{13,14},{6,9},{13,14}};

    // Output: 19
    events = {{25,26},{19,19},{9,13},{16,17},{17,18},{20,21},{22,25},{11,12},{19,23},{7,9},{1,1},{21,23},{14,14},{4,7},{16,16},{24,28},{16,18},{4,5},{18,20},{16,16},{25,26}};
    
    cout << sol.maxEvents(events) << endl;
        
    return 0;
}
