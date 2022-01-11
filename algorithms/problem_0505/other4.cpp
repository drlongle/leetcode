class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // Dijkstra's algorithm
        int rows = maze.size(), cols = maze[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX)); // dist from start position to others
        vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 4 directions, up down left right
        auto comp = [&](const auto& p1, const auto& p2)
        {
            return dist[p1.first][p1.second] > dist[p2.first][p2.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(comp);
        dist[start[0]][start[1]] = 0; // start point has 0 distance
        heap.push({start[0], start[1]}); // min heap

        while (!heap.empty())
        {
            auto xy = heap.top(); // find the index of position with minimum distance to start point
            if (xy.first == destination[0] && xy.second == destination[1])
            {
                return dist[xy.first][xy.second]; // we find the minimum distance from destination to the start
            }

            for (const auto& d : dir) // there could be 4 adjacent positions in each direction
            {
                int x = xy.first, y = xy.second, count = 0;
                while (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0)
                {
                    x += d[0];
                    y += d[1];
                    ++count; // add 1 more distance for each move
                }

                x -= d[0], y -= d[1], --count;
                if (count + dist[xy.first][xy.second] < dist[x][y])
                {
                    dist[x][y] = count + dist[xy.first][xy.second]; // update the distance of adjacent position
                    heap.push({x, y});
                }
            }
            heap.pop();
        }

        return -1; // should not reach here
    }
};
