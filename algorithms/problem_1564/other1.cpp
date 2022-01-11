/*
Scan the warehouse from left to right, remember at which positions the height got smaller, they are the limiting heights.
Sort the box based on height.
Try to insert the boxes in sorted order. The height limit is the closest limiting height on the left.
Run time analysis: assume number of boxes is n and size of warehouse is m, the run time is n*log(n)+m. Worst case memory usage is m.
 */
class Solution {
public:

    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        vector<int> pos(1, 0);
        for (int i=1; i<warehouse.size(); ++i)
            if (warehouse[i] < warehouse[pos.back()])
                pos.push_back(i);

        sort(boxes.begin(), boxes.end());
        int ret = 0;
        for (int i=warehouse.size()-1; i>=0; --i) {
            if (i<pos.back())
                pos.pop_back();
            if (boxes[ret] <= warehouse[pos.back()]) {
                if (++ret == boxes.size())
                    break;
            }
        }
        return ret;
    }
};
