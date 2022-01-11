/*
385. Mini Parser

Difficulty:Medium
Total Accepted:22.3K
Total Submissions:72.2K

Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].
Example 1:

Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
Example 2:

Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.
*/

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class NestedInteger {
 public:
 // Constructor initializes an empty nested list.
 NestedInteger(): misInteger(false), intValue(numeric_limits<int>::min()) { }
 
 // Constructor initializes a single integer.
 NestedInteger(int value): misInteger(true), intValue(value) { }

 // Return true if this NestedInteger holds a single integer, rather than a nested list.
 bool isInteger() const { return misInteger; }
 
 // Return the single integer that this NestedInteger holds, if it holds a single integer
 // The result is undefined if this NestedInteger holds a nested list
 int getInteger() const {return intValue; }
 
 // Set this NestedInteger to hold a single integer.
 void setInteger(int value) { misInteger = true; intValue = value;}
 
 // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 void add(const NestedInteger &ni) { list.emplace_back(ni); misInteger = false;}
 
 // Return the nested list that this NestedInteger holds, if it holds a nested list
 // The result is undefined if this NestedInteger holds a single integer
 const vector<NestedInteger> &getList() const { return list; }

private:
 bool misInteger;
 int intValue;
 vector<NestedInteger> list;
};

int find(const string&s, string pattern, size_t& index)
{
    unordered_set<char> lookup(pattern.begin(), pattern.end());
    for (size_t i = index; i < s.size(); ++i) {
        if (lookup.find(s[i]) != lookup.end())
            return i;
    }
    return -1;
}

class Solution {
public:
    NestedInteger deserialize(string& s, size_t& index) {
        NestedInteger ni;
        if (s[index] != '[') {
            int pos = find(s, ",]", index);
            string substr;
            if (pos < 0) {
                substr = s.substr(index);
                index = string::npos;
            } else {
                substr = s.substr(index, pos-index);
                index = pos + (s[pos] == ',' ? 1 : 0);
            }
            if (substr.size())
                ni.setInteger(stoi(substr));
        } else {
            ++index;
            if (s[index] == ']') {
                ++index;
                if (index < s.size() && s[index] == ',')
                    ++index;
            } else {
                while (index < s.size()) {
                    NestedInteger child = deserialize(s, index);
                    ni.add(child);
                    if (index >= s.size() || s[index] == ']') {
                        ++index;
                        if (index < s.size() && s[index] == ',')
                            ++index;
                        break;
                    }
                }
            }
        }
        return ni;
    }

    NestedInteger deserialize(string s) {
        size_t index = 0;
        return deserialize(s, index);
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    string s;

    s = "324";

    s = "[123,[456,[789]]]";

    s = "[]";

    // Output:   [123,456,[788,799,833],[],[[]],[],10,[]]
    // Expected: [123,456,[788,799,833],[[]],10,[]]
    s = "[123,456,[788,799,833],[[]],10,[]]";

    // Output:   [[],[],[[[[]],-4],[[[]],[0],[[]]]]]
    // Expected: [[],[[[[]],-4],[[[]],[0],[[]]]]]
    s = "[[],[[[[]],-4],[[[]],[0],[[]]]]]";

    sol.deserialize(s);

    return 0;
}

