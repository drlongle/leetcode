/*
388. Longest Absolute File Path

    Total Accepted: 5129
    Total Submissions: 17107
    Difficulty: Medium

Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext

The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext

The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

Note:

    The name of a file contains at least a . and an extension.
    The name of a directory or sub-directory will not contain a ..

Time complexity required: O(n) where n is the size of the input string.

Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
*/

#include <algorithm>
#include <array>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

struct Level_entry {
    Level_entry(Level_entry* parent, int namelen)
    {
        m_length = namelen + (parent ? parent->m_length + 1: 0);
    }

    int m_length;
};

class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0;
        size_t pos = 0, newpos;
        vector<string> parts;
        while (true) {
            newpos = input.find('\n', pos);
            if (newpos == string::npos) {
                parts.emplace_back(input.substr(pos));
                break;
            }
            parts.emplace_back(input.substr(pos, newpos-pos));
            pos = newpos + 1;
        }

        vector<vector<Level_entry*> > levels(1);
        for (string& p: parts) {
            size_t level = 0;
            while (level < p.size() && p[level] == '\t') {
                if (++level >= levels.size())
                    levels.emplace_back(vector<Level_entry*>());
            }
            Level_entry* entry = new Level_entry(level == 0 ? 0 :
                levels[level-1].back(), p.size() - level);
            levels[level].emplace_back(entry);
            size_t dotpos = p.find('.');
            if (dotpos != string::npos &&
                dotpos < p.size()-1 && entry->m_length > res)
                res = entry->m_length;
        }

        for (auto& one_level : levels)
            for (auto& p: one_level)
                delete p;

        return res;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    cout << "Result: " << sol.lengthLongestPath(input);

    return 0;
}

