/*
1700. Number of Students Unable to Eat Lunch
Easy

The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1
respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed
in a stack. At each step:
- If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it
  and leave the queue.
- Otherwise, they will leave it and go to the queue's end.

This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of
the i-th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference
of the j-th student in the initial queue (j = 0 is the front of the queue).
Return the number of students that are unable to eat.

Example 1:
Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
Output: 0
Explanation:
- Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
- Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
- Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
- Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
- Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
Hence all students are able to eat.

Example 2:
Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
Output: 3

Constraints:
1 <= students.length, sandwiches.length <= 100
students.length == sandwiches.length
sandwiches[i] is 0 or 1.
students[i] is 0 or 1.
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

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> student_type(2, 0);
        queue<int> demand, supply;
        int n = students.size();
        for (int i = 0; i < n; ++i) {
            demand.push(students[i]);
            supply.push(sandwiches[i]);
            ++student_type[students[i]];
        }

        while (supply.size()) {
            if (student_type[supply.front()] == 0)
                return demand.size();
            if (demand.front() == supply.front()) {
                --student_type[supply.front()];
                demand.pop(), supply.pop();
            } else {
                demand.push(demand.front());
                demand.pop();
            }
        }

        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> students, sandwiches;

    // Output: 0
    students = {1,1,0,0}, sandwiches = {0,1,0,1};
    cout << sol.countStudents(students, sandwiches) << endl;

    // Output: 3
    students = {1,1,1,0,0,1}, sandwiches = {1,0,0,0,1,1};
    cout << sol.countStudents(students, sandwiches) << endl;

    return 0;
}
