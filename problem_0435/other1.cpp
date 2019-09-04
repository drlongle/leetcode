bool Comp(const vector<int>& a, const vector<int>& b){
    return a[1] <= b[1];
}

class Solution {
public:
    bool overlap(const vector<int>& a, const vector<int>& b){
        return (a[0] <= b[0] && a[1] > b[0]) || (b[0] <= a[0] && b[1] > a[0]);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), Comp);
        int res = 0, p1 = 0, p2 = 1;
        for(; p2 < intervals.size(); ++ p2){
            if( overlap(intervals[p1], intervals[p2]) ){
                res ++;
            }
            else
                p1 = p2;
        }
        return res;
    }
};
