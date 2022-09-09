class Solution {
  public:
    int numOfPairs(vector<string> &nums, string target) {
        unordered_map<string, int> umap;
        int ans = 0;
        for (auto x : nums) {
            umap[x]++;
        }
        string check1 = "", check2 = "";

        for (int i = 0; i < target.length(); i++) {
            check1 += target[i];
            check2 = target.substr(i + 1);
            if (umap.find(check1) != umap.end() &&
                umap.find(check2) != umap.end()) {
                if (check1 == check2) {
                    ans += (umap[check1] * (umap[check1] - 1));
                } else {
                    ans += umap[check1] * umap[check2];
                }
            }
        }
        return ans;
    }
};
