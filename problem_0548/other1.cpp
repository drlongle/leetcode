class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int size = nums.size();
        if(size < 7) return false;
        unordered_map<int,vector<int>> right_sum;
        vector<int> right_sum_vector(nums.size(),0);
        int sum = 0;
        for(int right = size -1 ; right >= 0 ;right--){
            sum += nums[right];
            right_sum_vector[right] = sum; // build a sum vector, for quickly getting interval sum.
            right_sum[sum].push_back(right); // sum hash, since interger might be positive and negative, so same sum might be more than one sub-array.
        }
        sum = 0;
        for(int left = 0 ; left < size-1 ; left++){
            sum += nums[left]; // range for A segment
            for(int it : right_sum[sum]){ // if right_sum[sum] is not empty, means we found a D segment
                int inner_left = left+2, inner_right = it-2; // starting point for getting B and C
                if(inner_right - inner_left < 2) break;
                int inner_sum = right_sum_vector[inner_left] - right_sum_vector[inner_right+1]; // get interval sum across B,C
                int inner_left_sum = 0;
                for(;inner_left+1 < inner_right;inner_left++){
                    inner_left_sum+= nums[inner_left];
                    if(inner_sum - inner_left_sum - nums[inner_left+1] == inner_left_sum)
                        return true;
                }
            }
        }
        return false;
    }
};
