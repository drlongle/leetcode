class Solution {
public:
    string originalDigits(string s) {
        string res = "";
        vector<int> m(123, 0);
        vector<int> nums(10, 0);
        for (char c : s)
            m[c]++;
        nums[0] = m['z'];
        nums[2] = m['w'];
        nums[4] = m['u'];
        nums[6] = m['x'];
        nums[8] = m['g'];
        nums[1] = m['o'] - nums[0] - nums[2] - nums[4];
        nums[3] = m['t'] - nums[2] - nums[8];
        nums[7] = m['s'] - nums[6];
        nums[5] = m['v'] - nums[7];
        nums[9] = m['i'] - nums[5] - nums[6] - nums[8];
        for (int i = 0; i < 10; i++) {
            if (nums[i] > 0) {
                while(nums[i]--)
                    res += ('0' + i);
            }
        }
        return res;
    }
};


