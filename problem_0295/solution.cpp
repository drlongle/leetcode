/*
295. Find Median from Data Stream  
Total Accepted: 14786 Total Submissions: 67257 Difficulty: Hard

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
Examples:

[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:
    void addNum(int num) - Add a integer number from the data stream to the data structure.
    double findMedian() - Return the median of all elements so far.

For example:
add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2
*/

#include <algorithm>
#include <cassert>
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
    // Adds a number into the data structure.
    void addNum(int num) {
        if (bottom.size() > 0 && bottom.top() < num)
            top.emplace(num);
        else
            bottom.emplace(num);
        if (top.size() > bottom.size()) {
            bottom.emplace(top.top());
            top.pop();
        }
        else if (bottom.size() > top.size() + 1) {
            top.emplace(bottom.top());
            bottom.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (top.size() != bottom.size())
            return bottom.top();
        else
            return static_cast<double>(top.top() + bottom.top()) / 2;
    }
    
    void print() {
        cout << "Top heap: " << endl;
        while (top.size()) {
            cout << top.top() << endl;
            top.pop();
        }
        cout << "Bottom heap: " << endl;
        while (bottom.size()) {
            cout << bottom.top() << endl;
            bottom.pop();
        }
    }

    priority_queue<int, vector<int>, greater<int> > top;
    priority_queue<int, vector<int>, less<int> > bottom;
};

int main()
{
    Solution sol;
    sol.addNum(21);
    sol.addNum(3);
    sol.addNum(12);
    sol.addNum(9);
    sol.addNum(16);
    sol.print();

    return 0;
}

