/*
1242. Web Crawler Multithreaded
Medium

Given a url startUrl and an interface HtmlParser, implement a Multi-threaded web crawler to
crawl all links that are under the same hostname as startUrl.

Return all urls obtained by your web crawler in any order.

Your crawler should:
Start from the page: startUrl
Call HtmlParser.getUrls(url) to get all urls from a webpage of given url.
Do not crawl the same link twice.
Explore only the links that are under the same hostname as startUrl.

As shown in the example url above, the hostname is example.org. For simplicity sake, you may assume all urls
use http protocol without any port specified. For example, the urls http://leetcode.com/problems and
http://leetcode.com/contest are under the same hostname, while urls http://example.org/test and
http://example.com/abc are not under the same hostname.

The HtmlParser interface is defined as such:

interface HtmlParser {
  // Return a list of all urls from a webpage of given url.
  // This is a blocking call, that means it will do HTTP request and return when this request is finished.
  public List<String> getUrls(String url);
}
Note that getUrls(String url) simulates performing a HTTP request. You can treat it as a blocking function call
which waits for a HTTP request to finish. It is guaranteed that getUrls(String url) will return the urls within
15ms. Single-threaded solutions will exceed the time limit so, can your multi-threaded web crawler do better?

Below are two examples explaining the functionality of the problem, for custom testing purposes you'll have
three variables urls, edges and startUrl. Notice that you will only have access to startUrl in your code,
while urls and edges are not directly accessible to you in code.

Follow up:

Assume we have 10,000 nodes and 1 billion URLs to crawl. We will deploy the same software onto each node.
The software can know about all the nodes. We have to minimize communication between machines and make sure
each node does equal amount of work. How would your web crawler design change?
What if one node fails or does not work?
How do you know when the crawler is done?

Example 1:
Input:
urls = [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.google.com",
  "http://news.yahoo.com/us"
]
edges = [[2,0],[2,1],[3,2],[3,1],[0,4]]
startUrl = "http://news.yahoo.com/news/topics/"
Output: [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.yahoo.com/us"
]

Example 2:
Input:
urls = [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.google.com"
]
edges = [[0,2],[2,1],[3,2],[3,1],[3,0]]
startUrl = "http://news.google.com"
Output: ["http://news.google.com"]
Explanation: The startUrl links to all other pages that do not share the same hostname.

Constraints:
1 <= urls.length <= 1000
1 <= urls[i].length <= 300
startUrl is one of the urls.
Hostname label must be from 1 to 63 characters long, including the dots, may contain only the ASCII letters from 'a' to 'z', digits from '0' to '9' and the hyphen-minus character ('-').
The hostname may not start or end with the hyphen-minus character ('-').
See:  https://en.wikipedia.org/wiki/Hostname#Restrictions_on_valid_hostnames
You may assume there're no duplicates in url library.
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

class HtmlParser {
public:
    vector<string> getUrls(string url) {
        return vector<string>();
    }
};

class Solution {
public:
    string get_host(string& url) {
        size_t pos = url.find('/', 7);
        return url.substr(7, pos - 7);
    }

    void run() {
        string s;
        while (true) {
            s.resize(0);
            {
                lock_guard <mutex> lk(m_mutex);
                if (!m_active && q.empty())
                    return;
                if (q.size()) {
                    ++m_active;
                    s = q.front();
                    q.pop();
                }
            }

            if (!s.empty()) {
                auto urls = m_parser->getUrls(s);
                lock_guard<mutex> lk(m_mutex);
                for (auto& url: urls) {
                    auto nhost = get_host(url);
                    if (host == nhost && res.emplace(url).second) {
                        q.emplace(url);
                    }
                }
                --m_active;
            }
        }
    }

    mutex m_mutex;
    int m_active;
    queue<string> q;
    string host;
    unordered_set<string> res;
    static constexpr int N = 4;
    vector<thread> m_threads;
    HtmlParser* m_parser;

    vector<string> crawl(string startUrl, HtmlParser htmlParser) {

        host = get_host(startUrl);
        res.emplace(startUrl);
        q.emplace(startUrl);
        m_active = 0;
        m_parser = &htmlParser;

        for (int i = 0; i < N; ++i) {
            m_threads.emplace_back(&Solution::run, this);
        }

        for (int i = 0; i < N; ++i) {
            m_threads[i].join();
        }

        return vector<string>(res.begin(), res.end());
    }
};

void test_1()
{
    Solution sol;
    vector<string> res;
    HtmlParser parser;
    res = sol.crawl("http://news.yahoo.com/news/topics/", parser);
}

int main() {
    test_1();
    return 0;
}
