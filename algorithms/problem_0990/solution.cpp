/*
990. Satisfiability of Equality Equations
Difficulty: Medium

Given an array equations of strings that represent relationships between
variables, each string equations[i] has length 4 and takes one of two
different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters
(not necessarily different) that represent one-letter variable names.

Return true if and only if it is possible to assign integers to
variable names so as to satisfy all the given equations.

Example 1:
Input: ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is
satisfied, but not the second.  There is no way to assign the variables to
satisfy both equations.

Example 2:
Input: ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

Example 3:
Input: ["a==b","b==c","a==c"]
Output: true

Example 4:
Input: ["a==b","b!=c","c==a"]
Output: false
Example 5:

Input: ["c==c","b==d","x!=z"]
Output: true

Note:
1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] and equations[i][3] are lowercase letters
equations[i][1] is either '=' or '!'
equations[i][2] is '='
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    map<char, char> equals;
    
    char get_root(char ch) {
        if (equals.find(ch) == equals.cend())
            equals[ch] = ch;
        char p;
        while (ch != (p = equals[ch])) {
            ch = p;
        }
        return ch;
    }
    
    void set_root(char ch, char root) {
        do {
            char p = equals[ch];
            equals[ch] = root;
            ch = p;
        } while (ch != root);
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        for (auto& eq: equations) {
            if (eq[1] == '=') {
                char a = eq[0];
                char b = eq[3];
                char root_a = get_root(a);
                char root_b = get_root(b);
                if (root_a < root_b) {
                    set_root(b, root_a);
                } else {
                    set_root(a, root_b);
                }
            }
        }
        for (auto& eq: equations) {
            if (eq[1] == '!') {
                char a = eq[0];
                char b = eq[3];
                if (get_root(a) == get_root(b)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<string> equations;
    
    // Expeted: false
    equations = {"a==b","b!=a"};
    
    // Expeted: false
    //equations = {"a==b","b==a"};
    
    // Expected: true
    //equations = {"a==b","b==c","a==c"};
    
    // Expeted: false
    //equations = {"a==b","b!=c","c==a"};
    
    // Expeted: true
    //equations = {"c==c","b==d","x!=z"};
    
    cout << "Result: " << boolalpha << sol.equationsPossible(equations) << endl;
    
    return 0;
}
