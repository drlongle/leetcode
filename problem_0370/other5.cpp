class Solution {
public:
    vector<int> initializeDiffArray(vector<int>& A)
    {
        int n = A.size();

        // We use one extra space because
        // update(l, r, x) updates D[r+1]
        vector<int> D(n + 1);

        D[0] = A[0], D[n] = 0;
        for (int i = 1; i < n; i++)
            D[i] = A[i] - A[i - 1];
        return D;
    }
    // Does range update
    void update(vector<int>& D, int l, int r, int x)
    {
        D[l] += x;
        D[r + 1] -= x;
    }

    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> A(length, 0);
        vector<int> D = initializeDiffArray(A);
        for (int i = 0; i < updates.size(); i++) {
            update(D, updates[i][0], updates[i][1], updates[i][2]);
        }
        for (int i = 0; i < A.size(); i++) {
            if (i == 0)
                A[i] = D[i];
            else
                A[i] = D[i] + A[i - 1];
        }
        return A;
    }
};
