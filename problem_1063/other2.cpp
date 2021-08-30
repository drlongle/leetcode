class Solution {
public:
    int validSubarrays(vector<int>& nums) { // O(|nums|) time and O(|nums|) space
        std::vector<int> minNums;
        int validSubarraysCount = 0;
        for (const auto& num : nums) {
            while (minNums.size() && num < minNums.back()) {
                minNums.pop_back();
            }
            minNums.push_back(num);
            validSubarraysCount += minNums.size();
        }
        return validSubarraysCount;
    }
};
