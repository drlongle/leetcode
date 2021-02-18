class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> left(N), right(N), ksum(N);
        for (int i=0, s=0; i<N; i++) {
            s += nums[i];
            nums[i] = s;
        }

        for (int i=0; i + k - 1 < N; i++) {
            if (i == 0) ksum[i] = nums[k-1];
            else ksum[i] = nums[i+k-1] - nums[i-1];
        }

        for (int i=0, maxv=0; i<N - 2 * k; i++) {
            if (ksum[i] > maxv) {
                maxv = ksum[i];
                left[i] = i;
            } else {
                left[i] = left[i-1];
            }
        }
        for (int i=N-1, maxv=0; i>=2*k; i--) {
            if (ksum[i] >= maxv) {
                maxv = ksum[i];
                right[i] = i;
            } else {
                right[i] = right[i+1];
            }
        }

        vector<int> ans(3);
        for (int i=k, maxv=0; i<N - k; i++) {
            int s = ksum[left[i-k]] + ksum[i] + ksum[right[i+k]];
            if (s > maxv) {
                maxv = s;
                ans = {left[i-k], i, right[i+k]};
            }
        }
        return ans;
    }
};
