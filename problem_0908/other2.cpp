class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {

        // Determine the min and max of A
        int minA = A[0];
        int maxA = A[0];
        for(int i = 1; i < A.size(); i++)
        {
            minA = min(A[i], minA);
            maxA = max(A[i], maxA);
        }

        // Calculate the "smallest range" by (max(A) - K) - (min(A) + K)
        int range = (maxA - K) -  (minA + K);

        // 0 is returned if range < 0
        return max(0, range);
    }
};
