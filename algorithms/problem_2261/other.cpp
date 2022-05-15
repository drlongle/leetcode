class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size(), res = 0;
        unordered_set<string> st;
        for(int i = 0; i < n; i++) {
            int count = 0;
            string s = "";
            for(int j = i; j < n; j++) {
                if(nums[j]%p == 0) count++;
                if(count > k) break;
                s += to_string(nums[j]) + "#";
                if(st.find(s) == st.end()) {
                    st.insert(s);
                    res++;
                }
            }
        }
        return res;
    }
};
