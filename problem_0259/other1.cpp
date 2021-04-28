class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        // 2 pointers + linear scan: for each i, j, k triple, let i start from 0 to the end,
        // we need to find a way to calculate the (j, k) pairs such that the triple sum < target.
        // Let j start from i + 1, and k start from the end, each time we find (i, j, k) < target,
        // we will also find (i, j, k - 1), ..., (i, j, j + 1) < target, so there are totally
        // k - j pairs starting from j such that (i, j, k) < target.
        // Otherwise if (i, j, k) >= target, we reduce 1 from k, and check (i, j, k) again.
        // We keep doing this until j >= k.
        int res = 0, size = nums.size();
        sort(nums.begin(), nums.end()); // sort the array first
        for (int i = 0; i < size; ++i)
        {
            for (int j = i + 1, k = size - 1; j < k; --k) // 2 pointers
            {
                while (j < k && nums[i] + nums[j] + nums[k] < target) // (i, j, k) < target
                {
                    res += k - j; // add k - j # of pairs as described above
                    ++j;
                }
            }
        }

        return res;
    }
};
