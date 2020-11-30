class Solution {
private:
    static bool compare(vector<int> a, vector<int> b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        else if(a[2]!=b[2])
            return a[2]<b[2];
        else
        {
            if(a[2]==0)
                return a[1]>b[1];
            else
                return a[1]<b[1];
        }
    }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> dp;
        vector<vector<int>> ans;
        multiset<int, greater <int>> pq;
        pq.insert(0);
        for(int i=0;i<buildings.size();i++)
        {
            dp.push_back({buildings[i][0],buildings[i][2],0});
            dp.push_back({buildings[i][1],buildings[i][2],1});
        }
        sort(dp.begin(),dp.end(),compare);
        int i = 0;
        for(auto i: dp)
        {
            int x = i[0], height = i[1], type = i[2];
            if(type==0)
            {
                int max_val = *pq.begin();
                pq.insert(height);
                if(*pq.begin()!=max_val)
                    ans.push_back({x,height});
            }
            else if(type==1)
            {
                int max_val = *pq.begin();
                pq.erase(pq.find(height));
                if(max_val!=*pq.begin())
                    ans.push_back({x,*pq.begin()});
            }
        }

        return ans;
    }
};
