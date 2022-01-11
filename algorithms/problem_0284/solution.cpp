/*
284. Peeking Iterator
Total Accepted: 21421 Total Submissions: 63381 Difficulty: Medium

Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().

Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].

Call next() gets you 1, the first element in the list.

Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.

You call next() the final time and it returns 3, the last element. Calling hasNext() after that should return false.

Hint:
  Think of "looking ahead". You want to cache the next element.
  Is one variable sufficient? Why or why not?
  Test your design with call order of peek() before next() vs next() before peek().
  For a clean implementation, check out Google's guava library source code. 

Follow up: How would you extend your design to be generic and work with all types, not just integer?
*/

#include <algorithm>
#include <array>
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

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;

public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        m_valid = false;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!m_valid)
        {
            m_value = Iterator::next();
            m_valid = true;
        }
        return m_value;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (m_valid)
        {
            m_valid = false;
            return m_value;
        }
        else
            return Iterator::next();
    }

    bool hasNext() const {
        return m_valid || Iterator::hasNext(); 
    }

    int m_value;
    bool m_valid;
};

int main()
{
  // 0: hasNext
  // 1: peek
  // 2: next

  /*
  Input: [1,2,3,4]
  [0,1,1,2,2,1,1,2,0,1,0,2,0]
  Output:   ["true","1","1","1","2","1","1","3","true","1","true","4","false"]
  Expected: ["true","1","1","1","2","3","3","3","true","4","true","4","false"] 
  */

  return 0;
}

