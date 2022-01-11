class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        map<int,vector<int>> mini;
        map<int,vector<int>> maxi;
        for(int i=0; i<arrays.size(); i++){
            mini[arrays[i][0]].push_back(i);
            maxi[arrays[i][arrays[i].size()-1]].push_back(i);
        }
        auto miniptr = mini.begin();
        auto maxiptr = maxi.rbegin();

        if(miniptr->second[0] == maxiptr->second[0]){
            auto mininext = mini.begin();
            if(mininext->second.size() == 1)mininext++;
            auto maxinext = maxi.rbegin();
            if(maxinext->second.size() == 1)maxinext++;
            return max(abs(maxinext->first - miniptr->first), abs(maxiptr->first - mininext->first));
        }
        return abs(maxiptr->first - miniptr->first);
    }
};
