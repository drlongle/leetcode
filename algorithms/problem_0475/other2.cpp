class Solution {
  public:
    bool ok(int mid, vector<int> &houses, vector<int> &heaters) {
        int j = 0, k = 0;
        while (k < houses.size() && j < heaters.size()) {
            if (mid >= abs(houses[k] - heaters[j])) {
                k++;
            } else {
                j++;
            }
        }
        return k == houses.size() ? true : false;
    }
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        int hi = 1e9, lo = 0, ans = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        while (hi >= lo) {
            int mid = lo + (hi - lo) / 2;
            if (ok(mid, houses, heaters)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
