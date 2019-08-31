/*
1170. Compare Strings by Frequency of the Smallest Character
Easy

Let's define a function f(s) over a non-empty string s, which calculates the frequency of
the smallest character in s. For example, if s = "dcce" then f(s) = 2 because the smallest
character is "c" and its frequency is 2.

Now, given string arrays queries and words, return an integer array answer, where each
answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words.

Example 1:
Input: queries = ["cbd"], words = ["zaaaz"]
Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").

Example 2:
Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa"). On the second query
both f("aaa") and f("aaaa") are both > f("cc").
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
    int lowest_frequency(const string& st)
    {
        map<char, int> counters;
        for (auto& ch : st)
            ++counters[ch];
        return counters.empty() ? 0 : begin(counters)->second;
    }

    int find_index(vector<int>& nums, int target)
    {
        int begin = 0;
        int end = nums.size() - 1;
        int res = -1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (nums[mid] <= target) {
                begin = mid + 1;
                res = mid;
            } else {
                end = mid - 1;
            }
        }
        return res;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words)
    {
        vector<int> res, wcount;

        int wsize = words.size();
        wcount.resize(wsize);
        for (int i = 0; i < wsize; ++i)
            wcount[i] = lowest_frequency(words[i]);
        sort(begin(wcount), end(wcount));

        int qsize = queries.size();
        res.resize(qsize);
        for (int i = 0; i < qsize; ++i) {
            int qcount = lowest_frequency(queries[i]);
            int index = find_index(wcount, qcount);
            res[i] = wsize - 1 - index;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> queries, words;
    vector<int> res;

    // Output: [1]
    queries = {"cbd"}, words = {"zaaaz"};

    // Output: [1,2]
    // queries = {"bbb","cc"}, words = {"a","aa","aaa","aaaa"};

    queries = {"aabbabbb", "abbbabaa", "aabbbabaa", "aabba", "abb", "a", "ba", "aa", "ba", "baabbbaaaa", "babaa",
            "bbbbabaa"};
    words = {"b", "aaaba", "aaaabba", "aa", "aabaabab", "aabbaaabbb", "ababb", "bbb", "aabbbabb", "aab", "bbaaababba",
            "baaaaa"};

    res = sol.numSmallerByFrequency(queries, words);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
