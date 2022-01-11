class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        std::vector<std::vector<int>> graph(n, std::vector<int>(n));
        for (auto edge : flights)
        {
            graph[edge[0]][edge[1]] = edge[2];
        }
           
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> pq;
        pq.push({ 0, src, K + 1 });

        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            int price = cur[0], place = cur[1], remainStops = cur[2];

            if (place == dst)
                return price;

            if (remainStops > 0)
            {
                for (int i = 0; i < n; ++i)
                {
                    if (graph[place][i] > 0)
                        pq.push({ price + graph[place][i], i, remainStops - 1 });
                }
            }
        }
        return -1;
    }
};
