class Solution {
public:
    int findElement(vector<int>& arr, int el) {
        for (int i = 0; i < arr.size(); i++) if (arr[i] == el) return i + 1;
        return -1;
    }
    vector<int> pancakeSort(vector<int>& arr) {
        // support variables
        vector<int> res;
        int curr = arr.size(), pos;
        while (true) {
            while (curr && arr[curr - 1] == curr) curr--;
            if (!curr) break;
            pos = findElement(arr, curr);
            // sending curr to the front and then back to its place
            reverse(begin(arr), begin(arr) + pos);
            res.push_back(pos);
            reverse(begin(arr), begin(arr) + curr);
            res.push_back(curr);
        }
        return res;
    }
};
