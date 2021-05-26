class Solution {
public:
    int generatePatternsHelper(int curr, int m, int n, vector<bool> &visited, unordered_map<int, int> *pre) {
        if(n == 0) return 1;

        visited[curr] = true;
        int ans = 0;
        if(m <= 0) ans += 1;

        for(int i = 1; i < 10; i++) {
            if(!visited[i] && visited[pre[curr][i]]) {
                ans += generatePatternsHelper(i, m - 1, n - 1, visited, pre);
            }
        }
        visited[curr] = false;
        return ans;
    }

    int numberOfPatterns(int m, int n) {
        unordered_map<int, int> pre[10];
        pre[1] = {{9, 5}, {7, 4}, {3, 2}};
        pre[2] = {{8, 5}};
        pre[3] = {{1, 2}, {7, 5}, {9, 6}};
        pre[4] = {{6, 5}};
        pre[6] = {{4, 5}};
        pre[7] = {{9, 8}, {3, 5}, {1, 4}};
        pre[8] = {{2, 5}};
        pre[9] = {{3, 6}, {7, 8}, {1, 5}};

        vector<bool> visited(10, false);

        return generatePatternsHelper(0, m, n, visited, pre);
    }
};