class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes, vector<int>& boxes) {  
        bool changed = true;
        int res = 0;
        while (!boxes.empty() && changed) {
            changed = false;
            vector<int> newBoxes;
            for (auto b : boxes) {
                if (status[b]) {
                    changed = true;
                    newBoxes.insert(end(newBoxes), begin(containedBoxes[b]), end(containedBoxes[b]));
                    for (auto k : keys[b]) status[k] = 1;
                    res += candies[b];
                }
                else newBoxes.push_back(b);
            }
            swap(boxes, newBoxes);
        }
        return res;
    }
};
