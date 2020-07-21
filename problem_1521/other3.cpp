/*
First make sure that the return value -1000000000 can't be our result, because given the range of arr[i] <= 1e6 and target <= 1e7,
we can get worst result no more than 1e7, while the -1000000000 = -1e9. So we need to consider every subarray of array arr.

Let's look at a series of outputs by mysterious function func:

arr[l], arr[l] & arr[l + 1], arr[l] & arr[l + 1] & arr[l + 2], ..., arr[l] & ... & arr[N - 1]
Say l is a position in [0, N), N is the length of array arr.

A very important property of this sequence is that this sequence is non-increasing, because a & b <= a

So we can apply binary search to find the element that has minimum distance from target in this sequence.

However, we have N such sequences, beginning from index 0, 1, 2, ..., N - 1, and we can't afford to generate these N sequences in O(N^2) time.

For example, if we have such sequence start from l + 1, that is:

arr[l + 1], arr[l + 1] & arr[l + 2], arr[l + 1] & arr[l + 2] & arr[l + 3], ..., arr[l + 1] & ... & arr[N - 1]
How can we generate sequence beginning from l ?

Note that the new sequence's first element is arr[l], and the remaining elements are from each element of old sequence bitwise and arr[l]

We can't actually bitwise and each element in old sequence, because it will cause O(N^2) complexity in total N sequences.
If we regard arr[l] as a bit mask, and bitwise and arr[l] is actually set some bits to zero, we can save much time,
because an element's bit need to be set to zero for at most once. We have 32 * N bits in total in array arr,
so we do at most 32 * N times of set one bit to zero operations.

Then the idea is clear: group each element in arr by their binary representation, i.e. those who have i'th bit come to group i,
and when we apply set i'th bit to zero operations, we need only to consider elements in group i, and each element only requires operation once.
*/
class Solution
{
public:
    int closestToTarget(vector<int> &arr, int target)
    {
        int len = (int)arr.size();
        vector<vector<int>> tab(30);
        for (int i = 0; i < len; i++)
            for (int j = 0; j < 30; j++)
                if ((arr[i] >> j) & 1)
                    tab[j].push_back(i);

        vector<int> dp(len + 1);
        dp[len] = arr[0]; //dummy value to avoid "index out of range"
        int ans = abs(arr[0] - target);
        int l = len - 1;
        for (int i = len - 1; i >= 0; i--)
        {
            for (int j = 0; j < 30; j++)
                if (!((arr[i] >> j) & 1))
                    while (!tab[j].empty() && tab[j].back() > i)
                    {
                        dp[tab[j].back()] -= 1 << j;
                        tab[j].pop_back();
                    }
            dp[i] = arr[i];

            while (l > i && dp[l] < target)
                l--; //After this line, we have dp[l] >= target, dp[l + 1] < target, or l == i and all elements in this new sequence is smaller than target
            ans = min(ans, min(abs(target - dp[l]), abs(target - dp[l + 1])));
        }
        return ans;
    }
};
