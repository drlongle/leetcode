/*
648. Replace Words
Medium

In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000
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
#include <memory>
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
    struct Node {
        string word;
        unordered_map<char, unique_ptr<Node>> children;
    };
    
    struct Node root;

    void insert(const string& word) {
        int sz = word.size();
        Node* node = &root;
        for (int i = 0; i < sz; ++i) {
            char ch = word[i];
            if (node->children.count(ch) == 0) {
                node->children[ch] = make_unique<Node>();
            }
            node = node->children[ch].get();
        }
        node->word = word;
    }

    string get_root(const string& word) {
        int sz = word.size();
        Node* node = &root;
        for (int i = 0; i < sz; ++i) {
            if (node->children.empty())
                return node->word;
            auto it = node->children.find(word[i]);
            if (it == node->children.end() || !node->word.empty())
                return node->word;
            node = it->second.get();
        }
        return "";
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        istringstream iss(sentence);
        ostringstream oss;

        for (auto& word: dict) {
            insert(word);
        }
        
        string word;
        bool first_word = true;
        while (getline(iss, word, ' ')) {

            if (!first_word)
                oss << " ";
            first_word = false;
            auto root_word = get_root(word);
            if (root_word.empty())
                oss << word;
            else
                oss << root_word;
        }

        return oss.str();
    }
};

int main() {
    Solution sol;
    vector<string> dict;
    string sentence;
    
    dict = {"cat", "bat", "rat"};
    sentence = "the cattle was rattled by the battery";
    cout << sol.replaceWords(dict, sentence) << endl;

    // Expected: "a a a a a a a a bbb baba a"
    dict = {"a", "aa", "aaa", "aaaa"};
    sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
    cout << sol.replaceWords(dict, sentence) << endl;
    
    return 0;
}
