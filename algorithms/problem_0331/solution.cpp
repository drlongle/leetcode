/*
331. Verify Preorder Serialization of a Binary Tree
Total Accepted: 2991 Total Submissions: 9410 Difficulty: Medium

One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #

For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
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

#include <string.h>

using namespace std;

class Solution {
public:
    bool isValidSerialization(istringstream& iss) {
        string st;
        if (!getline(iss, st, ',')) return false;
        if (st == "#") return true;
        if (!isValidSerialization(iss)) return false;
        return isValidSerialization(iss);
    }

    bool isValidSerialization(string preorder) {
        istringstream iss(preorder);
        if (! isValidSerialization(iss)) return false;
        return iss.eof();
    }
};
int main()
{
    Solution sol;
    string st;

    // Expected: true
    st = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << "Result: " << sol.isValidSerialization(st) << endl;

    return 0;
}
