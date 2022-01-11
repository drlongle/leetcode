// This problem is similiar to range sum. Brute force of O(n*n) time would be TLE.
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> rt(n,0);
        for( int i=0; i<bookings.size(); i++){
            rt[bookings[i][1]-1]+=bookings[i][2];// 1-indexed
            if(1<bookings[i][0])    rt[bookings[i][0]-2]-=bookings[i][2];// 1-indexed
        }
        
        for( int i=rt.size()-2; -1<i; i--)  rt[i]+=rt[i+1];
        
        return rt;
    }
};

