/*
1410. HTML Entity Parser
Medium

HTML entity parser is the parser that takes HTML code as input and replace all the entities of the special characters by the characters itself.

The special characters and their entities for HTML are:

Quotation Mark: the entity is &quot; and symbol character is ".
Single Quote Mark: the entity is &apos; and symbol character is '.
Ampersand: the entity is &amp; and symbol character is &.
Greater Than Sign: the entity is &gt; and symbol character is >.
Less Than Sign: the entity is &lt; and symbol character is <.
Slash: the entity is &frasl; and symbol character is /.
Given the input text string to the HTML parser, you have to implement the entity parser.

Return the text after replacing the entities by the special characters.

Example 1:
Input: text = "&amp; is an HTML entity but &ambassador; is not."
Output: "& is an HTML entity but &ambassador; is not."
Explanation: The parser will replace the &amp; entity by &

Example 2:
Input: text = "and I quote: &quot;...&quot;"
Output: "and I quote: \"...\""

Example 3:
Input: text = "Stay home! Practice on Leetcode :)"
Output: "Stay home! Practice on Leetcode :)"

Example 4:
Input: text = "x &gt; y &amp;&amp; x &lt; y is always false"
Output: "x > y && x < y is always false"

Example 5:
Input: text = "leetcode.com&frasl;problemset&frasl;all"
Output: "leetcode.com/problemset/all"

Constraints:
1 <= text.length <= 10^5
The string may contain any possible characters out of all the 256 ASCII characters.
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
    string entityParser(string text) {
        ostringstream oss;
        int i = 0, sz = text.size();
        map<string, string> specials{{"&gt;", ">"}, {"&lt;", "<"}, {"&amp;", "&"}, {"&quot;", "\""}, {"&apos;", "'"}, {"&frasl;", "/"}};
        while (i < sz) {
            char ch = text[i];
            if (ch != '&') {
                oss << ch;
                ++i;
            } else {
                bool matched = false;
                for (const auto& [key, value]: specials) {
                    int ks = key.size();
                    if (i + ks <= sz && string_view(key.c_str()) == string_view(text.c_str() + i, ks)) {
                            oss << value;
                            matched = true;
                            i += ks;
                            break;
                    }
                }
                if (!matched) {
                    oss << ch;
                    ++i;
                }
            }
        }

        return oss.str();
    }
};

int main() {
    Solution sol;
    string text;

    // Output: "& is an HTML entity but &ambassador; is not."
    text = "&amp; is an HTML entity but &ambassador; is not.";
    //cout << sol.entityParser(text) << endl;

    // Output: "and I quote: \"...\""
    text = "and I quote: &quot;...&quot;";
    cout << sol.entityParser(text) << endl;

    // Output: "Stay home! Practice on Leetcode :)"
    text = "Stay home! Practice on Leetcode :)";
    cout << sol.entityParser(text) << endl;
    

    // Output: "x > y && x < y is always false"
    text = "x &gt; y &amp;&amp; x &lt; y is always false";
    cout << sol.entityParser(text) << endl;
    

    // Output: "leetcode.com/problemset/all"
    text = "leetcode.com&frasl;problemset&frasl;all";
    cout << sol.entityParser(text) << endl;
    
    return 0;
}
