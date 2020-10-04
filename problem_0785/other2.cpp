class disjoint_set
{
    vector<int> parent;
    vector<int> rank;
public:
    disjoint_set(int n)
    {
        parent=vector<int>(n);
        rank=vector<int>(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
    }
    int findset(int a)
    {
        if(parent[a]==-1)
            return a;
        return   parent[a]=findset(parent[a]);
    }

    void unite(int a,int b)
    {
        int s1=findset(a),s2=findset(b);
        if(s1 != s2)
        {
            if(rank[s1]>rank[s2]) swap(s1,s2);
            parent[s1]=s2;
            rank[s2]+=rank[s1];
        }
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        if (n== 0) return 0;
        disjoint_set ds(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                if(ds.findset(i)==ds.findset(graph[i][j]))
                    return 0;
                if(j)
                    ds.unite(graph[i][j], graph[i][j-1]);
            }
        }
        return 1;
    }
};
