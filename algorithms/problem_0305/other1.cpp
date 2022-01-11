class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        count = 0;

        parent.resize(m*n, -1);

        vector<int> ans;

        vector<vector<int>> matrix(m, vector<int>(n));

        for(auto pos : positions) {
            int x = pos[0];
            int y = pos[1];

            if(matrix[x][y] == 0) { // avoid repeated positions

                matrix[x][y] = 1;

                // update
                count++;
                parent[x*n+y] = x*n+y;

                for(auto dir : dirs) {
                    int u = x + dir[0];
                    int v = y + dir[1];
                    if(u >= 0 && u < m && v >= 0 && v < n && matrix[u][v] == 1) {
                        unions(x*n+y, u*n+v);
                    }
                }
            }

            ans.push_back(count);
        }

        return ans;
    }

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unions(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty) {
            parent[rootx] = rooty;
            count--;
        }
    }

    int count;
    vector<int> parent;

    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
