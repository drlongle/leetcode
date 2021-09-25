class Solution {

public:

    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        map<int,int>mp;
        for(int i=0;i<ranges.size();i++){
            if(mp[ranges[i][0]]){
                mp[ranges[i][0]]=max(ranges[i][1],mp[ranges[i][0]]); // this step is for if there are duplication in the starting of the ranges then we will take that upper limit which is maximum from the initial and the current upper range
            }
            else
                mp[ranges[i][0]]=ranges[i][1];   //if the lower range does not exist then it will get stored in the map
        }
        for(int i=left;i<=right;i++){   //we will iterate from the left variable till the right variable inclusively
            bool check=false;   //checker to check whether the element exists
            for(auto it:mp){
                if(i>=it.first and i<=it.second){
                    check=true;//element exists
                    break;
                }
            }
            if(!check)
                return false;  //element does not exist
        }
        return true;  //if flow reaches here then all the elements from left to right exists
    }
};