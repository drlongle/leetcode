/*
1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
Easy

Given a sentence that consists of some words separated by a single space, and a searchWord.
You have to check if searchWord is a prefix of any word in sentence.
Return the index of the word in sentence where searchWord is a prefix of this word (1-indexed).

If searchWord is a prefix of more than one word, return the index of the first word (minimum index).
If there is no such word return -1. A prefix of a string S is any leading contiguous substring of S.

Example 1:
Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.

Example 2:
Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence,
but we return 2 as it's the minimal index.

Example 3:
Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.

Example 4:
Input: sentence = "i use triple pillow", searchWord = "pill"
Output: 4

Example 5:
Input: sentence = "hello from the other side", searchWord = "they"
Output: -1

Constraints:
1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence consists of lowercase English letters and spaces.
searchWord consists of lowercase English letters.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence);
        string word;
        int sz = searchWord.size(), i = 1;;
        while (getline(iss, word, ' '))  {
            if (word.compare(0, sz, searchWord) == 0)
                return i;
            ++i;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    string sentence, searchWord;

    sentence = "i love eating burger", searchWord = "burg";
    cout << sol.isPrefixOfWord(sentence, searchWord) << endl;
    
    return 0;
}
