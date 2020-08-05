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

class WordDictionary {
public:
    /** Adds a word into the data structure. */
    void addWord(string word) {
        words.emplace_back(word);        
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        regex_replace(word, regex("\\."), "[[:lower:]]");
        regex reg(word);
        for (auto& w: words) {
            auto res = regex_match(w, reg);
            if (res)
                return true;
        }
        return false;
    }

    vector<string> words;
};

void test_1()
{
    WordDictionary dict;
    dict.addWord("bad");
    dict.addWord("dad");
    dict.addWord("mad");
    cout << dict.search("pad") << endl;
    cout << dict.search("bad") << endl;
    cout << dict.search(".ad") << endl;
    cout << dict.search("b..") << endl;
}

void test_2()
{
    WordDictionary dict;
    dict.addWord("at");
    dict.addWord("and");
    dict.addWord("an");
    dict.addWord("add");
    dict.addWord("a");
    cout << dict.search(".at") << endl;
}

int main() {
    //test_1();
    test_2();

    return 0;
}
