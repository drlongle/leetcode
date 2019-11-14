/*
1239. Maximum Length of a Concatenated String with Unique Characters
Medium

Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which
have unique characters. Return the maximum possible length of s.

Example 1:
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.

Example 2:
Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".

Example 3:
Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
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

    int count(vector<string>& arr, int pos, bitset<26> taken) {
        if (pos == sz)
            return 0;
        int r1 = count(arr, pos+1, taken);
        bool valid = true;
        string& word = arr[pos];
        for (char ch: word) {
            int idx = ch - 'a';
            if (taken.test(idx)) {
                valid = false;
                break;
            } else
                taken.set(idx);
        }
        if (valid)
            return max(r1, static_cast<int>(word.size()) + count(arr, pos+1, taken));
        else
            return r1;
    }
    
    int maxLength(vector<string>& arr) {
        sz = arr.size();
        return count(arr, 0, {});
    }

    int sz;
};

int main() {
    Solution sol;
    vector<string> arr;

    // Output: 4
    arr = {"un","iq","ue"};


    // Output: 6
    //arr = {"cha","r","act","ers"};


    //arr = {"abcdefghijklmnopqrstuvwxyz"};
    
    cout << sol.maxLength(arr) << endl;
    
    return 0;
}
