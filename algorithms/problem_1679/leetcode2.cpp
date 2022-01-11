class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            int complement = k - current;
            if (map[complement] > 0) {
                // remove complement from the map
                map[complement] = map[complement] - 1;
                count++;
            } else {
                // add current element in the map
                map[current] = map[current] + 1;
            }
        }
        return count;
    }
};