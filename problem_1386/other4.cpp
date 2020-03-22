/*
if no seats taken for one row, res +=2
if some are taken, check the example graph
 */

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;
        for(vector<int>& row: reservedSeats) {
            if(!mp.count(row[0]))
                mp[row[0]] = vector<int>(10);
            mp[row[0]][row[1]-1] = 1;
        }
        
        int res = 0;

        for(auto& [r, v]: mp) {
            res += getSlots(v);
        }
        res += (n-mp.size())*2;  //row with no seats taken
        
        return res;
    }
    
    int getSlots(vector<int>& row) {
        int res = 0;
        //middle 4 seats not taken
        if(!row[3] && !row[4] && !row[5] && !row[6]) {
            if(row[1] || row[2] || row[7] || row[8]) {
                res = 1;
            } else {
                res = 2;
            }
        } else {
            if(!row[1] && !row[2] && !row[3] && !row[4]) {
                res = 1;
            }
            if(!row[5] && !row[6] && !row[7] && !row[8]) {
                res = 1;
            }
        }
        return res;
    }
};
