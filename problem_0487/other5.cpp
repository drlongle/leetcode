class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int a{0}, b{0}, max_{0}, size{(int)nums.size()};
        for(int i{0}; i < size; ++i) {
            if(nums[i]) ++b;
            else {
                max_ = std::max(max_, a+b+1);
                a = b, b = 0;
            }
        }

        return std::min(size, std::max(max_, a+b+1));
    }
};
