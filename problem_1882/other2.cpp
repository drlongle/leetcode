class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // {time in which the server is available at, load, index}
        priority_queue<array<long, 3>, vector<array<long, 3>>, greater<array<long, 3>>> available, busy;
        for (int i = 0; i < servers.size(); i++) {
            // All servers are currently available at time 0
            available.push({ 0, servers[i], i });
        }
        vector<int> answer;
        for (int t = 0; t < tasks.size(); t++) {
            // Move servers from busy to available if servers needs to be freed or available is empty
            while (available.empty() || busy.empty() == false && busy.top()[0] == t) {
                array<long, 3> s = busy.top();
                busy.pop();
                available.push({ (s[0] == t ? 0 : s[0]), s[1], s[2] });
            }

            // We guarantee that there is always an available server
            array<long, 3> s = available.top();
            available.pop();
            busy.push({ (s[0] == 0 ? (t + tasks[t]) : (s[0] + tasks[t])), s[1], s[2] });

            // Save answer
            answer.push_back(s[2]);
        }
        return answer;
    }
};
