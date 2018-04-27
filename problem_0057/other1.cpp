// Basically treat the result vector as a stack and keep merging if required. If intervals are to left of the new interval we need to swap the order.

vector<Interval> insert(vector<Interval>& times, Interval m) {
        vector<Interval> merged{m};
        
        for (int i=0; i < times.size(); ++i) {
            auto &q = merged.back();
            auto p = times[i];
            if (p.end >= q.start && q.end >= p.start) {
                q.start = min(p.start, q.start);
                q.end = max(p.end, q.end);
            } else {
                if (p.end < q.start) swap(p, q);
                merged.push_back(p);    
            }
        }
        
        return merged;
    }

