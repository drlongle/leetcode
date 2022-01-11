/*
The idea is to define the size of our buckets such that the maximum gap will necessarily be larger than
a single bucket. That would mean that our answer could then be found by comparing the highest value in
each bucket with the lowest value in the next occupied bucket.

To achieve the right bucket size (bsize) for this to work, we'll need to iterate through nums once to find
the total range (hi - lo), then use that to figure out the absolute smallest possible maximum gap value
((hi - lo) / (nums.length - 1)). If we make sure to define the bucket size smaller than this value,
then as stated earlier, the two numbers that form the maximum gap will have to be found in separate buckets.

Since there are exactly N numbers spread throughout the buckets, and since it only requires a single iteration
of each number in a bucket to observe the local high and lo values (currhi, currlo), then it will take a total
of O(N) time to perform this process for the entire buckets array. And since we only need to make one comparison
per pair of buckets with consecutive numbers, and as there are only a maximum of 2 * N buckets, the comparisons
will only take O(N) time, as well.
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int hi = 0, lo = INT_MAX, ans = 0;
        for (auto& n : nums)
            hi = max(hi, n), lo = min(lo, n);
        int bsize = max(int((hi - lo) / (nums.size() - 1)), 1);
        vector<vector<int>> buckets((hi - lo) / bsize + 1, vector<int>());
        for (auto& n : nums)
            buckets[(n - lo) / bsize].push_back(n);
        int currhi = 0;
        for (auto& b : buckets) {
            if (b.empty()) continue;
            int prevhi = currhi ? currhi : b[0], currlo = b[0];
            for (auto& n : b)
                currhi = max(currhi, n), currlo = min(currlo, n);
            ans = max(ans, currlo - prevhi);
        }
        return ans;
    }
};
