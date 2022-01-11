class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        int maxheight=-1;
        for(int i=heights.size()-1;i>=0;i--){

            if(heights[i]>maxheight){
                ans.push_back(i);
                maxheight=heights[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
