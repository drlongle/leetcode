class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        priority_queue<Interval, vector<Interval>, cmp> q;
        for (auto &intervals : schedule)
            for (auto &interval : intervals)
                q.push(interval);
        vector<Interval> res;
        Interval pre = q.top();
        q.pop();
        while (!q.empty()) {
            Interval cur = q.top();
            q.pop();
            if (cur.start > pre.end) {
                res.push_back(Interval(pre.end, cur.start));
                pre = cur;
            } else {
                pre.end = max(pre.end, cur.end);
            }
        }
        return res;
    }

    struct cmp {
        bool operator()(Interval &interval1, Interval &interval2) {
            if (interval1.start == interval2.start)
                return interval1.end > interval2.end;
            return interval1.start > interval2.start;
        }
    };
};
