class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        auto x = countMissing(nums, 0, nums.size()-1);
        return (x<k)? (nums.back() + (k-x)) : rec(nums, 0, nums.size()-1, k);
    }

    int countMissing(vector<int>&nums, int left, int right){
        return (nums[right] - nums[left]) - (right-left);
    }

    bool baseCase(int left, int right){
        return right-left == 1;
    }

    int rec(vector<int>&nums, int left, int right, int k){
        if(baseCase(left, right))
            return nums[left] + k;
        auto mid = (right+left)/2;
        auto x = countMissing(nums, left, mid);
        return (k<=x)? rec(nums, left, mid, k) : rec(nums, mid, right, k-x);
    }
};
