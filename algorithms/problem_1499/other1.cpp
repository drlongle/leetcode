/*
We can use the sliding window technique and monotonically decreasing deque d.
The maximum yi - xi therefore will be in the front. For the deque, we can just
store the index j there to make it faster.

First, remove items that got out of the xj - xi window from the front of the queue.
Then, we compute our value. Finally, we add i to the deque, making sure we keep monotonicity
(nice word, thank you Word!) of y - x. In other words, we just remove all elements
with smaller y - x from the back of the deque.
*/

class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &p, int k, int res = INT_MIN)
    {
        deque<int> d;
        for (int j = 0; j < p.size(); ++j)
        {
            while (!d.empty() && p[j][0] - p[d.front()][0] > k)
                d.pop_front();
            if (!d.empty())
                res = max(res, p[d.front()][1] - p[d.front()][0] + p[j][1] + p[j][0]);
            while (!d.empty() && p[d.back()][1] - p[d.back()][0] < p[j][1] - p[j][0])
                d.pop_back();
            d.push_back(j);
        }
        return res;
    }
};