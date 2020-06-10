class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size(), k = 0;
        //if nums are not continuous, check each section
        //for example, 1,2,3, 6,7,8;
        for (int i = 1; i < n; i++) {
            if (nums[i]-nums[i-1] > 1) {
                if (!check(nums, k, i-1)) 
                    return false;
                k = i;
            }
        }
        return check(nums, k, n-1);
    }
private:
    bool check(vector<int>& nums, int s, int e) {
        int n = nums[e]-nums[s]+1;
        // count frequency of each number
        vector<int> mp(n, 0);
        for (int i = s, tmp = nums[s]; i <= e; i++)
            mp[nums[i]-tmp]++;
        // ones is subsequences with length 1 ending with index i-1
        // twos is subsequences with length 2 ending with index i-1
        // tot  is all subsequences ending with index i-1
        // initially ones[0] ending with index -1, i.e. nonexistent 
        vector<int> ones(n+1, 0), twos(n+1, 0), tot(n+1, 0);
        for (int i = 0; i < n; i++) {
            // we need at least ones+twos new number to make consecutive sequence
            // for examle, two 2, five 1,2, we need at least seven 3
            if (mp[i] < ones[i] + twos[i]) return false;
            // Greedy, appending to short sequences first
            // so twos = ones, and new ones is the extra new number
            twos[i+1] = ones[i];
            ones[i+1] = max(0, mp[i]-tot[i]);
            tot[i+1] = mp[i];
        }
        // if no subsequence length <= 2, return true
        return ones[n] == 0 && twos[n] == 0;
    }
};
