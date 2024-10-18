class Solution {
  public:
    int minGroups(vector<vector<int>> &intervals) {
        ranges::sort(intervals);

        priority_queue<int, vector<int>, greater<int>> groups;
        for (auto &i : intervals) {
            if (!groups.empty() && groups.top() < i[0]) {
                groups.pop();
            }
            groups.emplace(i[1]);
        }

        return groups.size();
    }
};
