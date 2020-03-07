// Find union

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>vertexs={0};
        vector<int>res;
        set<int>hash;
        for(vector<int>&v:edges){
            int v1=v[0];
            int v2=v[1];
            if(hash.find(v1)==hash.end()){
                vertexs.push_back(v1);
                hash.insert(v1);
            }
            if(hash.find(v2)==hash.end()){
                vertexs.push_back(v2);
                hash.insert(v2);
            } 
        }
        sort(vertexs.begin(),vertexs.end());
        for(vector<int>&v:edges){
            int v1=v[0];
            int v2=v[1];
            int root1=find(vertexs,v1);
            int root2=find(vertexs,v2);
            if(root1==root2){
                res.push_back(v1);res.push_back(v2);
                break;
            }
            //union
            vertexs[root1]=root2;
        }
        return res;
    }
    int find(vector<int>&nums,int x){
        if(nums[x]==x)return x;
        int root=find(nums,nums[x]);
        nums[x]=root;
        return root;
    }
};
