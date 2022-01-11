/*
Intuition
We should put the largest number into the most queried position.

Solution
We can count how many times each position was queried using another array cnt. To do so in O(n), we mark
the start and end of each query with + 1 and - 1, and then calculate counts for each position in one swipe.

You can see the picture that demonstrates this here: 1109. Corporate Flight Bookings.

Then, we can sort the input array and the count array, so that larger numbers and higher count are in the
matching positions. Then, we can compute the maximum sum in the final swipe.
 */

class Solution  {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> cnt(nums.size());
        for (auto &r : requests) {
            cnt[r[0]] += 1;
            if (r[1] + 1 < nums.size())
                cnt[r[1] + 1] -= 1;
        }
        for (auto i = 1; i < cnt.size(); ++i)
            cnt[i] += cnt[i - 1];
        sort(begin(nums), end(nums));
        sort(begin(cnt), end(cnt));
        int res = 0;
        for (auto i = 0; i < nums.size(); ++i)
            res = (res + nums[i] * cnt[i]) % 1000000007;
        return res;
    }
};