class Solution {
  public:
    int maxLength(vector<int> &ribbons, int k) {
        sort(ribbons.begin(), ribbons.end());
        int lo = 1, hi = *max_element(ribbons.begin(), ribbons.end()),
            index = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int current_count = 0;
            for (int i = 0; i < ribbons.size(); i++) {
                current_count += ribbons[i] / mid;
            }
            if (current_count >= k) {
                lo = mid + 1;
                index = mid;
            } else {
                hi = mid - 1;
            }
        }
        return index;
    }
};
