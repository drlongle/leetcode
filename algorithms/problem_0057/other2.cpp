vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        
        vector<Interval> result;
        int size = intervals.size();
        if (size == 0) {
            result.push_back(newInterval);
            return result;
        }
        
        // insert newInterval at appropriate location
        int i;
        for (i=0; i<size; i++) {
            if (intervals[i].start > newInterval.start) {
                break;
            }
        }
        intervals.insert(intervals.begin()+i, newInterval);
        
        Interval in;
        in.start = intervals[0].start;
        in.end = intervals[0].end;
        result.push_back(in);
        int currentPtr = 0;
        
        for (i=1;i <size+1; i++) {
            if (intervals[i].start <= result[currentPtr].end) {
                if (intervals[i].end > result[currentPtr].end) {
                    result[currentPtr].end = intervals[i].end;
                }
            } else {
                result.push_back(intervals[i]);
                currentPtr++;
            }
        }
        
        return result;
    }
