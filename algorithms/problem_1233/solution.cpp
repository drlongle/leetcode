/*
1233. Remove Sub-Folders from the Filesystem
Medium

Given a list of folders, remove all sub-folders in those folders and return in
any order the folders after removing.

If a folder[i] is located within another folder[j], it is called a sub-folder of it.

The format of a path is one or more concatenated strings of the form: / followed by one or more
lowercase English letters. For example, /leetcode and /leetcode/problems are valid paths while
an empty string and / are not. 

Example 1:
Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
Output: ["/a","/c/d","/c/f"]
Explanation: Folders "/a/b/" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d"
in our filesystem.

Example 2:
Input: folder = ["/a","/a/b/c","/a/b/d"]
Output: ["/a"]
Explanation: Folders "/a/b/c" and "/a/b/d/" will be removed because they are subfolders of "/a".

Example 3:
Input: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
Output: ["/a/b/c","/a/b/ca","/a/b/d"]
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

class Solution {
public:
    struct Node {
        Node(): valid(false) {}
        bool valid;
        map<string, Node> children;
    };

    void collect(Node* node, vector<string>& path, vector<string>& res) {
        if (node->valid) {
            ostringstream oss;
            for (auto& s: path) {
                oss << "/" << s;
            }
            res.emplace_back(oss.str());
        } else {
            for (auto& p: node->children) {
                string s = p.first;
                path.emplace_back(s);
                collect(&node->children[s], path, res);
                path.pop_back();
            }
        }
    }
    
    vector<string> removeSubfolders(vector<string>& folders) {
        vector<string> res;
        Node root;
        for (auto& dir: folders) {
            istringstream iss(dir);
            string subdir;
            Node* node = &root;
            while (getline(iss, subdir, '/')) {
                if (subdir.empty())
                    continue;
                //cout << dir << " --> " << subdir << endl;
                node = &(node->children[subdir]);
            }
            node->valid = true;
        }
        vector<string> path;
        collect(&root, path, res);
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> folders;

    // Output: {"/a","/c/d","/c/f"}
    folders = {"/a","/a/b","/c/d","/c/d/e","/c/f"};

    // Output: {"/a"}
    //folders = {"/a","/a/b/c","/a/b/d"};

    // Output: {"/a/b/c","/a/b/ca","/a/b/d"}
    //folders = {"/a/b/c","/a/b/ca","/a/b/d"};

    auto res = sol.removeSubfolders(folders);

    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;
    
    return 0;
}
