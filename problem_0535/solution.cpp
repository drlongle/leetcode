/*
535. Encode and Decode TinyURL
Medium

Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
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

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        urls.emplace_back(longUrl);
        return "http://tinyurl.com/" + to_string(urls.size() - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        auto index = shortUrl.find_last_of('/');
        string sindex = shortUrl.substr(index+1);
        int uindex = stoi(sindex);
        return urls[uindex];
    }

    vector<string> urls;
};

void test_1()
{
    Solution sol;
    const string url = "https://leetcode.com/problems/design-tinyurl";
    string encoded = sol.encode(url);
    cout << "Decoding: " << sol.decode(encoded) << endl;
}

int main() {
    test_1();
    
    return 0;
}
