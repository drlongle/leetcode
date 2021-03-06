class Solution {
public:
    double trimMean(vector<int>& arr) {
        auto sz = arr.size(), skip = sz / 20;
        nth_element(begin(arr), begin(arr) + skip, end(arr));
        nth_element(begin(arr) + skip, begin(arr) + sz - skip, end(arr));
        return (double)accumulate(begin(arr) + skip, begin(arr) + sz - skip, 0) / (sz - skip * 2);
    }
};