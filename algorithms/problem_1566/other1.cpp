class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        int left = 0, right = m;
        int count = 1;
        while(right < n) {
            // if mismatch is found increment the left pointer and move right pointer to end of window (left+m)
            if(arr[right-m] != arr[right]) {
                count = 1;
                left++;
                right = left+m;
            }
                // else check if a window is complete then increment the count
            else {
                if((right-left+1)%m == 0) count++;
                if(count == k) return true;
                right++;
            }
        }
        return false;
    }
};
