
// Find set union

class Solution {
public:
     int find1(vector<int> &parent,int i)
    {
        if(parent[i]== -1)
            return i;
        
        return find1(parent,parent[i]);
    }
     void union1(vector<int> &parent,int i,int j)
    {
        int x1=find1(parent,i);
        int x2=find1(parent,j);
        if(x1!=x2)
        {
            parent[x1]=x2;
        }
    }
  
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        set<int>s1;
        for(int i=0;i<edges.size();i++)
        {
            if(s1.count(edges[i][0])==0)
            s1.insert(edges[i][0]);
            if(s1.count(edges[i][1])==0)
            s1.insert(edges[i][1]);
        }
        vector<int>parent(s1.size()+1,-1);
        vector<int>ans;
        ans.push_back(1);
        
        for(int i=0;i<edges.size();i++)
        {
            int x1=find1(parent,edges[i][0]);
            int x2=find1(parent,edges[i][1]);
            if(x1==x2)
            {
                ans.clear();
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
            }
            union1(parent,x1,x2);
        }
        return ans;
    }
};
