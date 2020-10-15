class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        auto b = nums.begin(), e = nums.end();
        reverse(b, e);
        reverse(b, b+k);
        reverse(b+k, e);
    }
};
