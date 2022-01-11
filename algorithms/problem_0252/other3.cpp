class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return true;
        sort(intervals.begin(),intervals.end());

        int pre=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(pre>intervals[i][0])
            {
                return false;
            }
            else
            {
                pre=intervals[i][1];
            }
        }
        return true;
    }
};
