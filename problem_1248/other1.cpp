/*
Intuition
Have you read this? 992. Subarrays with K Different Integers


Explanation
Exactly K times = at most K times - at most K - 1 times
*/

class Solution {
    int numberOfSubarrays(vector<int>& A, int k) {
        return atMost(A, k) - atMost(A, k - 1);
    }

    int atMost(vector<int>& A, int k) {
        int res = 0, i = 0, n = A.size();
        for (int j = 0; j < n; j++) {
            k -= A[j] % 2;
            while (k < 0)
                k += A[i++] % 2;
            res += j - i + 1;
        }
        return res;
    }
};
