/*
Use an array heardAt[n] to store the time at which an employee heard the information. Initially all values are -1. Use this array for memoization.

heardAt[employee] = heardAt[boss] + informTime[boss]
 */
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 1){
            return 0;
        }
        vector<int> heardAt(n, -1);
        
        for(int i = 0; i < n; i++){
            if(heardAt[i] == -1){
                calculateTime(n, i, manager, informTime, heardAt);
            }
        }
        int ans = 0;
        for(int j = 0; j < n; j++){
            ans = max(ans, heardAt[j]);
        }
        return ans;
    }
    
    void calculateTime(int n, int i,vector<int>& manager,vector<int>& informTime,vector<int>& heardAt) {
        if(manager[i] != -1){
            int j = manager[i];
            if(heardAt[j] == -1){
                calculateTime(n, j, manager, informTime, heardAt);
            }
            heardAt[i] = informTime[j] + heardAt[j];
            return;
        }
        heardAt[i] = 0;
        return;
    }
};
