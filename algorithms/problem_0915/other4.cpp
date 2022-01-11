class Solution {
public:
    int partitionDisjoint(std::vector<int>& nums) {
        const auto n = nums.size();

        /** minValuesOnRight[i] stores the minimum
            value in the subarray nums[i:n-1]
        */
        std::vector<int> minValuesOnRight(n, 0);

        /** Go from right-to-left to compute minValuesOnRight[i]
            for all i where 0 <= i < n
        */
        int minVal = nums.back();

        minValuesOnRight.back() = minVal;

        for ( int i = n - 2; i >= 0; --i ) {
            minVal = std::min(minVal, nums[i]);
            minValuesOnRight[i] = minVal;
        }

        /** Now go from left to right to determine the first index
            where the partition can bde made.
        */
        int maxVal = nums.front();

        for ( int i = 1; i < n; ++i ) {
            if ( minValuesOnRight[i] >= maxVal )
                return i;
            maxVal = std::max(maxVal, nums[i]);
        }

        return -1;
    }
};
