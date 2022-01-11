/*
953. Verifying an Alien Dictionary
Easy

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

Example 1:
Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

Example 2:
Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

Example 3:
Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.
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
    unordered_map<char, int> ord;
    bool less_than_or_equal_to(string& s1, string &s2) {
        int sz1 = s1.size(), sz2 = s2.size(), sz = max(sz1, sz2);
        for(int i = 0; i < sz; ++i) {
            if (i >= sz1)
                return true;
            if (i >= sz2)
                return false;
            int od1 = ord[s1[i]], od2 = ord[s2[i]];
            if (od1 > od2)
                return false;
            else if (od1 < od2)
                return true;
        }

        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int osz = order.size();
        for (int i = 0; i < osz; ++i)
            ord[order[i]] = i;
        int wsz = words.size();
        for (int i = 0; i < wsz-1; ++i)
            if (!less_than_or_equal_to(words[i], words[i+1]))
                return false;
        return true;
    }
};

int main() {
    Solution sol;
    vector<string> words;
    string order;

    // Output: true
    words = {"hello","leetcode"}, order = "hlabcdefgijkmnopqrstuvwxyz";

    // Output: false
    words = {"word","world","row"}, order = "worldabcefghijkmnpqstuvxyz";

    // Output: false
    words = {"apple","app"}, order = "abcdefghijklmnopqrstuvwxyz";

    words = {"apple","apple1"}, order = "abcdefghijklmnopqrstuvwxyz";
    
    cout << sol.isAlienSorted(words, order) << endl;
    return 0;
}
