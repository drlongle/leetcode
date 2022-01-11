/*
341. Flatten Nested List Iterator  
Total Accepted: 4787 Total Submissions: 19035 Difficulty: Medium

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be
integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements
returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements
returned by next should be: [1,4,6]. 
*/

#include <algorithm>
#include <cassert>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger {
public:

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        m_list = nestedList; 
    }

    int next() {
        while (m_list.size() && !m_list.front().isInteger()) {
            vector<NestedInteger> newitems = m_list.front().getList();
            m_list.erase(m_list.begin());
            m_list.insert(m_list.begin(), newitems.begin(), newitems.end());
        }

        int result = m_list.front().getInteger();
        m_list.erase(m_list.begin());

        return result; 
    }

    bool hasNext() {
        while (m_list.size()) {
            NestedInteger ni = m_list.front();
            if (ni.isInteger()) return true;
            m_list.erase(m_list.begin());
            vector<NestedInteger> newitems = ni.getList();
            m_list.insert(m_list.begin(), newitems.begin(), newitems.end());
        }
        return false;
    }

    vector<NestedInteger> m_list;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main()
{
    return 0;
}

