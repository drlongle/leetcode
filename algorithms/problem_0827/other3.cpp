class Solution {

    struct UnionFind {
        UnionFind(int x, int y):parent(x*y), rank(x*y,1) {
            N = x;
            M = y;
            for(int i = 0; i < x; i++) {
                for(int j = 0; j < y; j++) {
                    int idx = M * i + j;
                    parent[idx] = idx;
                }
            }
        }

        void make_union(pair<int,int> x, pair<int,int> y) {
            auto px = find(x);
            auto py = find(y);
            if(px == py)
                return;

            parent[py] = px;
            rank[px] += rank[py];
        }

        int find(pair<int,int> x) {
            int idx = M * x.first + x.second;
            while(parent[idx] != idx) {
                idx = parent[idx];
            }
            return idx;
        }

        int get_rank(pair<int,int> x) {
            int idx = M * x.first + x.second;
            return rank[idx];
        }
        int get_rank(int idx) {
            return rank[idx];
        }

        vector<int> parent;
        vector<int> rank;
        int N;
        int M;
    };

    int N;
    int M;

public:
    int largestIsland(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();

        UnionFind uf(grid.size(), grid[0].size());

        for(int j = 1; j < M; j++) {
            if(grid[0][j-1] >0 && grid[0][j] > 0 ) {
                uf.make_union( {0, j-1}, {0, j});
            }
        }

        for(int i = 1; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(grid[i-1][j] >0 && grid[i][j] > 0 ) {
                    uf.make_union( {i-1, j}, {i, j});
                }
                if(j > 0 && grid[i][j-1] >0 && grid[i][j] > 0 ) {
                    uf.make_union( {i, j-1}, {i, j});
                }
            }
        }


        int maxIsland = 0;
        int delta[] = {0,1,0,-1,0};
        int zeroFound = false;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {

                if(grid[i][j] > 0)
                    continue;

                zeroFound = true;

                map<int, int> newIsland;
                for(int d = 0; d < 4; d++) {
                    int i1 = i + delta[d];
                    int j1 = j + delta[d+1];

                    if(i1 >=0 && j1 >= 0 && i1< N && j1 < M && grid[i1][j1] > 0) {
                        auto p = uf.find({i1,j1});
                        newIsland[p] = uf.get_rank(p);
                    }
                }

                int newSize = 1;
                for(auto& a : newIsland) {
                    newSize += a.second;
                }
                maxIsland = max(maxIsland, newSize);
            }
        }

        return zeroFound ? maxIsland : N*M;
    }
};
