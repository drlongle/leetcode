/*
Not claiming mine is better. Just another way to solve it. The relationship of this one v.s. the priority queue one is roughly like Bellman–Ford algorithm v.s. Dijkstra. I came up with the Naive BFS one first and ACed my solution. Then I realized this can be improved using the same methodology of Dijkstra, and then came up with the Priority Queue solution. I didn't learn other's priority queue solution before I finished my solution, but with my thoughts flow, the idea naturally reaches the priority queue solution.
*/

struct Pos
{
    int i, j;
    Pos (int i0, int j0) : i(i0), j(j0){}
};
class Solution {
public:
    int trapRainWater(vector<vector<int>> const & heightMap) {
        queue<Pos> que;
        int height = heightMap.size(), width = height > 0 ? heightMap.back().size() : 0;
        vector<vector<int>> waterMap (height, vector<int>(width, INT_MAX));
        for (int i = 0; i < height; ++ i)
        {
            waterMap[i][0] = 0, que.emplace(i, 0);
            if (width - 1 > 0)
                waterMap[i][width - 1] = 0, que.emplace(i, width - 1);
        }
        for (int j = 1; j < width - 1; ++ j)
        {
            waterMap[0][j] = 0, que.emplace(0, j);
            if (height - 1 > 0)
                waterMap[height - 1][j] = 0, que.emplace(height - 1, j);
        }
        while (que.size())
        {
            auto p = que.front(); que.pop();
            int i = p.i, j = p.j, waterLevel = max(waterMap[i][j], heightMap[i][j]);
            if (i + 1 < height && waterLevel < waterMap[i + 1][j])
                waterMap[i + 1][j] = waterLevel, que.emplace(i + 1, j);
            if (i - 1 >= 0 && waterLevel < waterMap[i - 1][j])
                waterMap[i - 1][j] = waterLevel, que.emplace(i - 1, j);
            if (j + 1 < width && waterLevel < waterMap[i][j + 1])
                waterMap[i][j + 1] = waterLevel, que.emplace(i, j + 1);
            if (j - 1 >= 0 && waterLevel < waterMap[i][j - 1])
                waterMap[i][j - 1] = waterLevel, que.emplace(i, j - 1);
        }
        int sum = 0;
        for (int i = 0; i < height; ++ i)
            for (int j = 0; j < width; ++ j)
                sum += max(heightMap[i][j], waterMap[i][j]) - heightMap[i][j];
        return sum;
    }
};

/*
With tiny modification, this naive BFS becomes the Priority Queue solution.
*/

struct Pos
{
    int i, j, val;
    Pos (int i0, int j0, int v0) : i(i0), j(j0), val(v0){}
    bool operator<(Pos const & to_less) const
    {
        return val > to_less.val; 
    }
};
class Solution {
public:
    int trapRainWater(vector<vector<int>> const & heightMap) {
        priority_queue<Pos> que;
        int height = heightMap.size(), width = height > 0 ? heightMap.back().size() : 0;
        vector<vector<bool>> visited (height, vector<bool>(width, false));
        for (int i = 0; i < height; ++ i)
        {
            visited[i][0] = true, que.emplace(i, 0, heightMap[i][0]);
            if (width - 1 > 0)
                visited[i][width - 1] = true, que.emplace(i, width - 1, heightMap[i][width - 1]);
        }
        for (int j = 1; j < width - 1; ++ j)
        {
            visited[0][j] = true, que.emplace(0, j, heightMap[0][j]);
            if (height - 1 > 0)
                visited[height - 1][j] = true, que.emplace(height - 1, j, heightMap[height - 1][j]);
        }
        int sum = 0;
        while (que.size())
        {
            auto p = que.top(); que.pop();
            int i = p.i, j = p.j, waterLevel = p.val;
            sum += p.val - heightMap[i][j];
            if (i + 1 < height && !visited[i + 1][j])
                visited[i + 1][j] = true, que.emplace(i + 1, j, max(waterLevel, heightMap[i+1][j]));
            if (i - 1 >= 0 && !visited[i - 1][j])
                visited[i - 1][j] = true, que.emplace(i - 1, j, max(waterLevel, heightMap[i-1][j]));
            if (j + 1 < width && !visited[i][j + 1])
                visited[i][j + 1] = true, que.emplace(i, j + 1, max(waterLevel, heightMap[i][j+1]));
            if (j - 1 >= 0 && !visited[i][j - 1])
                visited[i][j - 1] = true, que.emplace(i, j - 1, max(waterLevel, heightMap[i][j-1]));
        }
        return sum;
    }
};

