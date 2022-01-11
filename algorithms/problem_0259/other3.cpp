class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int size{(int)nums.size()}, count{0};
        for(int i{0}; i < size; ++i) {
            int j{i+1}, k{size-1};
            while(j < k) {
                if(nums[i]+nums[j]+nums[k] < target) count += k-j, ++j;
                else --k;
            }
        }
        return count;
    }
};
