class Solution {//Straight simulation
public://Time/Space: O(N^2), O(1);
    vector<int> pancakeSort(vector<int> A) {
        vector<int> res;
        for (int x = A.size(), i; x > 0; --x) {
            for (i = 0; A[i] != x; ++i); // find index i to make A[i]=x. x is the unprocessed largest number
            reverse(A.begin(), A.begin() + i + 1); //reverse items within [0, 3); now, A.begin() points x
            res.push_back(i + 1); // 3
            reverse(A.begin(), A.begin() + x); // [0,4]. Now, A.begin() + x -1 points to x
            res.push_back(x);
        }
        return res;
    }
};
