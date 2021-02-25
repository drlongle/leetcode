class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>arr = nums;
        sort(arr.begin() , arr.end());
        int start = -1, end = -1;
        for (int i = 0 ; i < nums.size() ; i++ ) {
            if (nums[i] != arr[i]) {
                start = i;
                break;
            }
        }
        
        for (int i = nums.size() - 1 ; i >= 0; i -- ) {
            if (nums[i] != arr[i]) {
                end = i;
                break;
            }
        }
        if (start == -1 && end == -1)
            return 0;
        return abs(end - start + 1);
    }
};
