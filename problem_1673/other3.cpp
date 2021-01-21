/*
 - Use a vector instead of a stack
 - Build a non-decreasing subsequence (take current element from nums - say nums[i], and keep deleting
   the last element from the vector as long as its greater than nums[i])
 - Maintain a "last" marker. Don't go beyond this as these are values to be returned. Using a last
   marker improves performance as you don't need to delete elements from the beginning.
 - In the end, simply resize the vector to size k, and return it
 */

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int i, n = nums.size(), last = 0;
        vector<int> a;
        for(i=0; i<n; i++) {
            if(i + k > n)
                ++last;
            while(a.size() > last && a.back() > nums[i])
                a.pop_back();
            a.push_back(nums[i]);
        }
        a.resize(k);
        return a;
    }
};
