class Solution {
public:
    bool static cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]>b[1];
    }
    vector<int> closestRoom(vector<vector<int>>& rooms,vector<vector<int>>& queries)
    {
        int i=0;
        for(auto &q:queries)
            q.push_back(i++);
        vector<int>res(i,-1);
        sort(rooms.begin(),rooms.end(),cmp);
        sort(queries.begin(),queries.end(),cmp);
        i=0;
        set<int>s;
        for(auto &q:queries)
        {
            while(i<rooms.size() && q[1]<=rooms[i][1])
            {
                s.insert(rooms[i][0]);
                i++;
            }
            if(!s.empty())
            {
                auto it=s.lower_bound(q[0]);
                int p1=INT_MAX,p2=INT_MAX;
                if(it!=s.begin())
                    p1=*prev(it);
                if(it!=s.end())
                    p2=*it;
                res[q[2]]=abs(q[0]-p1)<=abs(q[0]-p2)?p1:p2;
            }
        }
        return res;
    }
};
