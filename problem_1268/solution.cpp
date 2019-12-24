/*
1268. Search Suggestions System
Medium

Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return list of lists of the suggested products after each character of searchWord is typed. 

Example 1:
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]

Example 2:
Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]

Example 3:
Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]

Example 4:
Input: products = ["havana"], searchWord = "tatiana"
Output: [[],[],[],[],[],[],[]]

Constraints:

1 <= products.length <= 1000
There are no repeated elements in products.
1 <= Σ products[i].length <= 2 * 10^4
All characters of products[i] are lower-case English letters.
1 <= searchWord.length <= 1000
All characters of searchWord are lower-case English letters.
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

struct Node {
    set<string> words;
    map<char, Node> children;
};

class Solution {
public:

    void insert(Node& node, string& word, size_t index) {
        node.words.emplace(word);
        if (node.words.size() > 3)
            node.words.erase(*node.words.rbegin());

        if (index +1 == word.size())
            return;
        Node& child = node.children[word[index+1]];
        insert(child, word, index+1);
    }

    vector<string> search(Node& node, string word, size_t index) {
        if (index == word.size()-1)
            return vector<string>(begin(node.words), end(node.words));
        auto it = node.children.find(word[index+1]);
        if (it == end(node.children))
            return {};
        return search(it->second, word, index+1);
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        Node root;
        for (auto& prod: products)
            insert(root.children[prod[0]], prod, 0);
        int n = searchWord.size();
        char ch = searchWord[0];
        for (int i = 0; i < n; ++i)
            res.emplace_back(search(root.children[ch], searchWord.substr(0, i+1), 0));

        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
