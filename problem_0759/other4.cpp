class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> tmp;
        for(auto i:schedule)
        {
            for(auto s: i)
                tmp.push_back(s);
        }
        sort(tmp.begin(),tmp.end(),cmp);

        vector<Interval> res;
        int start=0, end=1;
        while(end<tmp.size())
        {
            if(tmp[end].start>tmp[start].end)
            {
                res.push_back(Interval(tmp[start].end, tmp[end].start));
                start=end;
                end++;
            }
            else
            {
                tmp[start].end=max(tmp[start].end,tmp[end].end);
                end++;
            }
        }
        return res;
    }

    static bool cmp(Interval &a, Interval &b)
    {
        return a.start<b.start || (a.start==b.start && a.end<b.end);
    }
};
