class Solution {
    private:
        vector<int> nums;
        vector<int> vec;
public:
    Solution(vector<int>& nums) {
        this->nums=nums;
        vec=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        next_permutation(vec.begin(),vec.end());
        return vec;
    }
};
