/*
677. Map Sum Pairs
Medium

Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
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
#include <memory>
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

class MapSum {
public:
    struct Node {
        unordered_map<char, unique_ptr<Node>> children;
        int val;
    };

    unordered_map<string, int> lookup;
    struct Node root;
    
    void insert(string key, int val) {
        int diff = val - lookup[key];
        lookup[key] = val;

        Node* node = &root;
        for (char ch: key) {
            Node* new_node = node->children[ch].get();
            if (new_node == nullptr) {
                node->children[ch] = make_unique<Node>();
                new_node = node->children[ch].get();
            }
            node = new_node;
            node->val += diff;
        }
    }
    
    int sum(string prefix) {
        if (prefix.empty())
            return 0;
        Node* node = &root;
        for (char ch: prefix) {
            node = node->children[ch].get();
            if (node == nullptr)
                return 0;
        }
        return node->val;
    }
};

void test_1() {
    MapSum mapsum;
    mapsum.insert("apple", 3);
    cout << mapsum.sum("ap") << endl;; // Output: 3
    mapsum.insert("app", 2);
    cout << mapsum.sum("ap") << endl;// Output: 5
}

int main() {
    test_1();
 
    return 0;
}
