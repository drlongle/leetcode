class Solution {
public:
    using Task = pair<int, int>;

    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<pair<int, Task>> task_vec;
        for (int idx = 0; idx < tasks.size(); ++idx) {
            task_vec.emplace_back(make_pair(tasks[idx][0], make_pair(tasks[idx][1], idx)));
        }
        sort(task_vec.begin(), task_vec.end());
        queue<pair<int, Task>> all_tasks;
        for (auto& task : task_vec) {
            all_tasks.emplace(task);
        }
        long long time = 0;
        auto comp = [](Task a, Task b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };
        priority_queue<Task, vector<Task>, decltype(comp)> queued_tasks(comp);
        vector<int> res;
        while(all_tasks.size() > 0 || queued_tasks.size() > 0) {
            if (queued_tasks.empty() && time < all_tasks.front().first) {
                time = all_tasks.front().first;
            }
            while(!all_tasks.empty() && time >= all_tasks.front().first) {
                queued_tasks.push(all_tasks.front().second);
                all_tasks.pop();
            }
            auto selected_task = queued_tasks.top();
            queued_tasks.pop();
            time += selected_task.first;
            res.push_back(selected_task.second);
        }
        return res;
    }
};
