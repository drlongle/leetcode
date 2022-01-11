/*
Track count of each numbers n, and bucket numbers by their count in c.

For each number, increase its count, then decrement elements in count - 1 bucket and increment in count bucket. Also track non-empty buckets in total.

When total is 1 or 2, we may have the equal frequency situation. There is two cases when there is only one bucket, and two cases when there are two.

One bucket (all elements have the same frequency):
Single number repeats many times.
All numbers repeat one time.
Two buckets (all elements have either frequency count 1 or count 2) :
One bucket has frequency of 1, and only one element.
One bucket has frequency of n + 1 and only one element. All other elements repeat n times.
*/

class Solution {
public:
    int maxEqualFreq(vector<int>& nums, int res = 0) {
        int n[50001] = {}, c[50001] = {}, total = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            int count = ++n[nums[i]];
            if (++c[count] == 1) ++total;
            if (count > 1 && --c[count - 1] == 0) --total;
            if (total == 1 && (count == 1 || c[count] == 1)) res = i + 1;
            if (total == 2){
                auto m_count = c[count + 1] ? count + 1 : count;
                if (c[1] == 1 || (c[m_count] == 1 && c[m_count - 1])) res = i + 1;
            }
        }
        return res;
    }
};
