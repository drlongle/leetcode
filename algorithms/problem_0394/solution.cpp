/*
394. Decode String
Difficulty: Medium

Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the
square brackets is being repeated exactly k times. Note that k is guaranteed to
be a positive integer.

You may assume that the input string is always valid; No extra white spaces,
square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits
and that digits are only for those repeat numbers, k. For example, there won't
be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

#include <algorithm>
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
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:    
    string decodeString(const string& s, int& index, int end) {
        ostringstream os;
        int count;
        while (index < end) {
            if (!isdigit(s[index]) && s[index] != '[' && s[index] != ']') {
                os << s[index++];
                continue;
            }
            count = 0;
            while (isdigit(s[index])) {
                count = count * 10 + s[index++] - '0';
            }
            int new_end = parens[index++];
            string temp = decodeString(s, index, new_end);
            while (count-- > 0) {
                os << temp;
            }
            index = new_end + 1;
        }
        
        return os.str();
    }
    
    string decodeString(const string& s) {
        int index = 0, end = s.size();
        stack<int> pos;
        for (int i = 0; i < end; ++i) {
            switch (s[i]) {
            case '[':
                pos.push(i);
                break;
            case ']':
                parens[pos.top()] = i;
                pos.pop();                
                break;
            }
        }
        
        return decodeString(s, index, end);
    }
    
    map<int, int> parens;
};

int main(int argc, char** argv) {
    Solution sol;
    string s;
    
    // Expected: "aaabcbc"
    s = "3[a]2[bc]";
    
    // Expected: "accaccacc"
    //s = "3[a2[c]]";
    
    // Expected: "abcabccdcdcdef"
    //s = "2[abc]3[cd]ef";
    
    cout << sol.decodeString(s) << endl;

    return 0;
}
