class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs)
                  {
                      if(lhs[0] == rhs[0])
                          return lhs[1]>rhs[1];
                      return lhs[0] < rhs[0];});
        
        int count = 1;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(start <= intervals[i][0] && intervals[i][1] <= end)
                continue;
            if(end <= intervals[i][0] || (start <= intervals[i][0] && end <= intervals[i][1])){
                count++;
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        return count;
    }

};
