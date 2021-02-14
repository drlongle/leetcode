// Pretreatment + Heap + Sliding Window

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        // pretreatment
        vector<pair<int, int>> possible;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                int temp = nums[i];
                possible.push_back({temp, i});
                while (temp % 2 == 0) {
                    temp /= 2;
                    possible.push_back({temp, i});
                }
            } else {
                possible.push_back({nums[i], i});
                possible.push_back({nums[i] * 2, i});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                greater<pair<int, int>>>
        priorityQueue(greater<pair<int, int>>{}, move(possible));
        int minDeviation = INT_MAX;
        int notIncluded = n;
        int currentStart = 0;
        vector<int> needInclude(n, 1);
        vector<pair<int, int>> seen;
        // get minimum from heap
        while (!priorityQueue.empty()) {
            pair<int, int> current = priorityQueue.top();
            int currentValue = current.first;
            int currentItem = current.second;
            seen.push_back(current);
            priorityQueue.pop();
            needInclude[currentItem] -= 1;
            if (needInclude[currentItem] == 0) {
                notIncluded -= 1;
            }
            if (notIncluded == 0) {
                while (needInclude[seen[currentStart].second] < 0) {
                    needInclude[seen[currentStart].second] += 1;
                    currentStart += 1;
                }
                if (minDeviation > currentValue - seen[currentStart].first) {
                    minDeviation = currentValue - seen[currentStart].first;
                }
                needInclude[seen[currentStart].second] += 1;
                currentStart += 1;
                notIncluded += 1;
            }
        }
        return minDeviation;
    }
};