/*
271. Encode and Decode Strings
Medium

Design an algorithm to encode a list of strings to a string. The encoded string is then sent
over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:
string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}

Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}

So Machine 1 does:
string encoded_string = encode(strs);

and Machine 2 does:
vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

Note:
The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be
generalized enough to work on any possible characters. Do not use class member/global/static variables to
store states. Your encode and decode algorithms should be stateless. Do not rely on any library method
such as eval or serialize methods. You should implement your own encode/decode algorithm.
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        ostringstream oss;
        for (auto& s: strs) {
            oss << s.size() << '#';
            oss << s;
        }

        return oss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0, len = s.size();
        while (i < len) {
            int n = 0;
            while (isdigit(s[i])) {
                n = n * 10 + s[i++] - '0';
            }
            ++i;
            res.emplace_back(s.substr(i, n));
            i += n;
        }

        return res;
    }
};


int main() {
    Codec codec;
    vector<string> strs;
    string str;

    strs = {"abcd", "efg", "hijkl", "mnopq"};
    str = codec.encode(strs);
    strs = codec.decode(str);
    copy(begin(strs), end(strs), ostream_iterator<string>(cout, ", "));
    cout << endl;

    return 0;
}
