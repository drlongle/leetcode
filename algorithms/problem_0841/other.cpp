
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector <bool> visited (rooms.size(),false);
        dfs(rooms,0,visited);
        for(int i =0; i < visited.size(); i++)
            if(visited[i] == false) return false;
        return true;
    }
    void dfs(vector<vector<int>> & rm,int i,vector <bool> &visited){
        visited[i] = 1;
        for(auto &j : rm[i]) {
            if(visited[j] != 1){
                visited[j] =1;
                dfs(rm,j,visited);
            }
        }
    }
};
