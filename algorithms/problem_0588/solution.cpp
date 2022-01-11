/*
588. Design In-Memory File System
Hard

Design a data structure that simulates an in-memory file system.

Implement the FileSystem class:

- FileSystem() Initializes the object of the system.
- List<String> ls(String path)
  If path is a file path, returns a list that only contains this file's name.
  If path is a directory path, returns the list of file and directory names in this directory.
  The answer should in lexicographic order.
- void mkdir(String path) Makes a new directory according to the given path. The given directory path does not exist.
  If the middle directories in the path do not exist, you should create them as well.
- void addContentToFile(String filePath, String content)
  If filePath does not exist, creates that file containing given content.
  If filePath already exists, appends the given content to original content.
- String readContentFromFile(String filePath) Returns the content in the file at filePath.

Example 1:
Input
["FileSystem", "ls", "mkdir", "addContentToFile", "ls", "readContentFromFile"]
[[], ["/"], ["/a/b/c"], ["/a/b/c/d", "hello"], ["/"], ["/a/b/c/d"]]
Output
[null, [], null, null, ["a"], "hello"]

Explanation
FileSystem fileSystem = new FileSystem();
fileSystem.ls("/");                         // return []
fileSystem.mkdir("/a/b/c");
fileSystem.addContentToFile("/a/b/c/d", "hello");
fileSystem.ls("/");                         // return ["a"]
fileSystem.readContentFromFile("/a/b/c/d"); // return "hello"

Constraints:
1 <= path.length, filePath.length <= 100
path and filePath are absolute paths which begin with '/' and do not end with '/' except that the path is just "/".
You can assume that all directory names and file names only contain lowercase letters, and the same names will not exist in the same directory.
You can assume that all operations will be passed valid parameters, and users will not attempt to retrieve file content or list a directory or file that does not exist.
1 <= content.length <= 50
At most 300 calls will be made to ls, mkdir, addContentToFile, and readContentFromFile.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class FileSystem {
public:

    struct Dir {
        unordered_map <string, string> files;
        map<string, Dir> dirs;
    };

    Dir root;

    vector<string> parse(string path) {
        vector <string> res;
        istringstream iss(path);
        string s;
        getline(iss, s, '/');
        while (getline(iss, s,'/'))
            res.push_back (s);

        return res;
    }


    vector<string> ls(string path) {
        auto dirs = parse(path);
        string last;
        if (dirs.size()) {
            last = dirs.back();
            dirs.pop_back();
        }
        auto node = &root;
        for (auto & dir: dirs) {
            node = &node->dirs[dir];
        }
        if (last.size() && node->files.count(last))
            return {last};
        if (last.size())
            node= &node->dirs[last];
        vector <string> res;
        for (auto& [dir, ignored] : node->dirs)
            res.push_back(dir);
        for(auto& [filename, ignored]: node->files)
            res.push_back(filename);
        sort(begin(res), end(res));
        return res;
    }

    void mkdir(string path) {
        auto dirs = parse(path);
        string last;
        if (dirs.size()) {
            last = dirs.back();
            dirs.pop_back();
        }
        auto node = &root;
        for (auto& dir: dirs)
            node = &node->dirs[dir];
        node->dirs.emplace(last, Dir());
    }

    void addContentToFile(string filePath, string content) {
        auto dirs = parse(filePath);
        string last = dirs.back();
        dirs.pop_back();
        auto node = &root;
        for(auto &dir: dirs)
            node = &node->dirs[dir];
        node->files[last] += content;
    }

    string readContentFromFile(string filePath) {
        auto dirs = parse(filePath);
        string last;
        if (dirs.size()) {
            last=dirs.back();
            dirs.pop_back();
        }
        auto node = &root;
        for (auto& dir: dirs)
            node = &node->dirs[dir];
        return node->files[last];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
int main() {
    return 0;
}
