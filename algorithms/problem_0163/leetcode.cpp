class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<string> missingRanges;

        if (n == 0) {
            missingRanges.push_back(formatRange(lower, upper));
            return missingRanges;
        }

        // Edge case 1) Missing ranges at the beginning
        if (nums[0] > lower) {
            missingRanges.push_back(formatRange(lower, nums[0] - 1));
        }

        // Missing ranges between array elements
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > 1) {
                missingRanges.push_back(formatRange(nums[i - 1] + 1, nums[i] - 1));
            }
        }

        // Edge case 2) Missing ranges at the end
        if (nums[n - 1] < upper) {
            missingRanges.push_back(formatRange(nums[n - 1] + 1, upper));
        }

        return missingRanges;
    }

    // formats range in the requested format
    string formatRange(int lower, int upper) {
        if (lower == upper) {
            return to_string(lower);
        } else {
            return to_string(lower) + "->" + to_string(upper);
        }
    }
};