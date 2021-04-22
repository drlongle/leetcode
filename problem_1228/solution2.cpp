class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size(), diff;
        if (arr[1]-arr[0] < 0)
            diff = max(arr[1]-arr[0], arr[n-1]-arr[n-2]);
        else
            diff = min(arr[1]-arr[0], arr[n-1]-arr[n-2]);
        for (int i = 1, curr = arr[0]; i < n; ++i) {
            curr += diff;
            if (arr[i] != curr)
                return curr;
        }
        return arr[0];
    }
};