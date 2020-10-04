class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        map<int, vector<int>> m;
        vector<int> ans(N);
        // making connections for he given graph
        for(auto a: paths)
        {
            m[a[0]].push_back(a[1]);
            m[a[1]].push_back(a[0]);    // becoz graph is undirected
        }

        // coloring procedure
        for(int i = 1; i <= N; i++)
        {
            vector<int> color(5, 0);   // 4 colors(flowers) are available

            // coloring the first children
            for(auto a: m[i])           // m[i] is the childrens of current node(garden)
            {
                color[ans[a - 1]] = 1;     // one color is used already so we subtract one
            }

            // again filling the colors in remaining childrens
            for(int j = 1; j <= 4; j++)
            {
                if(color[j] == 0)     // not used color(flower)
                {
                    ans[i - 1] = j;
                    break;
                }
            }
        }

        return ans;
    }
};
