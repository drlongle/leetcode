/*
The idea is to store the numbers in a (unordered) set, and then walk each consecutive sequence. Every time we walk a sequence, we can remove those numbers from the set so that they are never walked again. This ensures the O(n) runtime. Finally for every walk, we track the maximum walk length (sequence length).
*/

class Solution {
public:
    int walk(unordered_set<int>& uset, int num) {
        if (uset.find(num) == uset.end()) return 0;
        uset.erase(num);
        int w = 1;
        w += walk(uset, num + 1);
        w += walk(uset, num - 1);
        return w;
    }
    
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int maxVal = 0;
        for (int num : nums) {
            if (uset.find(num) != uset.end()) maxVal = max(walk(uset, num), maxVal);
        }
        return maxVal;
    }
};

