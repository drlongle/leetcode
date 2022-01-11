class Solution {
    map<vector<vector<int>>, int>dis;
    int a[4] = {1,-1,0,0};
    int b[4] = {0,0,1,-1};
public:
    bool check(vector<vector<int>> &v){
        for(auto y: v){
            for(auto x: y){
                if(x==1){
                    return false;
                }
            }
        }
        return true;
    }

    vector<vector<vector<int>>> neighbours(vector<vector<int>> &v, int n, int m){
        vector<vector<vector<int>>> tmp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vector<vector<int>>k = v;
                k[i][j] = (k[i][j]) ? 0 : 1;
                for(int l=0; l<4; l++){
                    int x = i+a[l];
                    int y = j+b[l];
                    if(x>=0 && x<n && y>=0 && y<m){
                        k[x][y] = (k[x][y]) ? 0 : 1;
                    }
                }
                tmp.push_back(k);
            }
        }
        return tmp;
    }
    
    int bfs(vector<vector<int>>& mat, int n, int m){
        queue<vector<vector<int>>>q;
        q.push(mat);
        dis[mat] = 0;
        while(q.size() != 0){
            auto v = q.front();
            q.pop();
            int d = dis[v];
            if(check(v)){
                return d;
            }
            auto tmp = neighbours(v, n, m);
            for(auto y: tmp){
                if(dis.find(y) == dis.end()){
                    dis[y] = d+1;
                    q.push(y);
                }
            }
        }
        return -1;
    }
    int minFlips(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        dis.clear();
        return bfs(mat, n, m);
    }
};
