/*
1032. Stream of Characters
Hard

Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried
(in order from oldest to newest, including this letter just queried) spell one of the words in the given list.

Example:
StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist

Note:
1 <= words.length <= 2000
1 <= words[i].length <= 2000
Words will only consist of lowercase English letters.
Queries will only consist of lowercase English letters.
The number of queries is at most 40000.
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class StreamChecker {
public:
    struct Node {
        Node(): children(26), leaf(false) {}
        vector<unique_ptr<Node>> children;
        bool leaf;
    };

    Node root;
    string pattern;

    void insert(string& word) {
        Node* node = &root;
        for (char ch: word) {
            auto& next = node->children[ch - 'a'];
            if (next == nullptr)
                next = make_unique<Node>();
            node = next.get();
        }
        node->leaf = true;
    }

    bool search(string& word) {
        Node* node = &root;
        int sz = word.size();
        for (int i = sz-1; i >= 0; --i) {
            node = node->children[word[i] - 'a'].get();
            if (node == nullptr)
                return false;
            if (node->leaf)
                return true;
        }

        return false;
    }
    StreamChecker(vector<string>& words) {
        for (auto& word: words) {
            reverse(begin(word), end(word));
            insert(word);
        }
    }

    bool query(char letter) {
        pattern.push_back(letter);
        return search(pattern);
    }
};

void test_1()
{
    vector<string> words{"cd","f","kl"};
    StreamChecker streamChecker(words); // init the dictionary.
    cout << streamChecker.query('a') << endl;          // return false
    cout << streamChecker.query('b') << endl;          // return false
    cout << streamChecker.query('c') << endl;          // return false
    cout << streamChecker.query('d') << endl;          // return true, because 'cd' is in the wordlist
    cout << streamChecker.query('e') << endl;          // return false
    cout << streamChecker.query('f') << endl;          // return true, because 'f' is in the wordlist
    cout << streamChecker.query('g') << endl;          // return false
    cout << streamChecker.query('h') << endl;          // return false
    cout << streamChecker.query('i') << endl;          // return false
    cout << streamChecker.query('j') << endl;          // return false
    cout << streamChecker.query('k') << endl;          // return false
    cout << streamChecker.query('l') << endl;          // return true, because 'kl' is in the wordlist
}

int main() {
    test_1();

    return 0;
}
