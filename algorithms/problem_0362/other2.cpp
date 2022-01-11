class HitCounter {
    struct Hit {
        int timestamp;
        int count;
    };
    vector<Hit> hits;
public:
    /** Initialize your data structure here. */
    HitCounter() {
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (hits.empty())
            hits.push_back(Hit{timestamp, 0});
        else
            hits.push_back(Hit{timestamp, hits.back().count + 1});
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int l = timestamp - 60*5;

        auto lb = upper_bound(hits.begin(), hits.end(), Hit{l, {}}, [](const auto &a, const auto &b) {
            return a.timestamp < b.timestamp;
        });

        if (lb == hits.end())
            return 0;

        auto ub = upper_bound(lb, hits.end(), Hit{timestamp, {}}, [](const auto &a, const auto &b) {
            return a.timestamp < b.timestamp;
        });

        ub -= 1;
        return ub->count - lb->count + 1;
    }
};
