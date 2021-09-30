class Solution {
public:
#define pb push_back

    vector<int> buckets; // k buckets to store current sum..our goal is to make sum == target in all buckets
    vector<int> n;
    int sum, target;

    bool func(int ind) {

        if(ind == n.size()) {
            return true;
        }

        bool isLast = false;
        for(int i=0;i<buckets.size();++i) {
            if(buckets[i] == 0) isLast = true;

            if(n[ind] + buckets[i] <= target) {
                buckets[i] += n[ind];
                bool ret = func(ind + 1);
                if(ret == true) return true;
                buckets[i] -= n[ind];
            }

            if(isLast) break;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        sum = 0;
        n = nums;
        for(int i=0;i<k;++i) {
            buckets.pb(0);
        }

        for(int i=0;i<nums.size();++i) {
            sum += nums[i];
        }

        target = sum / k;
        double test = sum / k;

        if(ceil(test) != floor(test)) {
            return false;
        }

        // Sorting improves the timing a lot. Because if elements is very large and recursion will end early
        sort(n.begin(),n.end(),greater<int>());

        return func(0);
    }
};
