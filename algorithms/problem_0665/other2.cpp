class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        const int n = nums.size();

        int lives = 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] <= nums[i + 1]) {
                continue;
            }
            // found decreasing pair

            // corrected already, must fail
            if (lives == 0) {
                return false;
            }

            // if not middle step, definitely correctable
            if (i == 0 || i == (n - 2)) {
                lives--;
                continue;
            }
            // if middle step, apply the above conditions
            if ((nums[i - 1] <= nums[i] && nums[i] <= nums[i + 2]) ||
                (nums[i - 1] <= nums[i + 1] && nums[i + 1] <= nums[i + 2])) {
                lives--;
                continue;
            } else {
                return false;
            }
        }

        return true;
    }
};
