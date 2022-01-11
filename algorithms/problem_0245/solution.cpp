/*
245. Shortest Word Distance III
Medium

Given an array of strings wordsDict and two strings that already exist in the array
word1 and word2, return the shortest distance between these two words in the list.

Note that word1 and word2 may be the same. It is guaranteed
that they represent two individual words in the list.

Example 1:
Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
Output: 1

Example 2:
Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "makes"
Output: 3

Constraints:
1 <= wordsDict.length <= 3 * 10^4
1 <= wordsDict[i].length <= 10
wordsDict[i] consists of lowercase English letters.
word1 and word2 are in wordsDict.
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& dict, string w1, string w2) {
        vector <int> v1, v2;
        for  (int i =0, n=dict.size (); i<n; ++i) {
            auto& w = dict[i];
            if(w == w1)
                v1.push_back (i);
            if(w == w2)
                v2.push_back (i);
        }
        int res = INT_MAX;
        if (w1 == w2) {
            for (int i = 0, n = v1.size(); i < n-1; ++i)
                res = min(res,v1[i+1]-v1[i]);
            return res;
        }
        size_t i1 = 0, i2 = 0, n1 = v1.size(), n2 = v2.size();
        while (i1<n1&&i2<n2) {
            res=min(res,abs(v1[i1]-v2[i2]));
            if (i2==n2-1 || (i1<n1-1 &&v1[i1]<v2[i2]))
                ++i1;
            else ++i2;
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
