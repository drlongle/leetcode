/*
355. Design Twitter

Difficulty:Medium
Total Accepted:26.8K
Total Submissions:103.1K

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.

Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);

*/

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Tweet {
public:
    Tweet(int i, int s): id(i), seqno(s) { }

    bool operator<(const Tweet& other) const {
        return seqno < other.seqno;
    }

    int id;
    int seqno;
};

class Twitter {
public:

    static const int MAX_TWEETS;

    /** Initialize your data structure here. */
    Twitter(): seqno(1) {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetId, seqno++); 
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet> t;
        follows[userId].emplace(userId);
        for (auto& followeeId: follows[userId]) {
            vector<Tweet>& followTweet = tweets[followeeId];
            for (int i = 0, index = followTweet.size() - 1; i < min(MAX_TWEETS, static_cast<int>(followTweet.size())); ++i, --index)
                t.emplace(followTweet[index]);
        }
        vector<int> res;
        while (static_cast<int>(res.size()) < MAX_TWEETS && t.size()) {
            res.emplace_back(t.top().id);
            t.pop();
        }

        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follows[followerId].emplace(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }

private:
    map<int, vector<Tweet>> tweets;
    map<int, unordered_set<int>> follows;
    int seqno;
};

const int Twitter::MAX_TWEETS = 10;

void baseTest()
{
    vector<int> res;
    Twitter twitter;

    // User 1 posts a new tweet (id = 5).
    twitter.postTweet(1, 5);

    // User 1's news feed should return a list with 1 tweet id -> [5].
    res = twitter.getNewsFeed(1);
    cout << "Expecting: [5]" << endl;
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // User 1 follows user 2.
    twitter.follow(1, 2);

    // User 2 posts a new tweet (id = 6).
    twitter.postTweet(2, 6);

    // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
    // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    twitter.getNewsFeed(1);
    cout << "Expecting: [6, 5]" << endl;
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // User 1 unfollows user 2.
    twitter.unfollow(1, 2);

    // User 1's news feed should return a list with 1 tweet id -> [5],
    // since user 1 is no longer following user 2.
    twitter.getNewsFeed(1);
    cout << "Expecting: [5]" << endl;
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
}

void test18()
{
    vector<int> res;
    Twitter twitter;

    // User 1 posts a new tweet (id = 5).
    twitter.postTweet(1, 5);

    // User 1 unfollows himself.
    twitter.follow(1, 1);

    // User 1's news feed should return a list with 1 tweet id -> [5].
    res = twitter.getNewsFeed(1);
    cout << "Expecting: [5]" << endl;
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
}

void test19()
{
    vector<int> res;
    Twitter twitter;

    vector<pair<int, int>> tweetParams{{1,5},{2,3},{1,101},
        {2,13},{2,10},{1,2},{1,94},{2,505},{1,333},{2,22},{1,11},
        {1,205},{2,203},{1,201},{2,213},{1,200},{2,202},{1,204},
        {2,208},{2,233},{1,222},{2,211}};

    for (auto& param: tweetParams)
        twitter.postTweet(param.first, param.second);

    res = twitter.getNewsFeed(1);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    twitter.follow(1, 2);
    res = twitter.getNewsFeed(1);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    twitter.unfollow(1, 2);
    res = twitter.getNewsFeed(1);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
}

int main(int argc, const char* argv[])
{
    function<void(void)> testPtr;

    testPtr = baseTest;
    testPtr = test18;
    testPtr = test19;
    testPtr();
}
