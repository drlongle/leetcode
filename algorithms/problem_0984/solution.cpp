/*
Problem 984. String Without AAA or BBB
Difficulty: Easy

Given two integers A and B, return any string S such that:
S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;
The substring 'aaa' does not occur in S;
The substring 'bbb' does not occur in S.

Example 1:
Input: A = 1, B = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.

Example 2:
Input: A = 4, B = 1
Output: "aabaa"

Note:
0 <= A <= 100
0 <= B <= 100
It is guaranteed such an S exists for the given A and B.
*/

#include <algorithm>
#include <bitset>
#include <cassert>
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
    string strWithout3a3b(int A, int B) {
        ostringstream oss;
        char last = ' ';
        while (A > 0 || B > 0) {
            int a, b;
            if (A > B) {
                a = min(A, 2), b = min(B, 1);
            } else if (A == B)  {
                a = b = min(A, 2);
            } else {
                a = min(A, 1), b = min(B, 2);
            }
            A -= a;
            B -= b;
            bool a_first;
            if (last == ' ') {
                a_first = (a > b);
            } else {
                a_first = (last == 'b');
            }
            while (a > 0 || b > 0) {
                if (a > 0 && a_first) {
                    last = 'a';
                    --a;
                } else if (b > 0) {
                    last = 'b';
                    --b;
                } else if (a > 0) {
                    last = 'a';
                    --a;
                }
                oss << last;
            }
        }
        
        return oss.str();
    }
};

int main(int argc, char** argv) {
    Solution sol;
    int A, B;
    
    A = 1, B = 2;
    A = 4, B = 1;
    cout << "Result: " << sol.strWithout3a3b(A, B) << endl;

    return 0;
}
