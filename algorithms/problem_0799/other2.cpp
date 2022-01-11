class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        vector<double> qty;
        qty.push_back((double)poured);

        if(query_row == 0)
            return (poured >= 1) ? 1 : 0;

        for(int i = 1; i <= query_row; i++) {
            vector<double> next(i + 1);
            for(int j = 0; j < i; j++) {
                double split = (qty[j] - 1.0)/2.0;
                split = (split >= 0.0) ? split : 0.0;
                next[j] += split;
                next[j+1] += split;
            }

            if(i == query_row) {
                return min(1.0, next[query_glass]);
            }

            qty = next;
        }

        return 1.0;
    }
};
