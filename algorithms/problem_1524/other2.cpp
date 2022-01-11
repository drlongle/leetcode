/*
Explanation
cur = 0 if current prefix sum is even
cur = 1 if current prefix sum is odd
count[0] is the number of even prefix sum
count[1] is the number of odd prefix sum

For each element in A:
if current prefix sum is even, res += the number of odd prefix sum
if current prefix sum is odd, res += the number of even prefix sum
*/
class Solution
{
public:
    int numOfSubarrays(vector<int> &A)
    {
        int cur = 0, res = 0, count[] = {1, 0}, mod = (int)1e9 + 7;
        for (int a : A)
        {
            cur ^= a & 1;
            res = (res + count[1 - cur]) % mod;
            count[cur]++;
        }
        return res;
    }
};