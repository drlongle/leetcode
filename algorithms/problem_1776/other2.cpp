class Solution {
  public:
    vector<double> getCollisionTimes(vector<vector<int>> &cars) {
        stack<int> st;
        vector<double> res(cars.size(), -1.0);

        for (int i = cars.size() - 1; i >= 0; i--) {
            double cp = cars[i][0]; // current car position
            int cs = cars[i][1];    // current car speed

            while (!st.empty()) {
                int sci = st.top();       // next car index
                double sp = cars[sci][0]; // next car postion
                int ss = cars[sci][1];    // next car speed

                if (cs <= ss) {
                    st.pop();
                    continue;
                }
                if (res[sci] == -1.0) { // cs > ss
                    break;
                }
                if ((sp - cp) / (cs - ss) >= res[sci]) {
                    st.pop();
                    continue;
                } else {
                }
                break;

                // simplified version
                // if (cs <= ss || (sp - cp)/(cs - ss) >= res[sci] && res[sci]
                // != -1.0) {
                //     st.pop();
                // } else {
                //     break;
                // }
            }
            if (!st.empty()) {
                int sci = st.top();
                double sp = cars[sci][0];
                int ss = cars[sci][1];
                res[i] = (sp - cp) / (cs - ss);
            }
            st.push(i);
        }
        return res;
    }
};
