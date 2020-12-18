class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(),
                  intervals.end(),
                  [] (const vector<int> &left, const vector<int> &right) {
                      return left.front() < right.front();
                  });

        int prev_end_time = 0;
        for (auto &interval : intervals) {
            if (interval.front() < prev_end_time) {
                return false;
            }
            prev_end_time = interval.back();
        }

        return true;
    }
};