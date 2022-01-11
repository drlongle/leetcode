/*
For each color find most left, right, bottom, top. These coordinate finally should form a rectangle.
Build graph with indegrees. So virtual grid for each color has dependencies on its nested other colors.
Use topological sort technique.
 */

class Solution {
public:
    struct coords
    {
        int left = INT_MAX;
        int right = INT_MIN;
        int bottom = INT_MAX;
        int top = INT_MIN;
    };

    bool isPrintable(vector<vector<int>>& grid)
    {
        vector<coords> colors(61);

        for (int row = 0; row < grid.size(); ++row)
            for (int col = 0; col < grid[row].size(); ++col)
                colors[grid[row][col]].left = min(colors[grid[row][col]].left, col),
                colors[grid[row][col]].right = max(colors[grid[row][col]].right, col),
                colors[grid[row][col]].bottom = min(colors[grid[row][col]].bottom, row),
                colors[grid[row][col]].top = max(colors[grid[row][col]].top, row);

        unordered_map<int, unordered_set<int>> indegrees, graph;

        for (int i = 0; i < colors.size(); ++i)
            for (int row = colors[i].bottom; row >= 0 && row <= colors[i].top; ++row)
                for (int col = colors[i].left; col >= 0 && col <= colors[i].right; ++col)
                    if (grid[row][col] != i)
                        indegrees[i].insert(grid[row][col]), graph[grid[row][col]].insert(i);

        queue<int> queue;

        for (int i = 0; i < colors.size(); ++i)
            if (!indegrees.count(i))
                queue.push(i);

        while (!queue.empty())
        {
            auto cur = queue.front();
            queue.pop();

            for (auto adj : graph[cur])
            {
                indegrees[adj].erase(cur);

                if (indegrees[adj].empty())
                    queue.push(adj), indegrees.erase(adj);
            }
        }

        return indegrees.empty();
    }
};