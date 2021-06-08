class Solution {
public:
    int shortestDistance(vector<vector<int>>& m, vector<int>& start, vector<int>& destination) {
        int res = 1e5;
        queue<vector<int>> q = {};
        start.push_back(0);
        q.push(start);
        m[start[0]][start[1]] = 1e5;

        while(!q.empty()){
            vector<int> v = q.front();
            int x = v[0], y = v[1], cost = v[2];
            q.pop();

            if(x==destination[0] && y==destination[1]){
                res = min(res, cost);
                continue;
            }

            for(int i=0; i<4; ++i){
                int xx = x, yy = y;
                int tmp = 0;
                if(i==0){
                    while(xx-1 >= 0 && m[xx-1][yy] != 1) {xx--;tmp++;}
                }else if(i==1){
                    while(xx+1 < m.size() && m[xx+1][yy] != 1) {xx++;tmp++;}
                }else if(i==2){
                    while(yy-1 >= 0 && m[xx][yy-1] != 1) {yy--;tmp++;}
                }else if(i==3){
                    while(yy+1 < m[0].size() && m[xx][yy+1] != 1) {yy++;tmp++;}
                }

                if(m[xx][yy]==0 || (m[xx][yy]<0 && m[xx][yy]*(-1) > cost+tmp ) ){
                    m[xx][yy]= (cost+tmp)*(-1);
                    q.push({xx,yy,cost+tmp});
                }

            }

        }
        return res==1e5? -1:res;
    }
};
