/*
1286. Iterator for Combination
Medium

Design an Iterator class, which has:
* A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
* A function next() that returns the next combination of length combinationLength in lexicographical order.
* A function hasNext() that returns True if and only if there exists a next combination.

Example:
CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.
iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false

Constraints:
1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength): length(combinationLength), index(length) {
        iota(begin(index), end(index), 0);
        sz = characters.size();
        chars = characters;
    }

    void update_index() {
        do {
            if (index.back() < sz-1) {
                ++index.back();
                while (index.size() < length && index.back() < sz-1)
                    index.emplace_back(index.back()+1);
            } else
                index.pop_back();
        } while (index.size() != length && index.size() > 0);
    }
    
    string next() {
        ostringstream oss;
        for (int i: index)
            oss << chars[i];
        update_index();
        return oss.str();
    }
    
    bool hasNext() {
        if (index.size() != length)
            return false;
        return true;
    }
    size_t sz, length;
    vector<size_t> index;
    string chars;
};

void test1() {
    CombinationIterator iterator = CombinationIterator("abc", 2);
    cout << iterator.next() << endl;; // returns "ab"
    cout << iterator.hasNext() << endl; // returns true
    cout << iterator.next() << endl; // returns "ac"
    cout << iterator.hasNext() << endl; // returns true
    cout << iterator.next() << endl; // returns "bc"
    cout << iterator.hasNext() << endl; // returns false
}

void test2() {
    CombinationIterator iterator = CombinationIterator("bvwz", 2);
    cout << iterator.hasNext() << endl;
    cout << iterator.hasNext() << endl;
    cout << iterator.next() << endl;
    cout << iterator.next() << endl;
    cout << iterator.hasNext() << endl;
    cout << iterator.hasNext() << endl;
    cout << iterator.next() << endl;
    cout << iterator.hasNext() << endl;
    cout << iterator.hasNext() << endl;
    cout << iterator.hasNext() << endl;
    cout << iterator.next() << endl;
    cout << iterator.next() << endl;
    cout << iterator.hasNext() << endl;
    cout << iterator.next() << endl;
    cout << iterator.hasNext() << endl;
    cout << iterator.next() << endl;
}

void test3() {
    CombinationIterator iterator = CombinationIterator("fiklnuy", 3);

    for (int i = 0; i < 30; ++i)
        cout << iterator.next() << endl;
}


int main() {
    //test1();
    test2();
    //test3();
    return 0;
}
