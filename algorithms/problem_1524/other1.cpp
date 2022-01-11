/*
If we know the number of even and odd subarrays that end at the previous element,
we can figure out how many even and odd subarrays we have for element n:

If n is even, we increase the number of even subarrays; the number of odd subarrays does not change.
If n is odd, the number of odd subarrays is the previous number of even subarrays + 1.
The number of even subarrays is the previous number of odd subarrays.

Looking at this example:

Array: [1, 1, 2, 1]  Total
Odd:    1  1  1  3     6
Even:   0  1  2  1
*/

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int odd = 0, even = 0, sum = 0;
        for (int n : arr)
        {
            if (n % 2)
            {
                swap(odd, even);
                ++odd;
            }
            else
                ++even;
            sum = (sum + odd) % 1000000007;
        }
        return sum;
    }
};