int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper)
{
    // init the sum of the sliding window as the first k elements. Since the input length is greater equal k, it's safe
    // to accumulate without checking
    int sum = accumulate(calories.begin(), calories.begin() + k, 0);
    // init the score
    int ans = sum > upper ? 1 : sum < lower ? -1 : 0;

    // slide the window by including the next element and excluding the previous element from the sum
    for (int i = k; i < calories.size(); ++i) {
        sum += calories[i];
        sum -= calories[i - k];
        // evaluate current score
        ans += sum > upper ? 1 : sum < lower ? -1 : 0;
    }
    return ans;
}
