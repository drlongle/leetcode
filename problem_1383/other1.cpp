/*
This problem reminded me of problem 857. Minimum Cost to Hire K Workers

We hire the team from the most efficent people to less.
The current iterated engineer has the smallest efficency in the team.
The performance of a team = efficency[i] * sumSpeed

Each time we have a new engineer,
though will reduce the efficency of the team,
it may increment the sum of speed.

If the size of team is bigger than k,
we have to layoff the smallest speed.
Then we update the result.

Note we should try better team work.
But there is the chance that less engineers
and achieve greater performance than k engineers.
If you have efficient = speed = 100,
other engineer have nothing,
you should be independent engineer and be your own boss.

We keep our engineers in order of their speed,
and we insert the new engineer inside the list as per its speed.
 */

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> ess;
        for (int i = 0; i < n; ++i)
            ess.push_back({efficiency[i], speed[i]});
        sort(begin(ess), end(ess));

        long sumS = 0, res = 0;
        priority_queue <int, vector<int>, greater<int> > pq;
        for (int i = n - 1; i >= 0; --i) {
            pq.push(ess[i].second);
            sumS += ess[i].second;
            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            res = max(res, sumS * ess[i].first);
        }
        return res % (int)(1e9+7);
    }
};
