class Solution {
  public:
    int findRadius(vector<int> &houses, vector<int> &h) {
        int ans = 0;
        sort(houses.begin(), houses.end());
        sort(h.begin(), h.end());

        queue<int> q;
        for (auto a : h)
            q.push(a);
        int prev = q.front();
        q.pop();
        for (auto a : houses) {
            while (!q.empty() && a >= q.front()) {
                prev = q.front();
                q.pop();
            }
            int tmp = 10000000000000;
            tmp = min(abs(a - prev), tmp);
            if (!q.empty())
                tmp = min(tmp, abs(a - q.front()));
            ans = max(ans, tmp);
        }
        return ans;
    }
};
