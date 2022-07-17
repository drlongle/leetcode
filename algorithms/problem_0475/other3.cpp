class Solution {
  public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {

        sort(heaters.begin(), heaters.end());
        int ans = INT_MIN;
        int left_closest_dist = INT_MAX;
        int right_closest_dist = INT_MAX;
        int n = heaters.size();
        for (int i = 0; i < houses.size(); i++) {
            int index = lower_bound(heaters.begin(), heaters.end(), houses[i]) -
                        heaters.begin();

            left_closest_dist =
                (index > 0) ? houses[i] - heaters[index - 1] : INT_MAX;

            right_closest_dist =
                (index < n) ? heaters[index] - houses[i] : INT_MAX;

            ans = max(ans, min(right_closest_dist, left_closest_dist));
        }
        return ans;
    }
};
