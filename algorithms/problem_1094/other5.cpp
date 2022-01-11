class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        //Max range of the trip 
        vector<int> dp(1000, 0);
                
        //Mark all the trip with the number of passangers 
        for(auto t : trips)
        {
            dp[t[1]] += t[0];   //Passanger in
            dp[t[2]] -= t[0];   //Passanger out.
        }
        
        //Generate the range
        for(int i = 1; i < dp.size(); i++)
        {
            //Current Passanger + old passangers. 
            dp[i] += dp[i-1];
            
            //Check the range, if we are breaching the capacity limit.
            if(dp[i] > capacity)
                return false;            
        }
        
        return true;
    }
};

