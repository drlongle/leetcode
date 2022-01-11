class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, vector<int>> students;
        for (int i = 0; i < items.size(); ++i) {
            int id = items[i][0], score = items[i][1];
            students[id].push_back(score);
        }
        vector<vector<int>> result;
        for (auto& [id, scores] : students) {
            nth_element(scores.begin(), scores.begin() + 5, scores.end(), greater<int>());
            int sum = 0;
            for (int i = 0; i < 5; ++i) {
                sum += scores[i];
            }
            result.push_back({id, sum / 5});
        }
        sort(result.begin(), result.end());
        return result;
    }
};
