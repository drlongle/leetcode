class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n,INT_MAX);
        for(int i=1;i<n;i++) l[i] = min(l[i-1],nums[i-1]);

        set<int> mp;
        mp.insert(nums[n-1]);
        for(int i=n-2;i>=1;i--){
            auto it = mp.lower_bound(nums[i]);
            if(it!=mp.begin()){
                it--;
                if(l[i] < nums[i] && l[i] < *it) return true;
            }
            mp.insert(nums[i]);
        }
        return false;
    }
};
