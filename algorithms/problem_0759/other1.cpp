class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {

        map<int,int> track;
        vector<Interval> res;

        for (const vector<Interval>& v :  schedule) {

            for (const Interval& i : v) {
                track[i.start]++;
                track[i.end]--;
            }
        }

        int count = 0, start = -1;
        for (auto it : track) {

            count += it.second;
            if (count == 0) {
                start = it.first;
            } else if (count > 0 && start != -1) {
                res.push_back(Interval(start, it.first));
                start = -1;
            }
        }

        return res;

    }
};
