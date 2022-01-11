void digest(stack<int> &stk,int &ans,vector<int>& heights,int i){
    int cur_area,prev_ht=heights[stk.top()];
    stk.pop();
    cur_area=prev_ht*((stk.empty())?i:(i-stk.top()-1));
    ans=max(ans,cur_area);
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int ans=0,i;
        for(i=0;i<heights.size();){
            (stk.empty()||heights[i]>=heights[stk.top()])?stk.push(i++):digest(stk,ans,heights,i);
        }

        while(!stk.empty()){
            digest(stk,ans,heights,i);
        }
        return ans;
    }
};
