class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int prev = 0;
        for (int curr: arr) {
            int diff = curr - prev;
            if (diff > k)
                return prev + k;
            else
                k -= diff - 1;
            prev = curr;
        }
        return prev + k;
    }
};
