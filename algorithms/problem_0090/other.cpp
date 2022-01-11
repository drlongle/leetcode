class Solution {
public:
    vector<vector<int> > res;
    set<vector<int> > resSet;
    void dfs(int start,vector<int> &v,vector<int> &nums){
        if(start==nums.size()) return;
        for(int i=start;i<nums.size();i++){
            v.push_back(nums[i]);
            if(resSet.count(v)==0){
                resSet.insert(v);
                res.push_back(v);
            }
                
            dfs(i+1,v,nums);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        res.push_back(v);
        sort(nums.begin(),nums.end());
        dfs(0,v,nums);
        return res;
    }
};

