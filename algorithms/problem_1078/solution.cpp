/*
1078. Occurrences After Bigram
Easy

Given words first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.

For each such occurrence, add "third" to the answer, and return the answer.

Example 1:

Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]

Example 2:
Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]

Note:
1 <= text.length <= 1000
text consists of space separated words, where each word consists of lowercase English letters.
1 <= first.length, second.length <= 10
first and second consist of lowercase English letters.
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
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        string pattern = first + " " + second + " ";
        size_t index = 0;
        while (true) {
            index = text.find(pattern, index);
            if (index == string::npos)
                break;
            if (index == 0 || text[index-1] == ' ') {
                size_t index2 = index + pattern.size();
                if (index2 >= text.size())
                    break;
                size_t index3 = text.find(' ', index2);
                if (index3 != string::npos)
                    res.emplace_back(text.substr(index2, index3 - index2));
                else
                    res.emplace_back(text.substr(index2));
            }
            index += first.size() + 1;
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    string text, first, second;

    // Output: ["girl","student"]
    text = "alice is a good girl she is a good student", first = "a", second = "good";

    // Output: ["we","rock"]
    text = "we will we will rock you", first = "we", second = "will";

    // Output: ["student"]
    //text = "alice is aa good girl she is a good student", first = "a", second = "good";
    
    auto res = sol.findOcurrences(text, first, second);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;
    
    return 0;
}
