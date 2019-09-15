/*
Synopsis:

Use a varation of Kadane's Algorithm to find the maximum subarray sum with one deletion:

Calculate the max sub-array sums in forward (left -> right) and reverse (right -> left) directions

the forward max sub-array sums for each i-th index represents the max sub-array sum ending at index i
the reverse max sub-array sums for each i-th index represents the max sub-array sum beginning at index i
While calculating the sums also keep track of the max sub-array sum with no deletions (this can be done in either the forward or reverse directions, I arbitrarily chose to perform this check in the forward direction)

Iterate once through the array and use pre-calculated sums to check if there exists a larger sum with one deletion

Runtime: O(N)
*/

class Solution {
public:
    static constexpr auto INF = static_cast<int>(1e4+1);
    using VI = vector<int>;
    int maximumSum(VI& A, int sum=0, int ans=-INF) {
        auto N = static_cast<int>(A.size());
        VI end(N), beg(N);
        end[0] = sum = ans = A[0]; // forward
        for (auto i=1; i < N; ++i) {
            end[i] = sum = max(A[i], sum + A[i]); // new sub-array or append to existing sub-array, whichever is maximal
            ans = max(ans, sum); // max sub-array sum with no deletions
        }
        beg[N-1] = sum = A[N-1]; // reverse
        for (auto i=N-2; i >= 0; --i) { 
            beg[i] = sum = max(A[i], sum + A[i]); // new sub-array or append to existing sub-array, whichever is maximal
        }
        for (auto i=1; i+1 < N; ++i) { // use pre-calculated sums to check if there exists a larger sum with one deletion
            sum = end[i-1] + beg[i+1]; // "delete" i-th value
            ans = max(ans, sum);
        }
        return ans;
    }
};
