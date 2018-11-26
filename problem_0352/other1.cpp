
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

class SummaryRanges {
private:
    map<int, int> s2e;
    map<int, int> e2s;
    unordered_set<int> vis;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    }

    void addNum(int val) {
        if (vis.find(val) != vis.end()) {
            return;
        }
        vis.insert(val);

        auto itprev = e2s.find(val - 1);
        auto itnext = s2e.find(val + 1);

        if (itprev == e2s.end() && itnext == s2e.end()) {
            s2e[val] = val;
            e2s[val] = val;
            return;
        }

        if (itprev != e2s.end() && itnext != s2e.end()) {
            int start = e2s[val - 1];
            int end = s2e[val + 1];
            e2s.erase(val - 1);
            s2e.erase(val + 1);
            s2e[start] = end;
            e2s[end] = start;
            return;
        }

        if (itprev != e2s.end()) {
            int start = e2s[val - 1];
            int end = val;
            e2s.erase(val - 1);
            s2e[start] = end;
            e2s[end] = start;
            return;
        }

        int start = val;
        int end = s2e[val + 1];
        s2e.erase(val + 1);
        s2e[start] = end;
        e2s[end] = start;
    }

    vector<Interval> getIntervals() {
        vector<Interval> res;
        for (auto& pr : s2e) {
            res.push_back(Interval(pr.first, pr.second));
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
