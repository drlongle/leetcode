/*
1348. Tweet Counts Per Frequency
Medium

Implement the class TweetCounts that supports two methods:

1. recordTweet(string tweetName, int time)

Stores the tweetName at the recorded time (in seconds).

2. getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)

Returns the total number of occurrences for the given tweetName per minute, hour, or day (depending on freq) starting from the startTime (in seconds) and ending at the endTime (in seconds).
freq is always minute, hour or day, representing the time interval to get the total number of occurrences for the given tweetName.

The first time interval always starts from the startTime, so the time intervals are [startTime, startTime + delta*1>,  [startTime + delta*1, startTime + delta*2>, [startTime + delta*2, startTime + delta*3>, ... , [startTime + delta*i, min(startTime + delta*(i+1), endTime + 1)> for some non-negative number i and delta (which depends on freq).  

Example:

Input
["TweetCounts","recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency","getTweetCountsPerFrequency","recordTweet","getTweetCountsPerFrequency"]
[[],["tweet3",0],["tweet3",60],["tweet3",10],["minute","tweet3",0,59],["minute","tweet3",0,60],["tweet3",120],["hour","tweet3",0,210]]

Output
[null,null,null,null,[2],[2,1],null,[4]]

Explanation
TweetCounts tweetCounts = new TweetCounts();
tweetCounts.recordTweet("tweet3", 0);
tweetCounts.recordTweet("tweet3", 60);
tweetCounts.recordTweet("tweet3", 10);                             // All tweets correspond to "tweet3" with recorded times at 0, 10 and 60.
tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59); // return [2]. The frequency is per minute (60 seconds), so there is one interval of time: 1) [0, 60> - > 2 tweets.
tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60); // return [2, 1]. The frequency is per minute (60 seconds), so there are two intervals of time: 1) [0, 60> - > 2 tweets, and 2) [60,61> - > 1 tweet.
tweetCounts.recordTweet("tweet3", 120);                            // All tweets correspond to "tweet3" with recorded times at 0, 10, 60 and 120.
tweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);  // return [4]. The frequency is per hour (3600 seconds), so there is one interval of time: 1) [0, 211> - > 4 tweets.

Constraints:
There will be at most 10000 operations considering both recordTweet and getTweetCountsPerFrequency.
0 <= time, startTime, endTime <= 10^9
0 <= endTime - startTime <= 10^4
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

class TweetCounts {
public:
    struct Tweet {
        map<int, int> count;
    };

    unordered_map<string, Tweet> tweets;
    
    TweetCounts() = default;
    
    void recordTweet(string tweetName, int time) {
        Tweet& tweet = tweets[tweetName];
        ++(tweet.count[time]);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval;
        if (freq == "minute")
            interval = 60;
        else if (freq == "hour")
            interval = 3600;
        else
            interval = 86400;
        
        Tweet& tweet = tweets[tweetName];
        vector<int> res;

        for (int t = startTime; t <= endTime; t += interval) {
            int count = 0;
            auto it = tweet.count.lower_bound(t);
            for (; it != tweet.count.end() && it->first < min(endTime+1, t + interval); ++it)
                count += it->second;
            res.emplace_back(count);
        }
        return res;
    }
};

void test_1() {
    TweetCounts tweetCounts;
    vector<int> res;
    tweetCounts.recordTweet("tweet3", 0);
    tweetCounts.recordTweet("tweet3", 60);
    tweetCounts.recordTweet("tweet3", 10);
    res = tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59); // return [2].
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    res = tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60); // return [2, 1].
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    tweetCounts.recordTweet("tweet3", 120);
    res = tweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);  // return [4].
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
}

void test_21() {
    TweetCounts tweetCounts;
    vector<int> res;
    tweetCounts.recordTweet("tweet3", 0);
    tweetCounts.recordTweet("tweet3", 60);
    tweetCounts.recordTweet("tweet3", 10);
    res = tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59); // return [2].
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    res = tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60); // return [2, 1].
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    tweetCounts.recordTweet("tweet3", 120);
    res = tweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);  // return [4].
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
}

int main() {
    test_1();
    //test_21();
    return 0;
}
