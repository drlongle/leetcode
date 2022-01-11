/*
1178. Number of Valid Words for Each Puzzle
Hard

With respect to a given puzzle string, a word is valid if both the following conditions are satisfied:
word contains the first letter of puzzle.
For each letter in word, that letter is in puzzle.
For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage"; while invalid words are
"beefed" (doesn't include "a") and "based" (includes "s" which isn't in the puzzle). Return an array answer, where
answer[i] is the number of words in the given word list words that are valid with respect to the puzzle puzzles[i].

Example :
Input:
words = ["aaaa","asas","able","ability","actt","actor","access"],
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
Output: [1,1,3,2,4,0]
Explanation:
1 valid word for "aboveyz" : "aaaa"
1 valid word for "abrodyz" : "aaaa"
3 valid words for "abslute" : "aaaa", "asas", "able"
2 valid words for "absoryz" : "aaaa", "asas"
4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
There're no valid words for "gaswxyz" cause none of the words in the list contains letter 'g'.
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

/*

* Intuition

First of all, notice that for each word, the ordering and the count of elements does not matter. So, we can keep all our
words in a sorted order and avoid the duplicate letters. This makes the maximum size of the word to be 26 (instead of
50).

Further, notice that the ordering of words in the puzzle doesn't matter. We just need to keep track of the first letter
of the puzzle. So, we can also keep our puzzle in sorted manner.

Let us define a trie on the set of words. The bool isEndOfWord field has been modified to store the number of words
ending at that node.

Insertion in the trie is trivial, just follow the normal procedure for insertion, and in the end, increase the count of
words ending at the last node by 1.

For any puzzle, we willl traverse the tree and get the answer. Observe that we only need to go 7 levels deep.

We explore all the 7 possibilities. As soon as we see the first element, we can keep incrementing the count from this
node onwards.

If we don't see the first element, we keep going down without changing count.

* Time Complexity Analysis

At the first level, we have 7 choices, but at the next level, we only have 6 choice, and the next 5, and so on, This
gives us an upper bound od 7 * 6 * ....1 = 7!, for each query. The overall complexity becomes O(query_length * 7!),
which is on the border but would hopefully pass.

Is the bound asymptotically tight?
If we think about it in big O notation, the derivation is correct. But to make the bounds tighter, let's use the theta
notation and amortized analysis,

Lowering the upper bound
Notice that we can only go 7 levels deep. So, the answer can lie in either or all of this levels.

How many answers lie in the first level ? Clearly, in the worst case, it is 7C1 , as selecting any 1 would give us an
answer.

How many answers lie in the second level? Clearly, selecting any 2 elements out of the 7 would give us an answer (since
any 2 elements from the set can have only 1 sorted order, hence we need to just select elements instead of permuting
them). So, the answer at the second level is 7C2

Similarly, how many at the third level? Clearly, we can select 3 elements out of the 7, and it would give us a unique
answer. Therefore, at the third level. we have 7C3.

.
.
.

At the 7th level, we have 7C7 = 1 answer (as there is only one way to reach the 7th level as everything has to be
sorted). In conclusion, the maximum nodes we would have to visit is 7C1 + ... 7C7 = 2^7 - 1 = 127.

So, the worst case traversal would be of the order of 10 ^ 2. So, the overall complexity is O(100 * queries_length).

[Even if you include the hidden constant factors, it won't go beyond 100 * queries_length
*/

struct Node {
    Node() : count(0)
    {
    }
    map<char, Node*> children;
    int count;
};

class Solution {
public:
    void insert(const string& word, Node* node)
    {
        for (size_t i = 0; i < word.size(); ++i) {
            char ch = word[i];
            auto it = node->children.find(ch);
            if (it != node->children.end())
                node = it->second;
            else {
                Node* new_node = new Node();
                node->children[ch] = new_node;
                node = new_node;
            }
        }
        ++node->count;
    }

    int search(const string& puzzle, Node* node, char first_char, bool seen_char)
    {
        if (!node)
            return 0;
        int count = seen_char ? node->count : 0;
        for (size_t i = 0; i < puzzle.size(); ++i) {
            char ch = puzzle[i];
            if (ch == first_char)
                count += search(puzzle, node->children[ch], first_char, true);
            else
                count += search(puzzle, node->children[ch], first_char, seen_char);
        }
        return count;
    }

    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
    {
        Node root;

        for (auto& word : words) {
            set<char> chars(begin(word), end(word));
            string str(begin(chars), end(chars));
            insert(str, &root);
        }

        vector<int> res;
        for (auto& puzzle : puzzles) {
            res.emplace_back(search(puzzle, &root, puzzle[0], false));
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> words, puzzles;

    // Output: [1,1,3,2,4,0]
    words = {"aaaa", "asas", "able", "ability", "actt", "actor", "access"};
    puzzles = {"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"};

    auto res = sol.findNumOfValidWords(words, puzzles);

    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
