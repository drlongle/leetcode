class TweetCounts {
    unordered_map<string, multiset<int>> all;
public:
    TweetCounts() {}
    
    void recordTweet(string tweetName, int time) {
        all[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int d = 86400;
        if (freq[0] == 'm') {
            d = 60;
        } else if (freq[0] == 'h') {
            d = 3600;
        }
        vector<int> r((endTime - startTime) / d + 1);
        const auto s = all.find(tweetName);
        if (s != all.end()) {
            for (auto t = s->second.lower_bound(startTime); t != s->second.end() && *t <= endTime; ++t) {
                ++r[(*t - startTime) / d];
            }
        }
        return r;
    }
};
