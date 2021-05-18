class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int res = 1;
        for (auto i = 1; i < arr.size(); ++i)
            if (arr[i] > res)
                ++res;
        return res;
    }
};
