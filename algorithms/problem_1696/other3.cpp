class Solution {
public:
    int maxResult(vector < int > & nums, int k) {
        int len = nums.size();
        if (len == 1) return nums[0];
        std::map < int, int > hm;
        int arr[len];
        arr[0] = nums[0];
        hm.emplace(arr[0], 1);
        for (int i = 1; i < len; i++) {
            arr[i] = (hm.rbegin() -> first) + nums[i];
            if (hm.count(arr[i]) > 0) {
                hm.emplace(arr[i], hm[arr[i]] + 1);
            } else {
                hm.emplace(arr[i], 1);
            }

            if (i - k >= 0) {
                if (hm[arr[i - k]] == 1) {
                    hm.erase(arr[i - k]);
                } else {
                    hm[arr[i - k]] = hm[arr[i - k]] - 1;
                }
            }
        }

        return arr[len - 1];
    }
};
