/*
244. Shortest Word Distance II
Medium

Design a data structure that will be initialized with a string array, and then it should
answer queries of the shortest distance between two different strings from the array.

Implement the WordDistance class:

WordDistance(String[] wordsDict) initializes the object with the strings array wordsDict.
int shortest(String word1, String word2) returns the shortest distance between
word1 and word2 in the array wordsDict.

Example 1:
Input
["WordDistance", "shortest", "shortest"]
[[["practice", "makes", "perfect", "coding", "makes"]], ["coding", "practice"], ["makes", "coding"]]
Output
[null, 3, 1]

Explanation
WordDistance wordDistance = new WordDistance(["practice", "makes", "perfect", "coding", "makes"]);
wordDistance.shortest("coding", "practice"); // return 3
wordDistance.shortest("makes", "coding");    // return 1

Constraints:
1 <= wordsDict.length <= 3 * 104
1 <= wordsDict[i].length <= 10
wordsDict[i] consists of lowercase English letters.
word1 and word2 are in wordsDict.
word1 != word2
At most 5000 calls will be made to shortest.
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

class WordDistance {
public:
    WordDistance(vector<string>& dict) {
        for (int i=0, n=dict.size(); i<n; ++i) {
            tab[dict[i]].push_back(i);
        }
    }
    unordered_map <string, vector <int>> tab;

    int shortest(string w1, string w2) {
        auto& v1 = tab[w1];
        auto& v2 = tab[w2];
        size_t i = 0, j = 0;
        int res = INT_MAX;
        while (i < v1.size() && j < v2.size ()) {
            res = min(res, abs(v1[i]-v2[j]));
            if ((v1[i] < v2[j]&& i < v1.size()-1) || j+1==v2.size ())
                ++i;
            else
                ++j;
        }

        return res;
    }
};

int main() {
    return 0;
}
