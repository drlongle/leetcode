class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> road(1020, 0);
        int c, start, end;
        for(auto trip: trips)   {
            c = trip[0], start = trip[1], end = trip[2];
            road[start] += c;
            road[end] += -c;
        }
        for(int i=1; i<1020; i++){
            road[i] += road[i-1];
            if(road[i]>capacity)
                return false;
        }
        return true;
    }
};

