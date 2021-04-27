class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); ++i) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end()); // ascending order

        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // min-heap

        for (long i = 0, time = 0; pq.size() || i < tasks.size(); ) {
            for ( ; i < tasks.size() && tasks[i][0] <= time; ++i) {
                pq.emplace(tasks[i][1], tasks[i][2]);
            }

            if (pq.size()) {
                auto [prc, index] = pq.top();
                pq.pop();
                ans.push_back(index);
                time += prc;
            } else {
                time = tasks[i][0];
            }
        }
        return ans;
    }
};
