class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, previousRemainder = 0;
        unordered_set<int> sumsSet;

        // loop through array
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            // corner case, 0 can not modulo
            if (k != 0) {
                sum %= k; // get remainder
            }

            // remainder 0 exist, means that qualify multiple of k, sum up to n*k
            if (sumsSet.count(sum)) {
                return true;
            }

            // insert remainder in set if not found any
            else {
                sumsSet.insert(previousRemainder);
                previousRemainder = sum;
            }
        }

        // not found any
        return false;
    }
};
