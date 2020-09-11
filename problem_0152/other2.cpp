class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        int R = nums[0];
        /*
        The idea is to traverse array from left to right keeping two variables minVal and maxVal 
        which represents the minimum and maximum product value till the ith index of the array. 
        Now, if the ith element of the array is negative that means now the values of minVal and maxVal 
        will be swapped as value of maxVal will become minimum by multiplying it with a negative number. 
        Now, compare the minVal and maxVal. The value of minVal and maxVal depends on the current index 
        element or the product of the current index element and the previous minVal and maxVal respectively.
        */
        int maxVal = R, minVal = R;
        for (int i = 1; i < n; i++) { 
  
            // When multiplied by -ve number, 
            // maxVal becomes minVal 
            // and minVal becomes maxVal. 
            if (nums[i] < 0) std::swap(maxVal, minVal);
  
            // maxVal and minVal stores the 
            // product of subarray ending at arr[i]. 
            maxVal = std::max(nums[i], maxVal * nums[i]); 
            minVal = std::min(nums[i], minVal * nums[i]); 
  
            // Max Product of array. 
            R = max(R, maxVal); 
        } 
        return R;
    }
};

