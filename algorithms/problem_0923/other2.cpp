class Solution {
public:
    int threeSumMulti(std::vector<int>& arr, int target) {
        int nums[target+1];
        std::memset(nums, 0, sizeof(nums));
        std::for_each(arr.begin(), arr.end(), [&](int v) {if(v <= target) ++nums[v];});

        long count {};
        for(int i=0; i <= target; ++i) {
            if(nums[i]) {
                // If the target is three times a number and the number occurs more than thrice
                if(nums[i] >= 3 && i * 3 == target) {  // case where the same number is picked 3 times nC3
                    long n = nums[i];
                    count += n * (n-1) * (n-2) / 6;
                }
                // If the target is greater than twice a number and the number occurs more than twice and has a matching
                // number to add up to target
                if (nums[i] >= 2 && target-i*2 > i && nums[target-i*2]) {  // case where the same number is picked twice nC2
                    long n = nums[i];
                    count += n * (n-1) / 2 * nums[target-i*2];
                }
                auto subTarget = target -i;
                for(int j=i+1; j <= subTarget/2; ++j) {  // loop ends at subTarget/2 to avoid double counting
                    // if the sub-target is equal to twice a number and the number occurs more than twice
                    if(nums[j] >= 2 && j * 2 == subTarget) { // case where the same number is picked twice nC2
                        long n = nums[j];
                        count += nums[i] * n * (n-1) / 2;
                    } else if(target -i -j > j && nums[target -i -j]) {  // only pick numbers greater than self to avoid double counting
                        count += nums[i] * nums[j] * nums[target -i -j];  // case with three distinct numbers
                    }
                }
            }
        }
        return count % 1000000007;
    }
};
