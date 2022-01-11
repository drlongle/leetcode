/*
630. Course Schedule III
Hard

There are n different online courses numbered from 1 to n. You are given an array courses where
courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for
durationi days and must be finished before or on lastDayi.

You will start on the 1st day and you cannot take two or more courses simultaneously.

Return the maximum number of courses that you can take.

Example 1:
Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
Output: 3
Explanation:
There are totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day.
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day.
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.

Example 2:
Input: courses = [[1,2]]
Output: 1

Example 3:
Input: courses = [[3,2],[4,3]]
Output: 0

Constraints:
1 <= courses.length <= 10^4
1 <= durationi, lastDayi <= 10^4
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
#include "common/TreeNode.h"

using namespace std;

/*
 * Sort the courses to select the ones with the strictest deadline first.
 * Among the selected sources, create a max heap so that the course with the
 * longest duration is at the top. For any new course, either add it to the
 * taken course or check if it's possible to replace the course with the longest
 * duration.
 */

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        auto compare = [] (const vector<int>& c1, const vector<int>& c2){
            return c1[1] < c2[1] || (c1[0] < c2[0] && c1[1] == c2[1]);
        };

        sort(begin(courses), end(courses), compare);
        priority_queue<int> taken; // taken courses with the longest course on top (max heap)
        int day = 1;
        for (auto& course: courses) {
            int completed = day + course[0] - 1;
            if (completed <= course[1]) {
                taken.emplace(course[0]);
                day = completed + 1;
            } else if (taken.size()) {
                int diff = taken.top() - course[0];
                // If we can replace the longest taken course with a shorter one, we gain some time.
                if (diff > 0 && day - diff <= course[1]) {
                    taken.pop();
                    day -= diff;
                    taken.emplace(course[0]);
                }
            }
        }

        return taken.size();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> courses;

    // Output: 3
    courses = {{100,200},{200,1300},{1000,1250},{2000,3200}};
    cout << sol.scheduleCourse(courses) << endl;

    // Output: 1
    courses = {{1,2}};
    cout << sol.scheduleCourse(courses) << endl;

    // Output: 0
    courses = {{3,2},{4,3}};
    cout << sol.scheduleCourse(courses) << endl;

    // Output: 2
    courses = {{5,5},{4,6},{2,6}};
    cout << sol.scheduleCourse(courses) << endl;

    // Output: 5
    courses = {{5,15},{3,19},{6,7},{2,10},{5,16},{8,14},{10,11},{2,19}};
    cout << sol.scheduleCourse(courses) << endl;

    // Output: 4
    courses = {{7,17},{3,12},{10,20},{9,10},{5,20},{10,19},{4,18}};
    cout << sol.scheduleCourse(courses) << endl;

    return 0;
}
