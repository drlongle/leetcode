class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int count = 0;
        // build the hashmap with count of occurence of every element in array
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = map[nums[i]] + 1;
        }
        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            int complement = k - nums[i];
            if (map[current] > 0 && map[complement] > 0) {
                if ((current == complement) && map[current] < 2) continue;
                map[current] = map[current] - 1;
                map[complement] = map[complement] - 1;
                count++;
            }
        }
        return count;
    }
};