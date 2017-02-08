/*
335. Self Crossing  
Total Accepted: 4913 Total Submissions: 26116 Difficulty: Hard

You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.

Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.

Example 1:

Given x = [2, 1, 1, 2],
Return true (self crossing)

Example 2:
Given x = [1, 2, 3, 4],
Return false (not self crossing)

Example 3:
Given x = [1, 1, 1, 1],
Return true (self crossing)

*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;



class Solution {
public:
  bool isSelfCrossing(vector<int>& x) {
    int prev = 0;
    int xmin = 0, xmax = 0;
    int ymin = 0, ymax = 0;
    for (size_t i = 0; i < x.size(); ++i) {
      int curr = x[i];

      prev = curr;
    }

    return false;
  }
};

int main()
{
  Solution sol;
  vector<int> x;

  //Expected: true
  x = {2, 1, 1, 2};

  //Expected: false
  x = {1, 2, 3, 4};

  //Expected: true
  x = {1, 1, 1, 1};

  cout << "Result: " << sol.isSelfCrossing(x) << endl;

  return 0;
}

