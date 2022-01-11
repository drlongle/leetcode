class Solution {
public:
    int maxBoxesInWarehouse(vector<int> &boxes, vector<int> &warehouse) {
        sort(boxes.begin(), boxes.end());
        int cnt = 0, i = boxes.size() - 1;
        for (int &h : warehouse) {
            while (i >= 0 && h < boxes[i]) i--;
            if (i-- < 0) return cnt;
            cnt++;
        }
        return cnt;
    }
};
