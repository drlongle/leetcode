/*
We only need to consider k = 1 and k = 2 then it becomes a classic DP problem - Maximum Subarray Sum.
 */

int kConcatenationMaxSum(vector<int>& arr, int k) {
    int n = arr.size(), sum = arr[0], mx = arr[0];
    int64_t total = accumulate(arr.begin(), arr.end(), 0), mod = 1e9+7;
    for (int i = 1; i < n * min(k, 2); i++) {
        sum = max(arr[i % n], sum + arr[i % n]);
        mx = max(mx, sum);
    }
    return max<int64_t>({0, mx, total * k - (total * 2 - mx)}) % mod;
}
