class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        // First we find out which array to increase and which array to decrease.
        // Then we sort the them increasingly or decreasingly accordingly.
        // After that loop through both of them simultaneously, if the array's sum is smaller, increase the element to 6.
        // Otherwise decrease the element to 1 until the difference b/w 2 arrays is <= 0.
        // If any of the iteration is is completed, finish it until the end of the array of the difference is <= 0.
        // Finally return the number of operations.
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        int diff = abs(sum1 - sum2), res = 0, i = 0, j = 0;

        vector<int>& inc = sum1 > sum2 ? nums2 : nums1;
        vector<int>& dec = sum1 > sum2 ? nums1 : nums2;
        sort(inc.begin(), inc.end());
        sort(dec.begin(), dec.end(), greater<int>()); // sort nums1 and nums2 accordingly

        while (i < inc.size() && j < dec.size() && diff > 0)
        {
            if (6 - inc[i] > dec[j] - 1) // reduce the difference as much as possible
            {
                diff -= 6 - inc[i];
                ++i;
            }
            else
            {
                diff -= dec[j] - 1;
                ++j;
            }
            ++res;
        }

        int isInc = i < inc.size(), k = isInc ? i : j;
        vector<int>& undone = isInc ? inc : dec;
        while (k < undone.size() && diff > 0) // complete the iteration for both arrays
        {
            diff -= isInc ? 6 - inc[k] : dec[k] - 1;
            ++res;
            ++k;
        }

        return diff > 0 ? -1 : res;
    }
};
