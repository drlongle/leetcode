// Pretreatment + Heap + Pointers

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        // pretreatment
        vector<vector<int>> possibleList;
        for (int i = 0; i < n; i++) {
            vector<int> candidates;
            if (nums[i] % 2 == 0) {
                int temp = nums[i];
                candidates.push_back(temp);
                while (temp % 2 == 0) {
                    temp /= 2;
                    candidates.push_back(temp);
                }
            } else {
                candidates.push_back(nums[i] * 2);
                candidates.push_back(nums[i]);
            }
            // reverse candidates to sort from small to large
            reverse(candidates.begin(), candidates.end());
            possibleList.push_back(candidates);
        }
        vector<vector<int>> pointers;
        for (int i = 0; i < n; i++) {
            vector<int> initialPointer{possibleList[i][0], i, 0};
            pointers.push_back(initialPointer);
        }
        make_heap(pointers.begin(), pointers.end(), greater<vector<int>>());
        int minDeviation = INT_MAX;
        int currentEnd = 0;
        for (int i = 0; i < n; i++) {
            currentEnd = max(currentEnd, possibleList[i][0]);
        }
        // get minimum from heap
        while (!pointers.empty()) {
            vector<int> current = pointers.front();
            pop_heap(pointers.begin(), pointers.end(), greater<vector<int>>());
            pointers.pop_back();
            int currentStart = current[0];
            int index = current[1];
            int indexInCandidates = current[2];
            if (minDeviation > currentEnd - currentStart) {
                minDeviation = currentEnd - currentStart;
            }
            // if the pointer reach last
            if (indexInCandidates + 1 == possibleList[index].size()) {
                return minDeviation;
            }
            int nextValue = possibleList[index][indexInCandidates + 1];
            currentEnd = max(currentEnd, nextValue);
            vector<int> nextPointer = {nextValue, index, indexInCandidates + 1};
            pointers.push_back(nextPointer);
            push_heap(pointers.begin(), pointers.end(), greater<vector<int>>());
        }
        return minDeviation;
    }
};