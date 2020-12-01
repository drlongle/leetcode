class Solution { //binary search
public: // Time/Space: O(nlogM); O(1); M: max_val - minVal
    double findMaxAverage(vector<int>& nums, int k) {
        double min_val = *min_element(nums.begin(), nums.end());
        double max_val = *max_element(nums.begin(), nums.end());
        double error = INT_MAX, pre_mid = max_val;
        while(error > 0.000001){
            auto mid = (min_val + max_val) / 2;
            if(check(nums, k, mid)) min_val = mid;
            else max_val = mid;
            error = abs(pre_mid - mid); // trick: update the error between latest two iterations
            pre_mid = mid;
        }
        return min_val;
    }

private:
    // to check if a subarray with length greater than or equal to k is possible with
    // an average sum greater than the mid value, i.e., check:
    // (a_1+a_2+ a_3...+a_j)/j ≥ mid
    // Time/Space: O(N); O(1)
    bool check(const vector<int>& nums, int k, double mid) {
        double sums = 0, pre_sums = 0;
        double min_pre_sums = 0; // trick: to accommodate the case pre_sums include no elements.
        for(int i = 0; i < k; i++) sums += nums[i] - mid;
        if( sums >= 0) return true;
        for(int i = k; i < nums.size(); i++) {
            sums += nums[i] - mid;
            pre_sums += nums[i - k] - mid;
            min_pre_sums = min(min_pre_sums, pre_sums);
            if(sums - min_pre_sums >= 0) return true;
        }
        return false;
    }
};
