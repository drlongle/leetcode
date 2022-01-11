/*
There is no need to tell intervals belonging to which person.
We just cut off all occupied intervals from the timeline, then remove the left-end and right-end.
Use the strict-weak-order, I am using this concept for all interval-overlapping problem.
 */

class Solution {
public:
    struct sortableInterval
    {
        int begin = 0;
        int end   = 0;

        // when x < y, means interval x is at left side of y and they are not contiguous
        bool operator < (const sortableInterval &other) const
        {
            return this->end + 1 <= other.begin;
        }
    };

    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule)
    {
        std::set<sortableInterval> occus;
        for(const auto &person: schedule){
            for(const auto &i: person){
                const auto eqr = occus.equal_range({i.start, i.end});
                if(eqr.first == eqr.second){
                    occus.insert({i.start, i.end});
                }
                else{
                    int min = INT_MAX;
                    int max = INT_MIN;

                    for(auto p = eqr.first; p != eqr.second; ++p){
                        min = std::min<int>({p->begin, min, i.start});
                        max = std::max<int>({p->end  , max, i.end  });
                    }

                    occus.erase(eqr.first, eqr.second);
                    occus.insert({min, max});
                }
            }
        }

        std::vector<Interval> result;
        for(auto p = occus.begin(), q = std::next(p); q != occus.end(); p++, q++){
            result.push_back({p->end, q->begin});
        }
        return result;
    }
};
