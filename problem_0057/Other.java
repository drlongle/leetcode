class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> ans = new ArrayList<Interval>();

        for(int i = 0 ; i < intervals.size() ;i++){
            Interval now = intervals.get(i);
            if(now.end < newInterval.start){ //intervals before the newInterval
                ans.add(now);
                continue;
            }
            else if(now.start > newInterval.end){ //intervals after the newInterval
                ans.add(newInterval);
                ans.addAll(intervals.subList(i,intervals.size())); //add all remaining intervals and return
                return ans;
            }
            else{ //intervals overlap the newInterval , update the interval range
                newInterval.start = Math.min(newInterval.start, now.start);
                newInterval.end = Math.max(newInterval.end, now.end);
            }
        }
        ans.add(newInterval); //if there are no intervals after the newInterval, than add it and return
        return ans;
    }
}

