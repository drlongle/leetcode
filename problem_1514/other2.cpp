/*
This is similar to Dijkstra, but instead of adding distance we multiply probabilities.

We store our travel probabilities in an adjacency list al. The maximum probability
of reaching each node is recorded in prob. Note that prob[start] == 1.

We start with start and do DFS. For each node from in the queue, we process its neighbors
and add them to the queue. Note that we add a neighbor to only if the highest probability
of reaching it (prob[to]) is less than probability of reaching to from from.
*/
class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<int, double>>> al(n);
        for (auto i = 0; i < edges.size(); ++i)
        {
            if (succProb[i] != 0)
            {
                al[edges[i][0]].push_back({edges[i][1], succProb[i]});
                al[edges[i][1]].push_back({edges[i][0], succProb[i]});
            }
        }
        vector<double> probs(n);
        probs[start] = 1;
        vector<int> q{start};
        while (!q.empty())
        {
            vector<int> q1;
            for (auto from : q)
            {
                for (auto [to, prob] : al[from])
                {
                    if (probs[to] < probs[from] * prob)
                    {
                        probs[to] = probs[from] * prob;
                        q1.push_back(to);
                    }
                }
            }
            swap(q, q1);
        }
        return probs[end];
    }
};