// Pretreatment + Sorting + Pointers

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        // pretreatment
        vector<int> possibleList[n];
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                int temp = nums[i];
                possibleList[i].push_back(temp);
                while (temp % 2 == 0) {
                    temp /= 2;
                    possibleList[i].push_back(temp);
                }
            } else {
                possibleList[i].push_back(nums[i] * 2);
                possibleList[i].push_back(nums[i]);
            }
            // reverse candidates to sort from small to large
            reverse(possibleList[i].begin(), possibleList[i].end());
        }
        vector<vector<int>> pointers;
        for (int i = 0; i < n; i++) {
            int size = possibleList[i].size();
            for (int j = 0; j < size; j++) {
                vector<int> initialPointer{possibleList[i][j], i, j};
                pointers.emplace_back(move(initialPointer));
            }
        }
        sort(pointers.begin(), pointers.end());
        int minDeviation = INT_MAX;
        int currentEnd = 0;
        for (int i = 0; i < n; i++) {
            currentEnd = max(currentEnd, possibleList[i][0]);
        }
        int possibleListSize[n];
        for (int i = 0; i < n; i++) {
            possibleListSize[i] = possibleList[i].size();
        }
        for (auto& current : pointers) {
            int currentStart = current[0];
            int index = current[1];
            int indexInCandidates = current[2];
            if (minDeviation > currentEnd - currentStart) {
                minDeviation = currentEnd - currentStart;
            }
            // if the pointer reach last
            if (indexInCandidates + 1 == possibleListSize[index]) {
                return minDeviation;
            }
            int nextValue = possibleList[index][indexInCandidates + 1];
            currentEnd = max(currentEnd, nextValue);
        }
        return minDeviation;
    }
};