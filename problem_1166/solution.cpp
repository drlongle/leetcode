/*
1166. Design File System
Difficulty: Medium

You are asked to design a file system which provides two functions:

create(path, value): Creates a new path and associates a value to it if possible and returns True. Returns False if the path already exists or its parent path doesn't exist.

get(path): Returns the value associated with a path or returns -1 if the path doesn't exist.
The format of a path is one or more concatenated strings of the form: / followed by one or more lowercase English letters. For example, /leetcode and /leetcode/problems are valid paths while an empty string and / are not.

Implement the two functions.

Please refer to the examples for clarifications.

Example 1:
Input: 
["FileSystem","create","get"]
[[],["/a",1],["/a"]]
Output: 
[null,true,1]
Explanation: 
FileSystem fileSystem = new FileSystem();
fileSystem.create("/a", 1); // return true
fileSystem.get("/a"); // return 1

Example 2:
Input: 
["FileSystem","create","create","get","create","get"]
[[],["/leet",1],["/leet/code",2],["/leet/code"],["/c/d",1],["/c"]]
Output: 
[null,true,true,2,false,-1]
Explanation: 
FileSystem fileSystem = new FileSystem();

fileSystem.create("/leet", 1); // return true
fileSystem.create("/leet/code", 2); // return true
fileSystem.get("/leet/code"); // return 2
fileSystem.create("/c/d", 1); // return false because the parent path "/c" doesn't exist.
fileSystem.get("/c"); // return -1 because this path doesn't exist.
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

struct Node {
    Node(int v=-1): val(v) {}
    int val;
    map<string, Node> children;
};

class FileSystem {
public:
    FileSystem(): root(0) {
        
    }
    
    bool create(string path, int value) {
        string s;
        stringstream ss(path);
        getline(ss, s, '/');
        Node *node = &root;
        while (getline(ss, s, '/')) {
            if (node->val < 0)
                return false;
            node = &(node->children[s]);
        }
        if (node->val >= 0)
            return false;
        node->val = value;
        
        return true;
    }
    
    int get(string path) {
        string s;
        stringstream ss(path);
        getline(ss, s, '/');
        Node *node = &root;
        while (getline(ss, s, '/')) {
            node = &(node->children[s]);
            if (node->val < 0)
                return -1;
        }

        return node->val;
    }
    
    Node root;
};

void test_1() {
    FileSystem fs;
    cout << "Create: " << boolalpha << fs.create("/a", 1) << endl;
    cout << "Get: " << fs.get("/a") << endl;
}

// [[],["/leet",1],["/leet/code",2],["/leet/code"],["/c/d",1],["/c"]]
void test_2() {
    FileSystem fs;
    cout << boolalpha << "Create: " << fs.create("/leet", 1) << endl;
    cout << boolalpha << "Create: " << fs.create("/leet/code", 2) << endl;
    cout << "Get: " << fs.get("/leet/code") << endl;
    cout << boolalpha << "Create: " << fs.create("/c/d", 1) << endl;
    cout << "Get: " << fs.get("/c") << endl;
}

int main() {
    //test_1();
    test_2();
    return 0;
}
