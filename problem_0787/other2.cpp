class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        // define graph.
        vector <vector<pair<int, int>>> graph (n);
        
        // form graph.
        for (auto flight : flights)
            graph [flight[0]].emplace_back (flight [1], flight [2]);
        
        // cost, stop_cnt, dst.
        priority_queue <tuple<int,int,int>, vector <tuple<int,int,int>>, greater<tuple<int,int,int>>> minq;
        minq.emplace (0, -1, src);
        
        // because minq is sorted by cost first, we may visit a node with the lowest
        // cost but with a higher stop_cnt. higher stop_cnt limits furthering the search 
        // via the current node. so, if a the same node is visited again, with a higher cost
        // but with a lower stop_cnt, we benefit from a deeper search and only then
        // we may find the answer in some cases.
        vector <int> visited (n, INT_MAX);
        
        // until there are incomplete paths with <= K stops.
        while (!minq.empty ())
        {
            // next path with smallest cost.
            auto [cost, stop_cnt, stop] = minq.top ();
            minq.pop ();

            // if destination, we have reached here with the smallest cost,
            // no matter the stop_cnt.
            if (stop == dst)
                return cost;

            // if we have reached 'stop' already thru less number of intermediate
            // stops, then skip. Otherwise continue.
            if (visited [stop] <= stop_cnt)
                continue;
            visited [stop] = stop_cnt;

            // add neighbors, if they can be reached with stop_cnt <= K.
            if (stop_cnt < K)
                for (auto nbor : graph [stop])
                    minq.emplace (cost + nbor.second, stop_cnt+1, nbor.first);
        }
        
        // not found.
        return -1;
    }
};
