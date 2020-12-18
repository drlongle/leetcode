class Solution {
    map<int,int> mp;
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int i;
        for(i=0;i<intervals.size();i++){
            mp[intervals[i][0]]+=1;
            mp[intervals[i][1]]-=1;
        }
        int cont=0;
        int maxx=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            cont+=it->second;
            maxx=max(maxx,cont);
        }
        return maxx;
    }
};
