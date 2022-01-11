class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // calculate all possible sub array sums
        vector<int> su((n - k + 1), 0);
        for (int i = 0; i < k; i++) {
            su[0] += nums[i];
        }

        for (int i = 1; i <= n - k; i++) {
            su[i] = su[i-1] - nums[i-1] + nums[i+k-1];
        }

        // find max 3rd sub array in every possible range
        vector<int> mp3(n, -1);
        int max3 = n-k;
        for (int i = n - k; i >= 2*k; i--) {
            if (su[i] >= su[max3]) {
                max3 = i;
            }
            mp3[i] = max3;
        }

        // find max 2nd sub array in every possible range
        vector<int> mp2(n, -1);
        int max2 = n - 2*k;
        for (int i = n - 2*k; i >= k; i--) {
            if (su[i] + su[mp3[i+k]] >= su[max2] + su[mp3[max2+k]]) {
                max2 = i;
            }
            mp2[i] = max2;
        }

        // find max of all 3 sub arrays
        int maxSum = 0;
        vector<int> res(3, -1);
        for (int i = 0; i <= n - 3*k; i++) {
            int j = mp2[i+k];
            int l = mp3[j+k];
            if (maxSum < su[i] + su[j] + su[l]) {
                maxSum = su[i] + su[j] + su[l];
                res[0] = i;
                res[1] = j;
                res[2] = l;
            }
        }

        return res;
    }
};
