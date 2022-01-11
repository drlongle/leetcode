// Fenwick tree

class Solution {
public:

    vector<int> BIT;

    // Standard methods for update and Query
    void upd (int ind, int N, int val) {
        while (ind <= N) {
            BIT[ind] += val;
            ind += ind & (-ind);
        }
    }

    int query(int ind) {
        int sum = 0;

        while (ind > 0) {
            sum += BIT[ind];
            ind -= ind & (-ind);
        }

        return sum;
    }

    // For calling utility function for range sum
    int getSum (int l) {
        return query(l);
    }

    vector<int> countSmaller (vector<int> arr) {

        int N = (int)arr.size();

        // Final answer will be stored here
        vector<int> itachi;

        // If our array is empty
        if (!N) return itachi;

        // IMP step:
        // To handle negative Values :-
        for (int i = 0; i < N; i++) arr[i] += 10000;

        // Forming Fenwick tree of size > max element so that elements can be directly accessed;
        int temp = *max_element(arr.begin(), arr.end());

        BIT.resize(temp + 5, 0);
        for (int i = 1; i <= temp + 1; i++) {
            BIT[i] = 0;
        }

        int ans = 0;

        for (int i = N - 1; i >= 0; i--) {
            ans = getSum(arr[i] - 1);
            upd(arr[i], temp, 1);
            itachi.push_back(ans);
        }

        reverse(itachi.begin(), itachi.end());
        return itachi;
    }
};
