class Solution {
public:
    int r, c;
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        r=isWater.size();
        c=isWater[0].size();
        vector<vector<bool> >visited(r, vector<bool>(c,false));
        queue<pair<int, int>> q;
        for(int i=0;i<isWater.size();i++){
            for(int j=0; j<isWater[0].size();j++){
                if(isWater[i][j] == 1) {
                    isWater[i][j] = 0;
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        int i, j;
        while(!q.empty()){
            pair<int, int> top = q.front();
            q.pop();
            i=top.first;j=top.second;
            visited[i][j] = true;
            if(isSafe(i-1, j) && !visited[i-1][j]) {
                isWater[i-1][j]=isWater[i][j]+1;
                visited[i-1][j]=true;
                q.push({i-1, j});
            }
            if(isSafe(i+1, j) && !visited[i+1][j]) {
                isWater[i+1][j]=isWater[i][j]+1;
                visited[i+1][j]=true;
                q.push({i+1, j});
            }
            if(isSafe(i, j-1) && !visited[i][j-1]){
                isWater[i][j-1]=isWater[i][j]+1;
                visited[i][j-1]=true;
                q.push({i, j-1});
            }
            if(isSafe(i, j+1) && !visited[i][j+1]) {
                isWater[i][j+1]=isWater[i][j]+1;
                visited[i][j+1]=true;
                q.push({i, j+1});
            }
        }
        return isWater;
    }

    bool isSafe(int i, int j){
        return i>=0 && i<r && j>=0 && j<c;
    }
};
