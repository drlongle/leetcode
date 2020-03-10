/*
The answer lies in the examples.
We can use a simple DFS to reach the target node while storing the probablity of reaching that node at t by multiplying by the number of children that node has.
Once we reach that target and depth required in the problem we can return that probablity.
Edge cases:

When either the node is somewhere in the middle and we reach that node but not in target time, we simply return 0.
When it's a leaf node but the time is less than the required one, it'll simply jump until the goal time, thus we can return the same probablity.
 */

class Solution {
public:
    long double prob=0;
    int target;
    vector<vector<int>> adjList;
    vector<bool> visited;
    bool dfs(int node,int depth,long double prob)
    {
        if(depth<0) //We don't need to check for depth greater than time.
            return false;
        visited[node]=true;
        if(node==target)
        {
            if(depth==0||adjList[node].size()==(node!=1)) //depth=time or it's a leaf node.
                this->prob=prob;
            return true; //Early exit.
        }
        for(int &n:adjList[node])
            //DFS to each children with carrying the probablity to reach them. (Early exit if found)
            if(!visited[n]&&dfs(n,depth-1,prob*(long double)1/(adjList[node].size()-(node!=1))))
                return true;
        return false;                
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) 
    {
        adjList.resize(n+1);
        visited.resize(n+1,false);
        this->target=target;
        for(vector<int> &v:edges) //Create adjacency list.
            adjList[v[0]].push_back(v[1]),adjList[v[1]].push_back(v[0]);
        dfs(1,t,1);
        return prob;
    }
};
