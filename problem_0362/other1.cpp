class HitCounter {
public:
    /** Initialize your data structure here. */
    vector<int> timeStamps;
    HitCounter() {

    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        timeStamps.push_back(timestamp);
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        auto it = upper_bound(timeStamps.begin() ,timeStamps.end(),timestamp-300);
        return timeStamps.end() - it;
    }
};
