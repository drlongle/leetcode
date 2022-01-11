/*
Tracing backward through the vector, we can update the threshold when pattern 32 occurs as below.

* If the number is greater than previous largest number, it means this number is pattern 3 and thus the threshold becomes previous largest number
* Elseif the number is greater than previous second largest number, it means this number is pattern 3 and thus the threshold becomes previous second largest number (note that current number forms pattern 23 but not pattern 32 with previous largest number)
The threshold is used to check if any element is smaller than the threshold (pattern 1). In this way, only constant space is need to keep track of the threshold, largest, and second largest number.

 */

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int l = INT_MIN; // second largest number  we have seen so far when traveling backward
		int h = INT_MIN; // largest number we have seen so far when traveling backward
		int thr = INT_MIN;
		for (int i = nums.size() - 1; i >= 0; i--) {
			if (nums[i] < thr) {
				return true;
			}
			if (nums[i] > h) {
				thr = h;
				l = h;
				h = nums[i];
			} else if (nums[i] > l) {
				thr = l;
				l = nums[i];
			}
		}
		return false;
    }
};

