class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {

        if (picture.size() == 0 || picture[0].size() == 0) return 0;

        // Make a map to store all ROWs with N 'B's and cateforize them based on their shape/form
        unordered_map<int, string> mp;

        for (int i = 0; i < picture.size(); i++) {

            // Representing the shape of current row
            string value = "";

            // Number of 'B's in the current row
            int count = 0;

            for (int j = 0; j < picture[i].size() && count <= N; j++) {
                value.push_back(picture[i][j]);
                if (picture[i][j] == 'B') count += 1;
            }

            // Only rows with N 'B' is qualified
            if (count == N) {
                mp[i] = value;
            }
        }

        // Final answer
        int ans = 0;

        // Find COLUMNs that all 'B' matching rows are in the same set of map
        for (int i = 0; i < picture[0].size(); i++) {

            // A array to store all locations for 'B' in the current column
            vector<int> vec;
            for (int j = 0; j < picture.size(); j++) {
                if (picture[j][i] == 'B') vec.push_back(j);
            }

            // Wipe out the cases that either current column or the first row in the vector don't have exact N 'B's
            if (vec.size() != N || !mp.count(vec[0])) continue;

            string shape = mp[vec[0]];
            for (auto v : vec) {
                if (mp.count(v) == 0 || mp[v] != shape) {
                    shape = "false";
                    break;
                }
            }

            // If all rows in the vector share the same shape, add the count of vector elements into final answer
            if (shape != "false") {
                ans += vec.size();
            }
        }

        return ans;
    }
};
