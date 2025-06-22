
/*
Intuition
If n == 1, done.
If n == 2, split once, done.
Otherwise we must have a middle status,
that one array has length 2 and A[i] + A[i + 1] >= m.

Explanation
If n > 2
there is at least one pair satisfies A[i] + A[i + 1] >= m.
This is a necessry and sufficient condition to split array.
So we return if n <= 2 or any A[i] + A[i + 1] >= m.
*/

    bool canSplitArray(vector<int>& A, int m) {
        for (int i = 0; i < A.size() - 1; ++i)
            if (A[i] + A[i + 1] >= m)
                return true;
        return A.size() < 3;
    }
