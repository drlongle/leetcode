class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector <pair<double, pair<int, int>>> arr;
        for (int i = 0; i < quality.size(); i++)
            arr.push_back(make_pair((double)wage[i] / quality[i], make_pair(wage[i], quality[i])));
        sort(arr.begin(), arr.end());

        int sum = 0;
        priority_queue<int> q;
        for(int i=0; i<K-1; i++) {
            sum += arr[i].second.second;
            q.push(arr[i].second.second);
        }

        double ans = (sum * arr[K-1].first) + arr[K-1].second.first;
        for(int i=K; i<arr.size(); i++) {
            q.push(arr[i-1].second.second);
            sum += arr[i-1].second.second;

            int max_q = q.top();
            q.pop();
            sum -= max_q;

            double curr_ans = (sum * arr[i].first) + arr[i].second.first;
            ans = min(ans, curr_ans);
        }
        return ans;
    }
};
