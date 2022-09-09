class Solution {
  public:
    int numOfPairs(vector<string> &nums, string target) {
        unordered_map<string, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        int count = 0, l = target.length();
        for (int i = 0; i < l; i++) {
            string s = target.substr(0, i + 1);
            string t = target.substr(i + 1, l - i - 1);
            if (m[s] != 0 && m[t] != 0) {
                if (s == t)
                    count += m[s] * (m[t] - 1);
                else
                    count += m[s] * m[t];
            }
        }
        return count;
    }
};
