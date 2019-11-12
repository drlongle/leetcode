/*
 * Synopsis
Preprocess the input array A by counting the even numbers to the Left and to the Right of each index i.
The count of even numbers is reset to 0 whenever an odd number is encountered. Use a queue to store
each odd number's index in A.
*/

class Solution {
public:
    using VI = vector<int>;
    int numberOfSubarrays(VI& A, int k, deque<int> odd={}, int ans=0) {
        auto isOdd = [](auto x) -> bool { return x % 2; };
        int N = A.size();
        auto L = VI(N),
             R = VI(N);
        for (auto i=1;    i < N; ++i) L[i] = !isOdd(A[i-1]) ? L[i-1] + 1 : 0;
        for (auto j=N-2; -1 < j; --j) R[j] = !isOdd(A[j+1]) ? R[j+1] + 1 : 0;
        for (auto i=0; i < N; ++i)
            if (isOdd(A[i]))
                odd.push_back(i);
        for (; odd.size() >= k; odd.pop_front()) {
            auto i = odd[0],
                 j = odd[k - 1];
            ans += (L[i] + 1) * (R[j] + 1);
        }
        return ans;
    }
};
