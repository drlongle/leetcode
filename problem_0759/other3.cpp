class Solution {
public:
    static bool cmp(Interval a, Interval b){
        return a.start < b.start;
    }

    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> all, merged, ans;
        for(auto i: schedule)
            for(auto j: i)
                all.emplace_back(j);

        sort(begin(all), end(all), cmp);

        for(int i = 0; i < all.size(); i++)
            if(i == 0 || merged.back().end < all[i].start){

                if(i != 0)
                    ans.emplace_back(Interval(merged.back().end,  all[i].start));
                merged.emplace_back(all[i]);
            }
            else{
                Interval itr(min(merged.back().start, all[i].start), max(merged.back().end, all[i].end));
                merged.emplace_back(itr);
            }
        return ans;
    }
};
