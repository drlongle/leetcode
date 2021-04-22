class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> umap;
        int ans=wall.size();
        int max_value = 0;
        for(auto curr: wall){
            int s=0;
            for(int i=0;i<curr.size()-1;i++){
                s+=curr[i];
                max_value=max(max_value,++umap[s]);
            }
        }

        return ans-max_value;
    }
};
