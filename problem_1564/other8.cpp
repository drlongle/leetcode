class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        if (warehouse.empty() || boxes.empty())
            return 0;

        //calc. effective top floors
        int mini = warehouse.front();
        for (int idx = 1; idx < warehouse.size(); ++idx) {
            mini = min(mini, warehouse[idx]);
            warehouse[idx] = mini;
        }

        sort(begin(boxes), end(boxes));
        sort(begin(warehouse), end(warehouse));

        int n_boxes {0};

        for (int w_idx = 0, b_idx = 0; w_idx < warehouse.size() && b_idx < boxes.size(); ++w_idx ) {
            if  (b_idx < boxes.size() && boxes[b_idx] <= warehouse[w_idx]) {

                ++b_idx;
                ++n_boxes;
            }
        }

        return n_boxes;
    }
};
