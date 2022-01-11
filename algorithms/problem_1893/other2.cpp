// Merge intervals
// See https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    bool isCovered(vector<vector<int>>& intervals, int left, int right) {
        sort(intervals.begin(),intervals.end());    //SORT FIRST
        vector<vector<int>>v;
        v.push_back(intervals[0]);  //PUSH FIRST ELEMENT
        for(int i=1;i<intervals.size();i++) //CHECK FROM SECOND ELEMENT
        {
            if(v.back()[1]>=intervals[i][0] || v.back()[1]==intervals[i][0]-1)
                // IF END OF LAST VECTOR >= START OF
                // CURRENT VECTOR OR CAN BE MERGED, IT MEANS THEY NEED TO BE OVERLAPPED
            {
                v.back()[1]=max(v.back()[1],intervals[i][1]);   //MERGING...
            }
            else
                v.push_back(intervals[i]);   //OTHERWISE PUSH IT, IT'S AN DISTINCT                                                              INTERVAL
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i][0]<=left && v[i][1]>=right)
                return true;
        }
        return false;
    }
};
