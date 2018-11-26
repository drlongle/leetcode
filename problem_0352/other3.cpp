#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Interval {
    Interval(int s, int e) : start(s), end(e) { }
    int start, end;
};

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() { }

    void addNum(int val) {
        if (mp.count(val)) return;
        if (mp.empty()) {
            mp[val] = val;
            return;
        }
        mp[val] = val;
        mergeIntervals(val);
    }

    vector<Interval> getIntervals() {
        vector<Interval> ans;
        for (auto& p: mp)
            ans.push_back(Interval(p.first, p.second));
        return ans;
    }

    void mergeIntervals(int val) {
        auto it = mp.find(val);
        auto cur = prev(it, 1);
        if (cur != mp.end() && (*cur).second - (*it).first >= -1) {
            (*cur).second = max((*it).second, (*cur).second);
            mp.erase((*it).first);
            it = cur;
        }
        cur = next(it, 1);
        if (cur != mp.end() && (*it).second - (*cur).first >= -1) {
            (*it).second = max((*cur).second, (*it).second);
            mp.erase((*cur).first);
        }
    }
private:
    map<int, int> mp;
};

int main()
{
    cout << "Hello world!" << endl;
}

