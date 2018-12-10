class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z==0)return true;
        numy=y+1;
        queue<pair<int,int>> q;
        unordered_set<long long> visited;
        q.push(make_pair(0,0));
        visited.insert(to1d(0,0));
        while(!q.empty())
        {
            int cx=q.front().first,cy=q.front().second;q.pop();
            if(addNode(0,cy,q,visited,z))return true;
            if(addNode(cx,0,q,visited,z))return true;
            if(addNode(x,cy,q,visited,z))return true;
            if(addNode(cx,y,q,visited,z))return true;
            if(addNode(cx+min(cy,x-cx),cy-min(cy,x-cx),q,visited,z))return true;
            if(addNode(cx-min(cx,y-cy),cy+min(cx,y-cy),q,visited,z))return true;
        }
        return false;
    }
    
    long long numy;
    
    bool addNode(int x,int y,queue<pair<int,int>>& q,unordered_set<long long>& visited,int& z)
    {
        if(visited.find(to1d(x,y))!=visited.end())return false;
        //cout<<x<<" "<<y<<endl;
        q.push(make_pair(x,y));
        visited.insert(to1d(x,y));
        if(x==z||y==z||x+y==z)return true;
        return false;
    }
    
    long long to1d(long long x,long long y)
    {
        return x*numy+y;
    }
};

