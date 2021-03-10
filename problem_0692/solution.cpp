/*
692. Top K Frequent Words
Medium

Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have
the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
with the number of occurrence being 4, 3, 2 and 1 respectively.

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.

Follow up: Try to solve it in O(n log k) time and O(n) extra space.
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
    struct Entry {
        Entry(const string& w, int c): word(w), cnt(c) {}
        bool operator<(const Entry& other) const {
            return cnt < other.cnt || (cnt == other.cnt && word > other.word);
        }
        string word;
        int cnt;
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> lookup;
        set<Entry> heap;

        for (auto& word: words) {
            ++lookup[word];
        }

        for (auto& [word, cnt]: lookup) {
            heap.emplace(word, cnt);
            if (heap.size() > k) {
                heap.erase(heap.begin());
            }
        }

        vector<string> res;
        for (auto it = heap.rbegin(); it != heap.rend(); ++it)
            res.emplace_back(it->word);

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words;
    int k;

    // Output: {"i", "love"}
    words = {"i", "love", "leetcode", "i", "love", "coding"}, k = 2;
    words = sol.topKFrequent(words, k);
    copy(begin(words), end(words), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // Output: {"the", "is", "sunny", "day"}
    words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"}, k = 4;
    words = sol.topKFrequent(words, k);
    copy(begin(words), end(words), ostream_iterator<string>(cout, ", "));
    cout << endl;

    return 0;
}
